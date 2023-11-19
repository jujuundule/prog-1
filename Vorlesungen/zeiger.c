#include <stdio.h>

// Zeiger

void quadrat(int *p){
    *p *= (*p);
}

void quadrat2(int i){
    i *= i;
}

// Wert eines Arrays mit Zeiger ausgeben
printvek(int* v, int anz){
    v = v + (anz-1); //zeigt auf letztes Element
    for(int i = 0; i < anz; i++, v--){
        printf("v[%d] = %d\n", i, *v);
    }
}

// Anzahl einer Zeichenkette ermitteln

int strlen(char *str){
    char *c;
    c=str;
    while(*c!='\0'){
        c++;
    }
    return c-str; // Länge der Zeichenkette zurückgeben
}

void zeigerTest(int* zeiger_1, int* zeiger_2, int* zeiger_3){
    *zeiger_1 = 1;
    *zeiger_2 = 2;
    *zeiger_3 = 3;
}

int main(){
    // Defintition und Initialisierung eines Zeigers und einer Variable
    int *zeiger, a;
    a = 5;

    // Zeiger auf die Adresse von a setzen
    zeiger = &a;

    // Wert der Variable a ausgeben
    printf("a = %d\n", a);
    
    // Adresse der Variable a ausgeben
    printf("&a = %p\n", &a);
    
    // Adresse auf die der Zeiger zeigt ausgeben (Adresse von a)
    printf("zeiger = %p\n", zeiger);
    
    // Inhalt der Adresse, auf die der Zeiger zeigt, ausgeben (Wert von a)
    printf("*zeiger = %d\n", *zeiger);
    
    // Adresse des Zeigers ausgeben
    printf("&zeiger = %p\n", &zeiger);

    int i = 5;

    quadrat2(i);
    printf("\nQuadrat von 5 = %d\n", i);

    quadrat(&i);
    printf("\nQuadrat von 5 = %d\n\n", i);

    // Zeiger und Arrays

    int array[4] = {10,11,12,13};
    int *p;
    p=array; // identisch mit p=&array[0]
    
    // Werte des Arrays mit Zeiger ausgeben
    printvek(p, 4);

    //Anzahl einer Zeichenkette
    printf("\n\n%s ist %d Zeichen lang\n", "Hallo", strlen("Hallo"));
    

    int *z_1, *z_2, *z_3;
    int a_1, a_2, a_3;
    z_1 = &a_1;
    z_2 = &a_2;
    z_3 = &a_3;

    a_1 = 0;
    a_2 = 0;
    a_3 = 0;

    printf("a_1 = %d\n", a_1);
    printf("a_2 = %d\n", a_2);
    printf("a_3 = %d\n", a_3);
    zeigerTest(z_1, z_2, z_3);
    printf("a_1 = %d\n", a_1);
    printf("a_2 = %d\n", a_2);
    printf("a_3 = %d\n", a_3);

    return 0;
}