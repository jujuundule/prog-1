#include <stdio.h>

/*
Aufgabe 10: Arithmetisches Mittel

Erstellen Sie ein Programm, das zyklisch in beliebiger Anzahl int-Werte einliest, 
dabei intern das arithmetische Mittel bildet und dieses zum Schluss ausgibt. 
Sie können den Nutzer am Anfang ihres Programms nach der Anzahl der einzulesenden 
Zahlen fragen oder die Eingabe mit einem Buchstaben (z.B. ‘q’) beenden lassen.
*/

int main (){
    int anzahl, mittelwert, summe, i = 0;
    
    printf("Anzahl der Zahlen: ");
    scanf("%d", &anzahl);

        if(anzahl>0){
            int zahlen[anzahl];

            for(i=0; i<anzahl; i++){
                printf("Geben Sie die %d. Zahl ein: ", i);
                scanf("%d", &zahlen[i]);
                summe += zahlen[i];
            }
            
            mittelwert = summe/anzahl;
            printf("Mittelwert: %d\n", mittelwert);
        
        }else{
            printf("Das Ergebnis ist 0.\n");
        }
}