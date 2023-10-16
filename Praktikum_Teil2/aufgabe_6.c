#include<stdio.h>

/* 
Aufgabe 6:
Dividieren Sie zwei Integerzahlen, die Sie von der Tastatur eingelesen haben,
einmal mit und einmal ohne erzwungene Typumwandlung zur Gleitkommazahl und 
speichern Sie das Ergebnis jeweils auf eine Variable vom Typ float. Geben Sie
das Ergebnis aus und erklären sich die Abweichung der beiden Werte, 
wenn die eine Integerzahl nicht durch die andere teilbar ist.
*/

int main(){
    int zahl1 = 0, zahl2 = 0;
    printf("Geben Sie die erste Zahl ein: ");
    scanf("%i", &zahl1);
            
    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%i", &zahl2);

    float quotFloat = (float) zahl1 / zahl2;
    float quotNormal = zahl1 / zahl2;

    // Ohne erzwungener Typwandlung wird der Nachkommawert abgeschnitten
    
    printf("Mit erzwungener Typwandlung: %.1f\n", quotFloat);
    printf("Ohne erzwungener Typwandlung: %.1f\n", quotNormal);
}
    