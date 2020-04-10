/******************************************************************************
 * 2020.04.08 Wu Yin
 *
 * �� size>0 ʱ��
 * tail ָ�������������*��*���Ǹ�����
 * head ָ�������������*��*���Ǹ�����
 *
 * size���㷨��
 * size = tail - head + 1
 * ��� size < 0,
 * size = size + LINK_LENTH
 *
 * ��ӽڵ�ʱ��tail++
 * ɾ���ڵ�ʱ��head++
 ******************************************************************************/
#ifndef BUFF_LINK_H
#define BUFF_LINK_H


#define FALSE 0
#define TRUE  1
typedef unsigned int BOOL;
typedef unsigned char UINT8;


#define LINK_LENTH 5
#define NODE_LENTH 106

/*
 * ��β����ӣ���ͷ����ȡ��ɾ��
 */
typedef struct {
	UINT8 buffPool[LINK_LENTH][NODE_LENTH];
	int head;      // ָ��ǰ��������*��*���Ǹ�����
	int tail;      // ָ��ǰ��������*��*���Ǹ�����
	int size;
} BuffLink;

int BuffLink_getSize(BuffLink *self);
UINT8 *BuffLink_popNode(BuffLink *self);
UINT8 *BuffLink_getNewNode(BuffLink *self);
void BuffLink_init(BuffLink *self);

// For test
int BuffLink_getHead(BuffLink *self);
int BuffLink_getTail(BuffLink *self);

#endif

