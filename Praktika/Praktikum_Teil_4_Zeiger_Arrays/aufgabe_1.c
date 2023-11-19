#include <stdio.h>
/*

1. Führen Sie eine einfache Rotation des Arrays nach links durch, d.h. das 
letzte Element bekommt den Wert des ersten Elementes zugewiesen, das erste 
den des zweiten, das zweite den des dritten usw. Kein Wert darf dabei verloren gehen.

2. Führen Sie eine einfache Rotation des Arrays nach rechts durch, d.h. das 
erste Element bekommt den Wert des n-ten Elementes zugewiesen, das zweite den 
des ersten usw.

3. Verallgemeinern Sie Ihr Programm dahingehend, dass eine m-fache Rotation 
(m<n) in eine beliebige Richtung des Arrays möglich ist. Die Rotationsrichtung 
und die Rotationsweite m sind vom Nutzer abzufragen.

*/

// Ausgabefunktion
void arrayAusgabe(int *vek, int n){
    for(int i=0; i<n; i++){
        printf("%d ", vek[i]);
    }
    printf("\n\n");
}

// Aufgabe 1: Rotation eines Arrays nach links 
void rotateLeft(int *vek, int n){
    int i;
    int temp = vek[0];      // ertses Element in temporärer Variable speichern

    for(i=0; i<n-1; i++){  // Schleife bis Anzahl -1 laufen lassen!!
        vek[i] = vek[i+1];
    }

    vek[n-1] = temp;
}

// Aufgabe 2: Rotation eines Arrays nach rechts

void rotateRight(int *vek, int n){
    int i;
    int temp = vek[n-1];

    for(i=n-1; i>=0; i--){
        vek[i] = vek[i-1];
    }

    vek[0] = temp;
}

// Aufgabe 3: m-fache Rotation nach links oder rechts

void rotateLeftN(int* v, int anz, int n){
    for(int i = 0; i < n; i++){
        rotateLeft(v, anz);
    }
}

void rotateRightN(int* v, int anz, int n){
    for(int i = 0; i < n; i++){
        rotateRight(v, anz);
    }
}

void rotateArray(int *v, int anz, char r, int t){
    switch(r){
        case 'l': rotateLeftN(v, anz, t); 
        break;
        case 'r': rotateRightN(v, anz, t); 
        break;
    }
}


int main(){
    int array[20] = {1,2,3,4,5,6,7,8,9,10};
    int max = 20, anzahl = 10;

/*
    printf("Ausgabe des nach Links rotierten Array:\n");
   
    rotateLeft(array, anzahl);
    arrayAusgabe(array, anzahl);

    

    printf("Ausgabe des nach Rechts rotierten Array:\n");
    
    rotateRight(array, anzahl);
    rotateRight(array, anzahl);
    arrayAusgabe(array, anzahl);   
*/
    char rotationRichtung;
    int rotationAnzahl = 0;
    
    printf("\nRotationsrichtung angeben [r/l]: \n");
    scanf("%c", &rotationRichtung);

    printf("\nRotationsanzahl angeben [Zahl]: \n");
    scanf("%d", &rotationAnzahl);

    rotateArray(array, anzahl, rotationRichtung, rotationAnzahl);
    
    printf("\nAusgabe des Arrays:\n");
    arrayAusgabe(array, anzahl); 

    
    return 0;
}
