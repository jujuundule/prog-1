#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotheken/mylib.h" //Eigne Bibliothek

int main(){
    int a;
    char c;

    a = DAUEingabe("Den wievielten Buchstaben des Alphabets möchtest du sehen? ", 1, 26, 3);
    c = 'A' + (a - 1); // c = 65 + (a - 1);
    
    printf("\n\nDer %d-te Buchstabe ist ein %c (numerisch %d)\n\n", a, c, c);
    
    return 0;
}

