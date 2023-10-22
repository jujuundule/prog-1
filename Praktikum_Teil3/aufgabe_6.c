#include <stdio.h>

/*
Aufgabe 6: Logische Ausdrücke

Schreiben Sie ein Programm mit dessen Hilfe Sie für einer Integervariablen 
x=7 
den Wert der folgenden logischen Ausdrücke berechnen und anzeigen können. 
Erklären Sie sich die ermittelten Ausgaben.
*/

int main (){
    int x = 7;
    printf("Ergebnis von x < 9 && x >= -5: %d\n", x < 9 && x >= -5);
    // Dieser Ausdruck prüft, ob x kleiner als 9 ist UND ob x größer oder gleich -5 ist.
    // Der Wert ist true (1), da x kleiner als 9 ist UND x größer oder gleich -5 ist.
     
    printf("Ergebnis von !x && x >= 3: %d\n", !x && x >= 3);
    // Dieser Ausdruck prüft, ob x negiert (unwahr) ist und gleichzeitig größer oder gleich 3 ist.
    //Der Wert ist false (0), da !x false (0) ist. Da der linke Operand des UND-Operators false ist, wird der rechte Operand nicht ausgewertet.
     
    printf("Ergebnis von x++ == 8 || x == 7: %d\n", x++ == 8 || x == 7);
    // Dieser Ausdruck prüft, ob x gleich 8 ist, bevor x um 1 erhöht wird, oder ob x gleich 7 ist.
    // Der Wert ist false (0), da x nicht gleich 8 ist, bevor x um 1 erhöht wird. 
    // Nach der Erhöhung von x ist x ungleich 7, deshalb ist der rechte Operand des ODER-Operators ebenfalls false (0).
}