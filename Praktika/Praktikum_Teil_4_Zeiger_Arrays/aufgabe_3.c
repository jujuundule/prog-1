#include <stdio.h>

/*

Aufgabe 3: Entfernen von Duplikaten

Gegeben ist ein eindimensionales Array mit n Elementen vom Typ int,
der bei der Variablendefinition initialisiert wird. Schreiben Sie 
ein Programm, das alle Duplikate aus dem Array entfernt, wenn

a) das Array aufsteigend sortiert ist,
b) das Array unsortiert vorliegt.

*/

// Ausgabefunktion
void ausgabeArray(int *vek, int *n){
    for(int i = 0; i <= (*n) - 1; i++){
        printf("%d ", vek[i]);
    }
}

// Array aufsteigend sortieren
void sortArray(int *v, int *p){
    int i, j, temp;
    for(i = 0; i < (*p); i++){
        for(j = i+1; j < (*p); j++){
            if(v[i] > v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Duplikate entfernen
void removeDuplicates(int *v, int *p){
    int i, j, k;
    for(i = 0; i < (*p); i++){
        for(j = i+1; j < (*p); j++){
            if(v[i] == v[j]){
                for(k = j; k < (*p); k++){
                    v[k] = v[k+1];
                }
                (*p)--;
                j--;
            }
        }
    }
}


int main(){

    int array_1[] = {1,2,2,2,2,3,4,5,3,3,10,2,2,1,5,4,4,2,3,4};
    int anz = sizeof(array_1) / sizeof(int);
    int *panz = &anz; // Zeiger auf die Anzahl der Array-Elemente

    // Ausgabe des Arrays
    ausgabeArray(array_1, &anz);
    printf("\n\n");

    //Sortieren des Arrays
    printf("Array sortieren:\n");
    sortArray(array_1, panz);
    ausgabeArray(array_1, &anz);
    printf("\n\n");
    
    // Entfernen der Duplikate
    printf("Duplikate entfernen:\n");
    removeDuplicates(array_1, panz);
    ausgabeArray(array_1, &anz);
    printf("\n\n");

    return 0;
}