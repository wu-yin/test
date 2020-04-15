/******************************************************************************
 * 2020.04.08 Wu Yin
 * ��������һ�������������ʵ�ֵ�һ�����λ�������
 * Ŀǰֻ���������淢�������Ĳ����������ݡ�
 * �������ݵ��������Ƚϴ��������˿ڷ�����������
 * ��������������������档
 * Ŀǰֻ������5�����νڵ�����ݣ��Ƿ��ã�����̫���ˣ�����֪������Ҫʵ��
 *
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
// ���100��һ���������ݽڵ�ĳ���
// ���ֵҪ�� "Ksm5.h" �е� ECG_WAVE_BUFF_LEN ���
#define NODE_LENTH 100

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

