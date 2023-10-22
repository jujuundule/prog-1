#include <stdio.h>

/*
Aufgabe 3: Einfache Werteberechnungen
Welchen Wert haben die folgenden arithmetischen Ausdrücke?
    3/4   
    15%4   
    15/2.0   
    3+5%4   
    3*7%4
*/

int main(){
// Dies ist eine Division von 3 durch 4. In C wird die Division ganzzahlig durchgeführt, wobei der Bruchteil abgeschnitten wird. Das Ergebnis ist 0. 
printf("3/4: %d\n", 3/4);

//Dies ist der Modulo-Operator, der den Rest der Division von 15 durch 4 berechnet. In C ergibt dies den Wert 3, da der Rest der Division von 15 durch 4 3 ist.
printf("15%4: %d\n", 15%4);

//Hier wird 15 durch 2.0 geteilt, was eine Gleitkommazahl ergibt. Das Ergebnis ist 7,5.
printf("15/2.0: %.1f\n", 15/2.0);

//Zuerst wird 5%4 berechnet, was in C ebenfalls den Wert 1 ergibt (Rest der Division von 5 durch 4). Dann wird 3 zu 1 addiert, was 4 ergibt.
printf("3+5%4: %d\n", 3+5%4);

//Zuerst wird 3*5 berechnet, was 15 ergibt. Dann wird 15%4 berechnet, was den Wert 3 ergibt (Rest der Division von 15 durch 4).
printf("3*5%4: %d\n", 3*5%4);

}