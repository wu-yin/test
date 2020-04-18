#include <stdio.h>
#include <string.h>
#include "BuffLink.h"

/******************************************************************************
 * 2020.04.08 Wu Yin
 ******************************************************************************/
int BuffLink_getHead(BuffLink *self) {
	if(NULL == self) {
		return -1;
	}

	return self->head;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 ******************************************************************************/
int BuffLink_getTail(BuffLink *self) {
	if(NULL == self) {
		return -1;
	}

	return self->tail;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 获取有效数据个数
 * 返回值：
 * -1：错误
 ******************************************************************************/
int BuffLink_getSize(BuffLink *self) {
	if(NULL == self) {
		return -1;
	}

	if(self->size < 0 || self->size > BUFFLINK_LENTH) {
		self->size = 0;
		return -1;
	}

	return self->size;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 弹出一个节点
 ******************************************************************************/
UINT8 *BuffLink_popNode(BuffLink *self) {
	if(NULL == self) {
		return NULL;
	}

	int selfSize = BuffLink_getSize(self);
	if((selfSize <= 0) || (selfSize > BUFFLINK_LENTH)) {
//		printf("over 1 %d %d \n", self->head, self->tail);
		return NULL;
	}

	UINT8 *retBuff;
	retBuff = self->buffPool[self->head];
	self->head++;
	self->head = self->head % BUFFLINK_LENTH;
	self->size--;

	return retBuff;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 添加节点。
 * 如果满了，则不会再添加，不会删除旧的增加新的，而是根本添加不进去了。
 ******************************************************************************/
UINT8 *BuffLink_getNewNode(BuffLink *self) {
	if(NULL == self) {
		return NULL;
	}

	int selfSize = BuffLink_getSize(self);
	// 溢出
	if((selfSize < 0) || (selfSize >= BUFFLINK_LENTH)) {
//		printf("over 2 %d %d \n", self->head, self->tail);
		return NULL;
	}

	self->tail++;
	self->tail = self->tail % BUFFLINK_LENTH;
	self->size++;

	return self->buffPool[self->tail];
}

/******************************************************************************
 * 2020.04.15 Wu Yin
 *
 ******************************************************************************/
BOOL BuffLink_isFull(BuffLink *self) {
	if(BUFFLINK_LENTH == self->size) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/******************************************************************************
 * 2020.04.15 Wu Yin
 *
 ******************************************************************************/
BOOL BuffLink_isEmpty(BuffLink *self) {
	if(0 == self->size) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/******************************************************************************
 * 2020.04.15 Wu Yin
 * For Debug
 ******************************************************************************/
char *BuffLink_getName(BuffLink *self) {
	return self->name;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 初始化
 ******************************************************************************/
void BuffLink_init(BuffLink *self, char *name) {
	if(NULL == self) {
		return;
	}

	self->head = 0;
	self->tail = -1;
	self->size = 0;
	strcpy(self->name, name);
}

