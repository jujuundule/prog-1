#include <stdio.h>

/*

Aufgabe 5: k-kleinstes Element

Gegeben ist ein unsortiertes eindimensionales Array mit n 
Elementen vom Typ int. Erstellen Sie ein Programm, das das 
k-kleinste Element ermittelt, wobei 1<=k<=n gilt und das Array

a) keine Duplikate enthält,
b) Duplikate enthalten darf.

Beispiel: In einem Array mit dem Inhalt 4 1 5 3 8 7 6 müsste die Suche nach dem zweitkleinsten Element den Wert 3 liefern.

*/

// Ausgabefunktion
void ausgabeArray(int *vek, int *n){
    for(int i = 0; i <= (*n) - 1; i++){
        printf("%d ", vek[i]);
    }
}

// Entfernen von Duplikaten
int removeDuplicates(int *v, int *p){
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

// Ermittlung des k-kleinsten Elements
void smallestElement(int *v, int *p, int k){
    int i, j, temp, min = 0;

    for(i = 0; i < (*p); i++){
        temp = 0;
        for(j = i+1; j < (*p); j++){
            if(v[i] > v[j]){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    printf("\n\nDas %d-kleinste Element ist %d.\n", k, v[k-1]);
}

int main(){

    int array_1[] = {3,3,4,5,24,64,3,4,5,2,2,1,0,6,3};
    int k, anz = sizeof(array_1) / sizeof(int);
    int *panz = &anz; // Zeiger auf die Anzahl der Array-Elemente

    // Ausgabe des Arrays
    ausgabeArray(array_1, panz);
    printf("\n\n");

    printf("Welches k-kleinste Element soll ermittelt werden?\n");
    
    if(scanf("%d", &k)){
        removeDuplicates(array_1, panz);
        smallestElement(array_1, panz, k);
        ausgabeArray(array_1, panz);
    }else{
        printf("Fehler bei der Eingabe!\n");
    }
    printf("\n\n");
    

    return 0;
}