# Gioco-degli-Scacchi
Riproduzione in console application del gioco degli scacchi<br/>

I pezzi bianchi inziano per 1XX, quelli neri con 2XX, mentre 999 rappresenta una casella non occupata.<br/>
![immagine2](https://user-images.githubusercontent.com/16807583/212702914-0434d6fb-ecf6-43e0-a657-3a83e1a5d8b7.png)


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
Prima di muovere un pedone, è importante valutare il caso in cui una qualsiasi figura bianca o nera si trovi di fronte ad esso, impedendone il movimento in avanti. In questo caso, il pedone può essere mosso in diagonale solo se è presente un pezzo avversario nelle caselle adiacenti (x+1,y+1) o (x+1,y-1). Per verificare la presenza di un pezzo nemico nelle caselle, è necessario utilizzare un algoritmo. Solo dopo aver verificato la presenza del pezzo avversario, il pedone può essere mosso in diagonale per catturarlo.
## alfiere
Date X,Y come coordinate di posizione di un alfiere, questo potrà muoversi soltanto se le sue diagonali sono libere fino al punto di destinazione:<br/>
il suo movimento su due diagonali viene scomposto in quattro diagonali di movimento, dividendo quindi ogni diagonale in due e avendo x,y come punto di riferimento. 
