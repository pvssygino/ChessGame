#include "script.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>


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
	/*if (column[0] == 'A') value = 0;
	else if (column[0] == 'B') value = 1;
	else if (column[0] == 'C') value = 2;
	else if (column[0] == 'D') value = 3;
	else if (column[0] == 'E') value = 4;
	else if (column[0] == 'F') value = 5;
	else if (column[0] == 'G') value = 6;
	else if (column[0] == 'H') value = 7;
	else printf("\nerror!");*/

	return value;
}
