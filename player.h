#ifndef LISTA_PEZZI
#define LISTA_PEZZI
#define RE_N 50
#define REGINA_N 40
#define TORRE_N 30
#define ALFIERE_N 20
#define CAVALLO_N 10
#define PEDONE_N 1

#define VUOTO 999
struct player_game {
	int RE;
	int REGINA;
	int TORRE;
	int CAVALLO;
	int ALFIERE;
	int PEDONE;
};
typedef player_game *in_player;
in_player initialize(int p);
int find(in_player, int n_pezzo);

int can_move(int MAT[8][8], int pezzo, int current_x, int current_y, int dest_x, int dest_y);

#endif 
