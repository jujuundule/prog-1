#include <stdio.h>
#include <math.h>

/*
Aufgabe 3:
Erstellen Sie ein Programm, das eine Integerzahl 
einliest und dann sowohl von dieser als auch von 
ihren 4 direkten Nachfolgern die Quadratwurzel 
berechnet und zusammen mit der Zahl in einer 
kleinen Tabelle ausgibt. Verwenden Sie zur 
Berechnung die Funktion sqrt() der Standardbibliothek 
"math.h", die im Lehrheft beschrieben ist.
*/

int main(){
    int zahl = 0;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%i", &zahl);

    for (int i = 0; i <= 4; i++){
        double wurzel = sqrt(zahl + i);
        printf("%i\t%f\n", zahl + i, wurzel);
    }
}