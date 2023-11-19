#include <stdio.h>

/*
Aufgabe 8: Maximum

Schreiben Sie ein Programm, dass zwei int-Werte von der Tastatur 
einliest und mit Hilfe der if-Anweisung das Maximum dieser zwei 
Werte bestimmt und ausgibt. Sind beide Werte gleich, so ist auch 
dies zu erkennen.
Nutzen Sie nun den bedingten Operator zur Lösung des Problems.
*/

int main(){
    int a, b = 0;

    // erste Zahl einlesen
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &a);

    // zweite Zahl einlesen
    printf("Geben Sie eine weitere Zahl ein: ");
    scanf("%d", &b);

    // der bedingte Operator ist eine Abkürzung für eine if-else-Verzweigung
    a > b ? printf("Die erste Zahl ist größer als die zweite Zahl.\n") : a < b ? printf("Die zweite Zahl ist größer als die erste Zahl.\n") : printf("Die beiden Zahlen sind gleich groß.\n");
}