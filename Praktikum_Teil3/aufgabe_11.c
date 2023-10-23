#include <stdio.h>
#include <math.h>

/*
Aufgabe 11: Funktionstabellen

Schreiben Sie ein Programm, das auf Wunsch Funktionstabellen für 
(mindestens 3) trigonometrische Funktionen generieren kann. Der 
Nutzer soll dabei die Funktion, die untere und obere Schranke und 
die Schrittweite wählen können. Achten Sie auf eine übersichtliche 
Darstellung auf dem Bildschirm. Sind mehr Daten anzuzeigen, als auf 
dem Bildschirm passen, so ist der Bildschirm erst nach Tastendruck 
durch den Nutzer weiter zu scollen.
*/

int main (){
char eingabeFunktion;
double startWert, endWert, schrittWeise;
int i;

printf("Wählen Sie eine Funktion aus!\n******************************\n\n[1]\tf(x) = sin(x)\n[2]\tg(x) = cos(x)\n[3]\th(x) = tan(x)\n");
scanf("%c", &eingabeFunktion);

// untere Schranke auswählen
printf("\n\nWählen Sie die untere Schranke aus: ");
scanf("%lf", &startWert);

// obere Schranke auswählen
printf("\n\nWählen Sie die obere Schranke aus: ");
scanf("%lf", &endWert);

// Schrittweise
printf("\n\nWählen Sie die Schrittweise: ");
scanf("%lf", &schrittWeise);

switch(eingabeFunktion){
    case 1:
        for(i = startWert; i <= endWert; i+schrittWeise){
            printf("\t%lf", i);
        }
        break;

}