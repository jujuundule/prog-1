#include<stdio.h>

/*
Aufgabe 2:
Ändern Sie das Programm aus Aufgabe 1, indem Sie 
Gleitkommazahlen für Eingabe und Ausgabe verwenden.
*/

int main(){
    float zahl1 = 0, zahl2 = 0;
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%f", &zahl1);
            
    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%f", &zahl2);
                    
    float sum = (float) zahl1 + zahl2;
    float diff = (float) zahl1 - zahl2;
    // das ist eine implizite Typumwandlung
    float quot = (float) zahl1 / zahl2;

    printf("Summe: %.2f\nDifferenz: %.2f\nQuotient:%.2f\n", sum, diff, quot);
}