/******************************************************************************
 * 2020.04.08 Wu Yin
 * 本对象是一个极简的用数组实现的一个环形缓冲区。
 * 目前只是用来缓存发给蓝牙的参数波形数据。
 * 波形数据的数据量比较大，怕蓝牙端口发送来不及，
 * 现用这个缓冲区做个缓存。
 * 目前只缓存了5个波形节点的数据，是否够用，还是太多了，都不知道，需要实测
 *
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


#define BUFFLINK_LENTH 5
// 这个100是一个波形数据节点的长度
// 这个值要与 "Ksm5.h" 中的 ECG_WAVE_BUFF_LEN 相等
#define WAVE_NODE_LENTH 100

/*
 * 从尾部添加，从头部读取并删除
 *   0   1   2   3   4
 *  --- --- --- --- ---
 * | * | * | * |   |   |   size=3
 *  --- --- --- --- ---
 *   ^       ^tail:最新插入的一个值
 *   ^head:最先插入的一个值，会pop出的那个值
 */
typedef struct {
	UINT8 buffPool[BUFFLINK_LENTH][WAVE_NODE_LENTH]; // 静态分配内存池
	int head;      // 指向当前链表中最*老*的那个数据
	int tail;      // 指向当前链表中最*新*的那个数据
	int size;
	char name[10]; // For Debug
} BuffLink;

int BuffLink_getSize(BuffLink *self);
UINT8 *BuffLink_popNode(BuffLink *self);
UINT8 *BuffLink_getNewNode(BuffLink *self);
void BuffLink_init(BuffLink *self, char *name);

BOOL BuffLink_isFull(BuffLink *self);
BOOL BuffLink_isEmpty(BuffLink *self);

// For Debug
int BuffLink_getHead(BuffLink *self);
int BuffLink_getTail(BuffLink *self);
char *BuffLink_getName(BuffLink *self);

#endif

