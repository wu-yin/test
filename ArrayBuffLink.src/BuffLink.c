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
 * ��ȡ��Ч���ݸ���
 * ����ֵ��
 * -1������
 ******************************************************************************/
int BuffLink_getSize(BuffLink *self) {
	if(NULL == self) {
		return -1;
	}

	if(self->size < 0 || self->size > LINK_LENTH) {
		self->size = 0;
		return -1;
	}

	return self->size;
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * ����һ���ڵ�
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
	self->size--;

	return self->buffPool[self->head];
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * ��ӽڵ�
 ******************************************************************************/
UINT8 *BuffLink_getNewNode(BuffLink *self) {
	if(NULL == self) {
		return NULL;
	}

	int selfSize = BuffLink_getSize(self);
	// ���
	if((selfSize < 0) || (selfSize >= LINK_LENTH)) {
//		printf("over 2 %d %d \n", self->head, self->tail);
		return NULL;
	}

	self->tail++;
	self->tail = self->tail % LINK_LENTH;
	self->size++;

	return self->buffPool[self->tail];
}

/******************************************************************************
 * 2020.04.08 Wu Yin
 * ��ʼ��
 ******************************************************************************/
void BuffLink_init(BuffLink *self) {
	if(NULL == self) {
		return;
	}

	self->head = 0;
	self->tail = -1;
	self->size = 0;
}

