#include<stdio.h>

/*
Aufgabe 1:
Schreiben Sie ein Programm, dass Sie nacheinander 
zur Eingabe von 2 Integerzahlen auffordert, die 
von Ihnen eingegebenen Zahlen auf zwei Variablen 
vom Typ int abspeichert und danach die Summe, die 
Differenz, das Produkt und den Quotienten ausgibt.
*/

int main(){
    int zahl1 = 0, zahl2 = 0;
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%i", &zahl1);
            
    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%i", &zahl2);
                    
    int sum = zahl1 + zahl2, diff = zahl1 - zahl2, quot = zahl1 / zahl2;
    printf("Summe: %i\nDifferenz: %i\nQuotient:%i\n", sum, diff, quot);
}