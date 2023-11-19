#include <stdio.h>

/*
Aufgabe 4: Operatorprioritäten

Wie werden die Operanden und Operatoren im folgenden Ausdruck zusammengefasst?
      x = -4 * ++i - 6 % 4
Setzen Sie entsprechende Klammern und überprüfen Sie, ob das Programm noch den gleichen Wert für x ermittelt.
*/

int main(){
    int i = 0;
    int x = -4 * ++i - 6 % 4;

    /*
    OPERATORPRIORITÄTEN:

    Operattor:          Priorität:
    *******************************
    
    Funktionsaufruf (()):       15
    Präfix (++i):               14
    Multiplikation (*):         13
    Modulo (%):                 13
    Subtraktion (-):            12
    Zuweisung (=):               2

    *******************************
    */

    printf("-4 * ++i - 6 % 4 = %d\n\n", x);
    // -6
    i = 0;
    x = -4 * (++i - 6) % 4;
    printf("-4 * (++i - 6) % 4 = %d\n\n", x);
    // 0
    i = 0;
    x = (-4 * ++i - 6) % 4;
    printf("(-4 * ++i - 6) % 4 = %d\n\n", x);
    // -2

}