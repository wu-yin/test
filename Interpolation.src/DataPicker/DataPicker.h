#ifndef DATA_PICKER_H
#define DATA_PICKER_H

#define FALSE 0
#define TRUE  1
typedef unsigned char BOOL;
typedef unsigned char UINT8;

typedef struct {
	BOOL isFirstData;
	int old;                 // 上一个数据的值。
	int errorCount;          // 误差累计。
	unsigned short highest;  // 跟踪最大值。
	unsigned short lowest;   // 跟踪最小值。

	// 这些值不太清楚
	float sample;
	float contractIndex;
	float contractRemain;
	float contractSample;
	float pspeed;

	UINT8 status;
	long realCount;   // 插值器实际记录处理的数据个数。
	UINT8 resultVal;  // 保存通过插值计算后的数据。
} DataPicker;



// 设置采样率
void DataPicker_setSample(DataPicker *self, float rate, float pspeed);
// 给算法喂数据
BOOL DataPicker_append(DataPicker *self, UINT8 value);
// 取出运算结果，抽出的数据
UINT8 DataPicker_getResultVal(DataPicker *self);
// 初始化
void DataPicker_init(DataPicker *self);

#endif
