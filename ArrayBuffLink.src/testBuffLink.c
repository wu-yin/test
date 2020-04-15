#include <stdio.h>
#include "BuffLink.h"

void main() {
	BuffLink bl;

	BuffLink_init(&bl);
	UINT8 *buff = BuffLink_getNewNode(&bl);
	for(int i = 0; i < 100; i++) {
		buff[i] = 1;
	}

	buff = BuffLink_getNewNode(&bl);
	for(int i = 0; i < 100; i++) {
		buff[i] = 2;
	}

	buff = BuffLink_getNewNode(&bl);
	for(int i = 0; i < 100; i++) {
		buff[i] = 3;
	}

	buff = BuffLink_getNewNode(&bl);
	for(int i = 0; i < 100; i++) {
		buff[i] = 4;
	}

	buff = BuffLink_getNewNode(&bl);
	for(int i = 0; i < 100; i++) {
		buff[i] = 5;
	}

	// ------------
	buff = BuffLink_popNode(&bl);
	for(int i = 0; i < 20; i++) {
		printf("%d ", buff[i]);
	}
	printf("\n");

	buff = BuffLink_popNode(&bl);
	for(int i = 0; i < 20; i++) {
		printf("%d ", buff[i]);
	}
	printf("\n");

	buff = BuffLink_popNode(&bl);
	for(int i = 0; i < 20; i++) {
		printf("%d ", buff[i]);
	}
	printf("\n");

	return;
}
