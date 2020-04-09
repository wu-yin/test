#include <stdio.h>
#include <math.h>
#include "DataPicker.h"

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 如果DataPicker_append()返回值是TURE，则马上从这里取出最新的结果值
 * 返回值：
 * 目前最新的一个结果值
 ******************************************************************************/
UINT8 DataPicker_getResultVal(DataPicker *self) {
	if(NULL == self) {
		return FALSE;
	}

	return self->resultVal;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 给算法喂数据。
 ******************************************************************************/
BOOL DataPicker_append(DataPicker *self, UINT8 value) {
	if(NULL == self) {
		return FALSE;
	}

	if(self->sample <= 1) {
		self->sample = 1;
		return FALSE;
	}

	if(self->isFirstData == TRUE) {
		self->isFirstData = FALSE;
		self->resultVal = value;
		self->old = value;
		self->realCount++;
		return TRUE;
	}

	int result_value;
	int status_cur = (value - self->old > 0);

	// 若_old是峰值，调整_highest。
	// self->status == 1表示上升趋势。
	if(self->status == 1 && status_cur == 0) {
		self->highest = (self->old > self->highest) ? self->old : self->highest;
	}

	// 若_old是谷值，调整_lowest
	if(self->status == 0 && status_cur == 1) {
		self->lowest = (self->old > self->lowest) ? self->lowest : self->old;
	}

	// 如果原始采样率大于输出采样率，则抽取
	float ds;
	if(self->contractSample <= 0) {
		return FALSE;
	}

	//该值决定此点是保留还是抽掉
	ds = self->contractIndex + self->contractRemain - self->contractSample;

	// 满足这个条件，则把此点抽掉，否则保留下来，
	// 并把_highest和_lowest恢复初始值。
	if(ds >= 0) {
		self->contractIndex = 1;
		self->contractRemain = ds;

		if(self->errorCount != 0) {
			if(self->errorCount > 25) {
				self->errorCount = 25;
			}
			else if(self->errorCount < -25) {
				self->errorCount = -25;
			}

			self->contractRemain += self->errorCount * self->contractSample;
			self->realCount += self->errorCount;
			self->errorCount = 0;
		}

		self->status = status_cur;
		self->old = value;
		return FALSE;
	}
	self->contractIndex += 1;

	// 保留尖峰
	// 在前面抽取的点中有峰值，但没有谷值，则把最大的峰值保留下来。
	if((self->highest != 0) && (self->lowest == 1000)) {
		result_value = self->highest;
	}
	// 在前面抽取的点中有谷值，但没有峰值，则把最小的谷值保留下来。
	else if((self->highest == 0) && (self->lowest != 1000)) {
		result_value = self->lowest;
	}
	// 在前面抽取的点中有峰值也有谷值，比较最大的峰值和最小的谷值距离127的
	// 远近，远者保留下来。
	else if((self->highest != 0) && (self->lowest != 1000)) {
		if(fabs(self->highest - 127) > fabs(self->lowest - 127)) {
			result_value = self->highest;
		}
		else {
			result_value = self->lowest;
		}
	}
	// 在前面抽取的点中没有峰值也没有谷值，
	// 就是说采样点的值一直递增或递减，可以直接抽取掉。
	else {
		result_value = value;
	}

	self->resultVal = result_value;
	self->realCount++;

	self->highest = 0;
	self->lowest = 1000;

	if(self->errorCount != 0) {
		if(self->errorCount > 25) {
			self->errorCount = 25;
		}
		else if(self->errorCount < -25) {
			self->errorCount = -25;
		}

		self->contractRemain += self->errorCount * self->contractSample;
		self->realCount += self->errorCount;
		self->errorCount = 0;
	}

	self->status = status_cur;
	self->old = value;

	return TRUE;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 设置采样率。
 * 目前本算法只支持抽值，也就是说输出量要小于输入量。
 * 参数：
 * rate：输入数据率
 * pspeed：输出数据率
 ******************************************************************************/
void DataPicker_setSample(DataPicker *self, float rate, float pspeed) {
	if(NULL == self) {
		return;
	}

	// TODO :
	// 只支持抽值，不支持插值
	if((rate == 0) || (pspeed == 0)) {
		printf("the rate or pspeed is 0!\n");
		return;
	}

	self->sample = rate / pspeed;
	if(self->sample <= 1) {
		self->sample = 1;
		return;
	}

	//表示要进行压缩，抽取点。
	self->contractSample = rate / (rate - pspeed);

	if(self->pspeed != pspeed) {
		self->realCount = 0;
	}

	self->pspeed = pspeed;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 初始化数据
 ******************************************************************************/
void DataPicker_init(DataPicker *self) {
	if(NULL == self) {
		return;
	}

	self->old = 127;
	self->highest = 0;
	self->lowest = 1000;
	self->status = 0;
	self->errorCount = 0;
	self->realCount = 0;

	self->contractIndex = 1;
	self->contractRemain = 0;

	self->isFirstData = TRUE;

	self->contractSample = -1;
	self->sample = 1;
	self->pspeed = 0.0;
	self->resultVal = 0;

}