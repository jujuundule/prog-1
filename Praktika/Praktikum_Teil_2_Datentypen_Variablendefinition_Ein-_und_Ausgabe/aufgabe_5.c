#include <stdio.h>

/*
Aufgabe 5:
Lesen Sie mit nur einem scanf()-Funktionsaufruf Ihr Geburtstag auf 
3 Variablen ein und geben Sie es zur Kontrolle noch einmal aus. 
Testen Sie Möglichkeiten der Fehlerbehandlung bei Falscheingaben 
durch den Nutzer.
*/

int main() {
    int day, month, year;

    printf("Geben Sie Ihren Geburtstag im Format TT.MM.JJJJ ein: ");
    
    /*
    Zur Fehlerbehandlung wurde scanf() mit einer Bedingung versehen.
    Wenn scanf() 3 Werte einliest, wird die Bedingung erfüllt und
    der Codeblock wird ausgeführt. Andernfalls wird der else-Block
    ausgeführt.
    */
   
    if (scanf("%d.%d.%d", &day, &month, &year) == 3) {
        printf("Sie haben Ihren Geburtstag eingegeben: %02d.%02d.%04d\n", day, month, year);
    } else {
        printf("Falsche Eingabe. Bitte verwenden Sie das Format TT.MM.JJJJ.\n");
    }

    return 0;
}