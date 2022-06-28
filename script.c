#include "script.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

bool mio(int MAT[8][8], int x, int y,int pezzo) {
	bool check = false;
	if (MAT[x][y] != 999) {
		if (MAT[x][y] > 200 && pezzo > 200 || MAT[x][y] < 200 && pezzo < 200)  check = true;
	}
	return check;
}
int return_column(char column[]) {
	int value = 0;

	switch(column[0]) {
	case 'a':
	case 'A' : value = 0;
		break;
	case 'b':
	case 'B' : value = 1;
		break;
	case 'c':
	case 'C' : value = 2;
		break;
	case 'd':
	case 'D' : value = 3;
		break;
	case 'e':
	case 'E' : value = 4;
		break;
	case 'f':
	case 'F' : value = 5;
		break;
	case 'g':
	case 'G' : value = 6;
		break;
	case 'h':
	case 'H' : value = 7;
		break;
	default: printf("error!\n");
		break;

	}

	return value;
}
