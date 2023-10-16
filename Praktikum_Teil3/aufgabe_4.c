#include <stdio.h>

/*
Aufgabe 4: Operatorprioritäten

Wie werden die Operanden und Operatoren im folgenden Ausdruck zusammengefasst?
      x = -4 * ++i - 6 % 4
Setzen Sie entsprechende Klammern und überprüfen Sie, ob das Programm noch den gleichen Wert für x ermittelt.
*/

int main(){
    double x = -4 * ++i - 6 % 4;

    /*
    Multiplikation:     Priorität 13,
    Präfix:             14
    Subtraktion:        
    */

    printf("%d", x);

}