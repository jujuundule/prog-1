#include <stdio.h>

/*
Aufgabe 2: Einfügen und Löschen von Arrayelementen

1. Schreiben Sie ein Programm, das das k-te Element (k<=m) aus dem Array entfernt 
und die entstandene Lücke durch heranziehen der restlichen Arrayelemente schließt.

2. Erweitern Sie Ihr Programm dahingehend, dass hinter dem k-ten Element (k<=m) 
ein neuer int-Wert eingefügt werden kann.

*/

// Ausgabefunktion
void ausgabeArray(int *vek, int *n){
    for(int i = 0; i <= (*n) - 1; i++){
        printf("%d ", vek[i]);
    }
}

// ein k-tes Element aus einem Array löschen
void deleteElement(int *v, int *p, int k){
    for (int i = k; i < (*p); i++){
        v[i] = v[i+1];
    }
    (*p)--;
}

// Element an k-ter Stelle ersetzen
void insertElement(int *v, int k, int neueZahl){
    v[k] = neueZahl;
}

int main(){

    int array_1[] = {1,2,3,4,5,6,7,8,9,10};
    int k, neueZahl, anz = sizeof(array_1) / sizeof(int);
    int *panz = &anz; // Zeiger auf die Anzahl der Array-Elemente
    char modus;
    
    while(*panz != 0){

        ausgabeArray(array_1, panz);

        printf("\n\n");

        printf("Welches Element soll bearbeitet werden?\n");

        if((scanf("%d", &k)) && (k <= (*panz))){
            getchar();
            printf("Soll das Element überschrieben [e] oder gelöscht [d] werden?\n");

            if((scanf("%c", &modus)) && ((modus == 'e') || (modus == 'd'))){
                getchar();
                switch(modus){
                    case 'd':{ // d - Löschen
                        k--;
                        deleteElement(array_1, panz, k);
                    }
                    break;
                    case 'e':{ // e - Bearbeiten
                        printf("Zahl eingeben:");
                        if(scanf("%d", &neueZahl)){
                            getchar();
                            k--;
                            insertElement(array_1, k, neueZahl);
                        }else{
                            printf("\nFalsche Eingabe\n");
                        }
                    }
                    break;
                }
            }else{
                printf("\nFalsche Eingabe\n");
            }
        }else{
            printf("\nFalsche Eingabe\n");
        }
    }
    printf("\nAlle Elemente wurden gelöscht.\n");

    return 0;
}