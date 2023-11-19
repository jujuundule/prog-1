#include<stdio.h>

/*
Aufgabe 2:
Ändern Sie das Programm aus Aufgabe 1, indem Sie 
Gleitkommazahlen für Eingabe und Ausgabe verwenden.
*/

void zahlEinlesen();

int main(){
    zahlEinlesen();
    return 0;
}

void zahlEinlesen(){
    float zahl1 = 0, zahl2 = 0;
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%f", &zahl1);
            
    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%f", &zahl2);

    float sum = zahl1 + zahl2, diff = zahl1 - zahl2, quot = zahl1 / zahl2;
    
    printf("\n\nSumme: %.2f\nDifferenz: %.2f\nQuotient:%.2f\n\n\n", sum, diff, quot);
}