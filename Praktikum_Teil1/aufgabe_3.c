#include <stdio.h>
/*
Definieren Sie den Tag, den Monat und das Jahr 
Ihres Geburtstages als "konstante Variablen" 
vom Typ int und geben Sie den Satz:
"Ich wurde am tt.mm.jjjj geboren."
auf dem Bildschirm aus.
*/
int main(){
    const int day = 6, month = 8, year = 1997;
    // Speicher sparen
    // const char tag = 13, monat = 9;
    // const short jahr = 2007;
    printf("Ich wurde am %02d.%02d.%d geboren\n", day, month, year);
}