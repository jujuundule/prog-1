#include <stdio.h>

/*

Aufgabe 4: Häufigkeit von Arrayelementen

In einem eindimensionalen Array sind n Elemente vom Typ int 
gespeichert. Schreiben Sie ein Programm, das das häufigste 
Element und dessen absolute Häufigkeit ermittelt, unter der 
Voraussetzung,

a) dass das Array bereits aufsteigend sortiert vorliegt 
(bei gleichen Häufigkeiten das kleinste Element),

b) das Array unsortiert vorliegt (bei gleicher Häufigkeit das 
zuerst aufgetretene Element).

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

// Absolute Häufigkeit ermitteln
void absoluteFrequency(int *v, int *p){
    int i, j, k, temp, max = 0, maxElement = 0;
    for(i = 0; i < (*p); i++){
        temp = 0;
        for(j = i+1; j < (*p); j++){
            if(v[i] == v[j]){
                temp++;
            }
        }
        if(temp > max){
            max = temp;
            maxElement = v[i];
        }
    }
    printf("Das Element %d kommt %d mal vor.\n", maxElement, max+1);
}

// Element an k-ter Stelle ersetzen
void insertElement(int *v, int k, int neueZahl){
    v[k] = neueZahl;
}

int main(){

    int array_1[] = {3,3,4,5,24,64,3,4,5,2,2,1,0,6,3};
    int anz = sizeof(array_1) / sizeof(int);
    int *panz = &anz; // Zeiger auf die Anzahl der Array-Elemente

    // Ausgabe des Arrays
    ausgabeArray(array_1, &anz);
    printf("\n\n");

    // Absolute Häufigkeit ermitteln
    absoluteFrequency(array_1, panz);
    printf("\n\n");
    return 0;
}