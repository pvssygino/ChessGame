#ifndef TAVOLA_DI_GIOCO
#define TAVOLA_DI_GIOCO
#include "player.h"
#define DIM 8


int inizializza_tavola(int mat[DIM][DIM],in_player playerbianco, in_player playernero );
void stampa_tavola(int mat[DIM][DIM]);
bool mio(int MAT[8][8], int x, int y, int pezzo);


#endif
