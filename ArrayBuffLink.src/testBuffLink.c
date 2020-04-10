#include <stdio.h>
#include "BuffLink.h"

void main() {
	BuffLink bl;

	// 超过长度，会溢出3次
	printf("\n----- test: overflow ------\n");
	BuffLink_init(&bl);
	for(int i = 0; i < 8; i++) {
		if(NULL == BuffLink_getNewNode(&bl)) {
			printf("overflow \n");
		}
	}

	printf("\n----- test: empty pop error ------\n");
	BuffLink_init(&bl);
	if(NULL == BuffLink_popNode(&bl)) {
		printf("ops, the link is empty! %d \n", BuffLink_getSize(&bl));
	}

	printf("\n----- test: add and pop ------\n");
	printf("[add 3 times, pop 1 times]\n");
	BuffLink_init(&bl);
	for(int i = 0; i < 3; i++) {
		BuffLink_getNewNode(&bl);
	}
	BuffLink_popNode(&bl);
	printf("[len=2; head=1; tail=2] %d %d %d\n",
			BuffLink_getSize(&bl),
			BuffLink_getHead(&bl),
			BuffLink_getTail(&bl));

	printf("\n[add 4 times, pop 2 times, add 2 times]\n");
	BuffLink_init(&bl);
	for(int i = 0; i < 4; i++) {
		BuffLink_getNewNode(&bl);
	}
	BuffLink_popNode(&bl);
	BuffLink_popNode(&bl);
	for(int i = 0; i < 2; i++) {
		BuffLink_getNewNode(&bl);
	}
	printf("[len=4; head=2; tail=0] %d %d %d\n",
			BuffLink_getSize(&bl),
			BuffLink_getHead(&bl),
			BuffLink_getTail(&bl));

	printf("\n----- test: add and pop 2 ------\n");
	BuffLink_init(&bl);
	printf("tail=%d head=%d len=%d \n",
				BuffLink_getTail(&bl),
				BuffLink_getHead(&bl),
				BuffLink_getSize(&bl));
	for(int i = 0; i < 15; i++) {
		BuffLink_getNewNode(&bl);
		BuffLink_popNode(&bl);
		printf("tail=%d head=%d len=%d \n",
				BuffLink_getTail(&bl),
				BuffLink_getHead(&bl),
				BuffLink_getSize(&bl));
	}

	return;
}
