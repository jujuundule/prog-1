#include <stdio.h>

/*
Aufgabe 5: Fehlersuche

Bestimmen und erklären Sie sich die Bildschirmausgaben des nachstehenden Programms.
*/

void main() {
    int erg, a, b, c;
    int y=5;
    
    printf("Wert von 7||(y==0): %d\n",7||(y==0)); // 1
    printf("Wert von y: %d\n\n",y); // 5
    // 7 ist nicht 0 (true), 5 ist nicht gleich 0 (false)
    //Da der ODER-Operator nur einen wahren Operanden benötigt, ist das Gesamtergebnis des Ausdrucks wahr (1).
    
    a = b = c = 0; 
    //Variablen a, b und c werden alle auf den Wert 0 gesetzt.
    erg = ++a || ++b && ++c; 
    //Da der linke Operand des ODER-Operators wahr ist, wird der rechte Operand ++b && ++c nicht ausgewertet, da der Ausdruck bereits wahr ist.
    //++b und ++c werden daher nicht ausgeführt, und ihre Werte bleiben 0.

    printf("erg = %d,\n a = %d,\n b = %d,\n c = %d\n\n\n", erg, a, b, c); // erg = 1, a = 1, b = 0, c = 0
   
    a = b = c = 0; 
    //Variablen a, b und c werden alle auf den Wert 0 gesetzt.
    erg = ++a && ++b || ++c;
    //Da der linke Operand des ODER-Operators wahr ist, wird der rechte Operand ++c nicht ausgewertet
    
   
    printf("erg = %d,\n a = %d,\n b = %d,\n c = %d\n\n\n", erg, a, b, c); // erg = 1, a = 1, b = 1, c = 0
}