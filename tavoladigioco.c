#include "tavoladigioco.h"

#include <stdio.h>

int inizializza_tavola(int mat[DIM][DIM], in_player playerbianco, in_player playernero) {

	for (int i = 2; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			mat[i][j] = VUOTO;
		}
	}
	mat[7][0] = playerbianco->TORRE;
	mat[7][1] = playerbianco->CAVALLO;
	mat[7][2] = playerbianco->ALFIERE;
	mat[7][3] = playerbianco->RE;
	mat[7][4] = playerbianco->REGINA;
	mat[7][5] = playerbianco->ALFIERE;
	mat[7][6] = playerbianco->CAVALLO;
	mat[7][7] = playerbianco->TORRE;
	mat[6][0] = playerbianco->PEDONE;
	mat[6][1] = playerbianco->PEDONE;
	mat[6][2] = playerbianco->PEDONE;
	mat[6][3] = playerbianco->PEDONE;
	mat[6][4] = playerbianco->PEDONE;
	mat[6][5] = playerbianco->PEDONE;
	mat[6][6] = playerbianco->PEDONE;
	mat[6][7] = playerbianco->PEDONE;

	mat[0][0] = playernero->TORRE;
	mat[0][1] = playernero->CAVALLO;
	mat[0][2] = playernero->ALFIERE;
	mat[0][3] = playernero->RE;
	mat[0][4] = playernero->REGINA;
	mat[0][5] = playernero->ALFIERE;
	mat[0][6] = playernero->CAVALLO;
	mat[0][7] = playernero->TORRE;
	mat[1][0] = playernero->PEDONE;
	mat[1][1] = playernero->PEDONE;
	mat[1][2] = playernero->PEDONE;
	mat[1][3] = playernero->PEDONE;
	mat[1][4] = playernero->PEDONE;
	mat[1][5] = playernero->PEDONE;
	mat[1][6] = playernero->PEDONE;
	mat[1][7] = playernero->PEDONE;

	
	return 0;

}
void stampa_tavola(int mat[DIM][DIM]) {
	printf("                      A    B    C    D    E    F    G    H \n\n");
	for (int i = 0; i < DIM; i++) {
		printf("                 %d  ", i + 1);
		for (int j = 0; j < DIM; j++) {
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
}

