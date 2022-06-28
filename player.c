#include "player.h"
#include "tavoladigioco.h"
#include <stdio.h>
#include <stdlib.h>
in_player initialize(int p) {
	int n = 0;
	in_player list = (in_player)malloc(sizeof(struct player_game));
	if (p == 0) {//bianchi iniziano con 1
		n = 100;
		list->RE = n + RE_N;
		list->REGINA = n + REGINA_N;
		list->TORRE = n + TORRE_N;
		list->ALFIERE = n + ALFIERE_N;
		list->CAVALLO = n + CAVALLO_N;
		list->PEDONE = n + PEDONE_N;
	}
	else { //neri iniziano con 2
		n = 200;
		list->RE = n + RE_N;
		list->REGINA = n + REGINA_N;
		list->TORRE = n + TORRE_N;
		list->ALFIERE = n + ALFIERE_N;
		list->CAVALLO = n + CAVALLO_N;
		list->PEDONE = n + PEDONE_N;
	}
	return list;
}
int find(in_player list, int n_pezzo) {
	int done = 0;
	if (n_pezzo == list->ALFIERE || n_pezzo == list->CAVALLO || n_pezzo == list->PEDONE || n_pezzo == list->REGINA || n_pezzo == list->RE || n_pezzo == list->TORRE) {
		done = 1;
	}
	return done;
}

int can_move(int MAT[8][8], int pezzo, int current_x, int current_y, int dest_x, int dest_y) {
	int can_do = 0;
	bool miopezzo = mio(MAT, dest_x, dest_y, pezzo);
	bool check_diagonale = false; //ALFIERE
	bool check_riga = false; //TORRE
	int getAllX[8]; //CAVALLO
	int getAllY[8]; //CAVALLO
	if (miopezzo == false) {
		if (pezzo == 200 + PEDONE_N || pezzo == 100 + PEDONE_N) {
			if (current_y == dest_y) {
				if ((abs(current_x - dest_x) == 1 || abs(current_x - dest_x) == 2)) {  //movimento verticale pedone
					if (MAT[dest_x][dest_y] == VUOTO) can_do = 1;
				}
			}
			else if (abs(current_y - dest_y) == 1 && abs(current_x - dest_x) == 1) { //movimento diagonale pedone
				if (MAT[dest_x][dest_y] != VUOTO) can_do = 1;
			}
		}

		if (pezzo == 200 + ALFIERE_N || pezzo == 100 + ALFIERE_N) {
			for (int i = 1; i < 8 - current_y; i++) {
				if (dest_x == current_x - i && dest_y == current_y + i)
					for (int j = 1; j < 8 - current_y; j++) {
						check_diagonale = mio(MAT, current_x - j, current_y + j, pezzo);
						if (check_diagonale == true) break;
						else can_do = 1;
					}
				else if (dest_x == current_x - i && dest_y == current_y - i)
					for (int j = 1; j < 8 - current_y; j++) {
						check_diagonale = mio(MAT, current_x - j, current_y - j, pezzo);
						if (check_diagonale == true) break;
						else can_do = 1;
					}
				else if (dest_x == current_x + i && dest_y == current_y - i)
					for (int j = 1; j < 8 - current_y; j++) {
						check_diagonale = mio(MAT, current_x + j, current_y - j, pezzo);
						if (check_diagonale == true) break;
						else can_do = 1;
					}
				else if (dest_x == current_x + i && dest_y == current_y + i)
					for (int j = 1; j < 8 - current_y; j++) {
						check_diagonale = mio(MAT, current_x + j, current_y + j, pezzo);
						if (check_diagonale == true) break;
						else can_do = 1;
					}
			}
		}
			if (pezzo == 200 + CAVALLO_N || pezzo == 100 + CAVALLO_N) {

				getAllX[0] = current_x - 2;              //Prendo ogni coppia (x,y) dove il cavallo può saltare
				getAllY[0] = current_y + 1;              //nel caso si trovi al bordo tavola verranno anche presi punti della matrice che non appartengono ad essa
				                                        //in ogni caso verrà confrontato l'input x e l'input y di destinazione per vedere se è presente nella coppia
				getAllX[1] = current_x - 2;             //degli spostamenti del cavallo.
				getAllY[1] = current_y - 1;

				getAllX[2] = current_x + 2;
				getAllY[2] = current_y + 1;

				getAllY[3] = current_x + 2;
				getAllY[3] = current_y - 1;

				getAllX[4] = current_x - 1;
				getAllY[4] = current_y - 2;

				getAllX[5] = current_x - 1;
				getAllY[5] = current_y + 2;

				getAllX[6] = current_x + 1;
				getAllY[6] = current_y - 2;

				getAllX[7] = current_x + 1;
				getAllY[7] = current_y + 2;

				int contiamo = 0;
				while (contiamo != 8) {
					if (dest_x == getAllX[contiamo] && dest_y == getAllY[contiamo]){
						can_do = 1;
					}
					contiamo++;
				}			
			}
			if (pezzo == 200 + TORRE_N || pezzo == 100 + TORRE_N) {
				for (int i = 1; i < 8 - current_y; i++) {
					if (dest_x == current_x + i && dest_y == current_y)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x + j, current_y, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x - i && dest_y == current_y)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x - j, current_y, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x && dest_y == current_y +i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x, current_y + j, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x && dest_y == current_y - i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x, current_y -j, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
				}
			}
			if (pezzo == 200 + RE_N || pezzo == 100 + RE_N) {
				if ((abs(current_x - dest_x) == 1 || abs(current_x - dest_x) == 2)) {
					if (MAT[dest_x][dest_y] == VUOTO) can_do = 1;
				}
			}
			if (pezzo == 200 + REGINA_N || pezzo == 100 + REGINA_N) {
				for (int i = 1; i < 8 - current_y; i++) {
					if (dest_x == current_x - i && dest_y == current_y + i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_diagonale = mio(MAT, current_x - j, current_y + j, pezzo);
							if (check_diagonale == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x - i && dest_y == current_y - i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_diagonale = mio(MAT, current_x - j, current_y - j, pezzo);
							if (check_diagonale == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x + i && dest_y == current_y - i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_diagonale = mio(MAT, current_x + j, current_y - j, pezzo);
							if (check_diagonale == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x + i && dest_y == current_y + i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_diagonale = mio(MAT, current_x + j, current_y + j, pezzo);
							if (check_diagonale == true) break;
							else can_do = 1;
						}
					if (dest_x == current_x + i && dest_y == current_y)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x + j, current_y, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x - i && dest_y == current_y)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x - j, current_y, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x && dest_y == current_y + i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x, current_y + j, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
					else if (dest_x == current_x && dest_y == current_y - i)
						for (int j = 1; j < 8 - current_y; j++) {
							check_riga = mio(MAT, current_x, current_y - j, pezzo);
							if (check_riga == true) break;
							else can_do = 1;
						}
				}

			}
		
	}
	return can_do;
}
