//
// $ gcc DataPicker.c testDataPicker.c -o testDataPicker
//
#include <stdio.h>
#include "DataPicker.h"

void main() {
	DataPicker dp;
	DataPicker_init(&dp);
	DataPicker_setSample(&dp, 100, 30);

	for(int i = 0; i < 50; i++) {
		if(DataPicker_append(&dp, i)) {
			printf("%d \n", DataPicker_getResultVal(&dp));
		}
	}

	for(int i = 50; i > 0; i--) {
		if(DataPicker_append(&dp, i)) {
			printf("%d \n", DataPicker_getResultVal(&dp));
		}
	}
}
