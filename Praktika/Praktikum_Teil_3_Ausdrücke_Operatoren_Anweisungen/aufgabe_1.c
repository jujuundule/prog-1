#include <stdio.h>
#include <math.h>

/*
Aufgabe 1: Würfel

Erstellen Sie ein Programm zur Berechnung von 
Eigenschaften eines Würfels, das bei gegebener 
(d.h. in Ihrem Fall einzugebender) Kantenlänge a

den Flächenumfang (=6a*a),
das Volumen (=a*a*a) und
die Länge der Raumdiagonale (=a*sqrt(3))

berechnet und ausgibt.
*/

int main () {
    float kanteWuerfel, laengeWuerfelDiagonale, volumenWuerfel, flaechenumfangWuerfel = 0;
    
    printf("Geben Sie die Kantenlänge des Würfels ein: ");
    scanf("%f", &kanteWuerfel);

    flaechenumfangWuerfel = 6*kanteWuerfel*kanteWuerfel;
    volumenWuerfel = kanteWuerfel*kanteWuerfel*kanteWuerfel;
    laengeWuerfelDiagonale = sqrt(3)*kanteWuerfel;

    printf("Der Flächenumfang des Würfels beträgt: %.2f cm²\n", flaechenumfangWuerfel);
    printf("Das Volumen des Würfels beträgt: %.2f cm³\n", volumenWuerfel);
    printf("Die Länge der Würfeldiagonale beträgt: %.2f cm\n", laengeWuerfelDiagonale);

}