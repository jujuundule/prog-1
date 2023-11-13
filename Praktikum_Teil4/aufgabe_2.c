#include <stdio.h>

/*

1. Schreiben Sie ein Programm, das das k-te Element (k<=m) aus dem Array entfernt 
und die entstandene Lücke durch heranziehen der restlichen Arrayelemente schließt.

2. Erweitern Sie Ihr Programm dahingehend, dass hinter dem k-ten Element (k<=m) 
ein neuer int-Wert eingefügt werden kann.

*/

// Ausgabefunktion
void arrayAusgabe(int *vek, int n){
    for(int i=0; i<n; i++){
        printf("%d ", vek[i]);
    }
    printf("\n\n");
}

// Rotation eines Arrays nach links 
void rotateLeft(int *vek, int n){
    int i;
    int temp = vek[0];      // ertses Element in temporärer Variable speichern

    for(i=0; i<n-1; i++){  // Schleife bis Anzahl -1 laufen lassen!!
        vek[i] = vek[i+1];
    }

    vek[n-1] = temp;
}

// Rotation eines Arrays nach rechts

void rotateRight(int *vek, int n){
    int i;
    int temp = vek[n-1];

    for(i=n-1; i>=0; i--){
        vek[i] = vek[i-1];
    }

    vek[0] = temp;
}

// Aufgabe 1: Entfernen des k-ten Elements

void loeschen(int *v, int *panz, int p){

}

int einfügen(int *array, int* panz, int maxanz, int e, int p){
    
}

int main(){
    int vektor[10] = {1,2,3,4,5,6,7,8,9,10};
    int anz = 10;

    removeElement(vektor, anz, 5);
    arrayAusgabe(vektor, anz-1);
    return 0;
}