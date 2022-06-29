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
Quando viene selezionato un pedone come pezzo da muovere, ancor prima del movimento, si valuta il caso generico in cui potrebbe verificarsi che una qualsiasi figura bianca/nera si trovi di fronte al pedone stesso e che quindi questo una volta selezionato non può fare il suo spostamento in avanti. Si può decidere di fare un movimento in diagonale per mangiare un pezzo avversario soltanto quando è effetivamente presente un pezzo dell'avversario nelle caselle (x+1,y+1) (x+1,y-1). Un algoritmo verificherà la presenza di un pezzo nemico nelle caselle, soddisfatta questa proprietà il pedone può compiere il movimento trasversale.
## alfiere
Date X,Y come coordinate di posizione di un alfiere, questo potrà muoversi soltanto se le sue diagonali sono libere fino al punto di destinazione:<br/>
sapendo che x,y è la posizione dell'alfiere, scomponiamo il suo movimento su due diagonali in quattro diagonali di movimento, dividendo quindi ogni diagonale in due diagonali che hanno come punto di riferimento x,y. 
