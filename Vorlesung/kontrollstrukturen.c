#include <stdio.h>

int main(void) {
    int i = 3, j = 12;

    for(int i = 1; i <= 10; i++) {  // Zeilenausgabe wiederholen
        if(i%2 == 0) continue;      // % ist der Modulo-Operator
        for(j = 1; j <= 10; j++) {  // Zeile ausgeben
            printf("%4d ", j*i);
        }
        printf("\n");
        
    }
    printf("\n\n");

    i = 0;
    if (i == 0){ // Achtung!!! Vergleichsoperator ==, Zuweisungsoperator =
        printf("*\n\n");
    } 

    i = 1;
    printf("i = %d\n", -i);
    return 0;
}