#include "player.h"
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
	bool miopezzo = false;
	int check = 0;
	if (pezzo == 200 + PEDONE_N || pezzo == 100 + PEDONE_N) {
		if (current_y == dest_y) {
			if ((abs(current_x - dest_x) == 1 || abs(current_x - dest_x) == 2)) {  //movimento verticale pedone
				if (MAT[dest_x][dest_y] == VUOTO) check = 1;
			}
		}
		else if (abs(current_y - dest_y) == 1 && abs(current_x - dest_x) == 1) { //movimento diagonale pedone
			if (MAT[dest_x][dest_y] != VUOTO) check = 1;
		}
		
	}
	if (pezzo == 200 + ALFIERE_N || pezzo == 100 + ALFIERE_N) {
		


	}
	return check;
}
