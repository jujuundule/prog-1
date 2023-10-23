#include <stdio.h>

/*
Aufgabe 10: Arithmetisches Mittel

Erstellen Sie ein Programm, das zyklisch in beliebiger Anzahl int-Werte einliest, 
dabei intern das arithmetische Mittel bildet und dieses zum Schluss ausgibt. 
Sie können den Nutzer am Anfang ihres Programms nach der Anzahl der einzulesenden 
Zahlen fragen oder die Eingabe mit einem Buchstaben (z.B. ‘q’) beenden lassen.
*/

int main (){
    int anzahl, summe, i = 0;
    double mittelwert = 0;
    
    printf("Anzahl der Zahlen: ");
    scanf("%d", &anzahl);

        if(anzahl>0){
            int zahlen[anzahl];

            for(i=0; i<anzahl; i++){
                printf("Geben Sie die %d. Zahl ein: ", i);
                scanf("%d", &zahlen[i]);
                summe += zahlen[i];
            }
            
            mittelwert = (float) summe/anzahl;
            printf("\n\nMittelwert: %.2lf\n\n", mittelwert);
        
        }else{
            printf("\n\nDas Ergebnis ist 0.\n\n");
        }
}