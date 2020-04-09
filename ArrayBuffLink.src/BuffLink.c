#include <stdio.h>
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

	int linkSize = self->tail - self->head + 1;
	if(linkSize < 0) {
		linkSize = LINK_LENTH + linkSize;
	}

	if((linkSize < 0) || (linkSize > LINK_LENTH)) {
		return -1;
	}
//	printf("BuffLink_getSize()=%d \n", linkSize);
	return linkSize;
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
	if((selfSize <= 0) || (selfSize > LINK_LENTH)) {
//		printf("over 1 %d %d \n", self->head, self->tail);
		return NULL;
	}

	self->head++;
	self->head = self->head % LINK_LENTH;

	return self->buffPool[self->head];
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 添加节点
 ******************************************************************************/
UINT8 *BuffLink_getNewNode(BuffLink *self) {
	if(NULL == self) {
		return NULL;
	}

	int selfSize = BuffLink_getSize(self);
	// 溢出
	if((selfSize < 0) || (selfSize >= LINK_LENTH)) {
//		printf("over 2 %d %d \n", self->head, self->tail);
		return NULL;
	}

	self->tail++;
	self->tail = self->tail % LINK_LENTH;

	return self->buffPool[self->tail];
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * 初始化
 ******************************************************************************/
void BuffLink_init(BuffLink *self) {
	if(NULL == self) {
		return;
	}

	self->head = 0;
	self->tail = -1;
	self->nodeLen = NODE_LENTH;
	self->linkLen = LINK_LENTH;
}