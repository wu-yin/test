/******************************************************************************
 * 2020.04.08 Wu Yin
 *
 * 当 size>0 时：
 * tail 指向的是链表中最*新*的那个数据
 * head 指向的是链表中最*老*的那个数据
 *
 * size的算法：
 * size = tail - head + 1
 * 如果 size < 0,
 * size = size + LINK_LENTH
 *
 * 添加节点时：tail++
 * 删除节点时：head++
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
 * 从尾部添加，从头部读取并删除
 */
typedef struct {
	UINT8 buffPool[LINK_LENTH][NODE_LENTH];
	int head;      // 指向当前链表中最*老*的那个数据
	int tail;      // 指向当前链表中最*新*的那个数据
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

