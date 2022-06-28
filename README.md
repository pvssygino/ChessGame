# Gioco-degli-Scacchi
Riproduzione in console application del gioco degli scacchi<br/>

I pezzi bianchi inziano per 1XX, quelli neri con 2XX, mentre 999 rappresenta una casella non occupata.<br/>
# Pezzi
I pezzi sono identificati da un numero:<br/>

50 re<br/>
40 regina<br/>
30 torre<br/>
20 alfiere<br/>
10 cavallo<br/>
01 pedone<br/> 

--------------------
Esempio: il 150 è il re bianco, il 240 la regina nera
# Movimenti
La scacchiera è rappresenta da una matrice di interi 8x8 che viene riempita con il valore dei pezzi quando viene inizializzata. Quando si decide di muovere un pezzo verrà richiesta la posizione x,y del pezzo nella scacchiera e le coordinate di destinazione del pezzo dest_x,dest_y. Una funzione mio(Mat,x,y,pezzo) verifica che il pezzo che si sta muovendo appartiene al giocatore. Potrebbe infatti succedere che il bianco inserisca nelle coordinate del pezzo da muovere un pezzo nero!
## pedone
Quando viene selezionato un pedone come pezzo da muovere si deve innanzitutto verificare un caso generico che potrebbe verificarsi durante il metch, ovvero che una qualsiasi figura bianca/nera si trovi di fronte al pedone stesso e che quindi questo una volta selezionato non può fare il suo spostamento in avanti. Se il pedone non trova nessuno davanti può fare il suo spostamento. Si può decidere di fare un movimento in diagonale per mangiare un pezzo avversario soltanto quando è effetivamente presente un pezzo dell'avversario nelle caselle (x+1,y+1) (x+1,y-1) (x-1,y+1) (x-1,y-1). Un algoritmo verificherà se è presente un pezzo nemico nelle caselle, soddisfatta questa proprietà il pedone può compiere il movimento trasversale per mangiare.
