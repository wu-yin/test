//
// $ gcc DataPicker.c testDataPicker.c -o testDataPicker
//
#include <stdio.h>
#include "DataPicker.h"


void testOneInstance() {
	DataPicker dp;
	DataPicker_init(&dp);
	DataPicker_setSample(&dp, 10, 3); // 输入输出只要一个比例就行，不一定是真实速率

	for(int i = 0; i < 50; i++) {
		if(DataPicker_append(&dp, i)) {
			printf("in=%d out=%d \n", i, DataPicker_getResultVal(&dp));
		}
	}

	for(int i = 50; i > 0; i--) {
		if(DataPicker_append(&dp, i)) {
			printf("in=%d out=%d \n", DataPicker_getResultVal(&dp));
		}
	}
}

void testMultInstance() {
	DataPicker dp_10to3, dp_10to5;
	UINT8 buff30[55] = {0};
	UINT8 buff50[55] = {0};

	DataPicker_init(&dp_10to3);
	DataPicker_setSample(&dp_10to3, 100, 30);

	DataPicker_init(&dp_10to5);
	DataPicker_setSample(&dp_10to5, 100, 50);

	static int indexBuff30 = 0;
	static int indexBuff50 = 0;

	for(int i = 0; i < 50; i++) {
		if(DataPicker_append(&dp_10to3, i)) {
			buff30[indexBuff30] = DataPicker_getResultVal(&dp_10to3);
			indexBuff30++;
		}

		if(DataPicker_append(&dp_10to5, i)) {
			buff50[indexBuff50] = DataPicker_getResultVal(&dp_10to5);
			indexBuff50++;
		}
	}

	for(int i = 50; i > 0; i--) {
		if(DataPicker_append(&dp_10to3, i)) {
			buff30[indexBuff30] = DataPicker_getResultVal(&dp_10to3);
			indexBuff30++;
		}

		if(DataPicker_append(&dp_10to5, i)) {
			buff50[indexBuff50] = DataPicker_getResultVal(&dp_10to5);
			indexBuff50++;
		}
	}

	printf("%s \t %s \t %s \n", "No.", "100-30", "100-50");
	for(int i = 0; i < 55; i++) {
		printf("%d \t %d \t %d \n", i, buff30[i], buff50[i]);
	}
}

void main() {
	printf("\n------- testOneInstance() --------- \n");
	testOneInstance();

	printf("\n------- testMultInstance() --------- \n");
	testMultInstance();
}
