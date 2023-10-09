#include<stdio.h>

int main(){
    int zahl1 = 0, zahl2 = 0;

    printf("Geben Sie die erste Zahl ein: ");
    scanf("%i", &zahl1);

    printf("Geben Sie die zweite Zahl ein: ");
    scanf("%i", &zahl2);

    int sum = zahl1 + zahl2, diff = zahl1 - zahl2, quot =zahl1 / zahl2;
    printf("Summe: %i\nDifferenz: %i\nQuotient:%i\n", sum, diff, quot);
}