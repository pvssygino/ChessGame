#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "script.h"
#include "tavoladigioco.h"

int TAVOLA[DIM][DIM];

void gioca();
in_player playerbianco = initialize(0);
in_player playernero = initialize(1);
#pragma warning(disable:4996)
int main() {

	int pezzo = 0;
	int verify = 0;
	int input_r = 0, input_c = 0;
	int x = 0, y = 0;
	int switch_ = 0;
	enum { PLAYER,COM };
	printf("Benvenuto nel gioco degli scacchi!\n");
	printf(" 0. Gioca contro un amico\n");
	printf(" 1. Gioca contro il computer\n");
	printf(" >");
	scanf("%d", &switch_);

	switch (switch_) {
	case PLAYER:
		printf("------------------------------------------>Inizializzazione Tavola() - OK\n");
		printf("I pezzi del bianco iniziano con 1XX, i pezzi del nero iniziano con 2XX!\n\n");
		inizializza_tavola(TAVOLA,playerbianco,playernero);
		stampa_tavola(TAVOLA);
		gioca();
		break;
	case COM:
		break;
	default:
		break;

	}
}
void gioca(){

	int input_r = 0;
	int verify = 0;
	int pezzo = 0;
	int x = 0;
	char y[2];
	int y_int = 0;
	char input_c[2];
	int c = 0;

	int turn = 0;
	while (turn != 2) {
		turn == 0 ? printf("Turno: BIANCO\n") : printf("Turno: NERO\n");
		printf("Inserisci le cordinate del pezzo da che desideri muovere (r,c)\n");
		printf(" r>");
		scanf("%d", &input_r);
		printf(" c>");
		scanf("%s", &input_c);
		c = return_column(input_c);
		pezzo = TAVOLA[input_r - 1][c];

		if (pezzo == VUOTO) 
         printf("-------------------------------------> casella vuota!\n");
		else {
			if (turn == 0)
				verify = find(playerbianco, pezzo);
			else if (turn == 1)
				verify = find(playernero, pezzo);

			if (verify == 1) {
				printf("Inserisci le coordinate di destinazione (r,c)\n");
				printf("r>");
				scanf("%d", &x);
				printf("c>");
				scanf("%s", &y);
				y_int = return_column(y);
				int check = can_move(TAVOLA, pezzo, input_r - 1, c, x - 1, y_int);
				if (check == 1) {
					TAVOLA[x - 1][y_int] = pezzo;
					TAVOLA[input_r - 1][c] = VUOTO;
					stampa_tavola(TAVOLA);
					turn == 0 ? turn = 1 : turn = 0;
				}
				else {
					printf("------------------------------------->Non puoi fare questo spostamento!\n\n");
					stampa_tavola(TAVOLA);
				}				
			}
			else {
				printf("-------------------------------------> Questo pezzo non ti appartiene!\n\n");
				stampa_tavola(TAVOLA);
			}
		}
	}
	
}
