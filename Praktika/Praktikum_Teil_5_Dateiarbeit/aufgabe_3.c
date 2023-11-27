#include <stdio.h>

/*
Aufgabe 3: Dateistatistik

Schreiben Sie ein Programm, das in einer gegebenen 
Textdatei die Anzahl der Zeichen, der Worte und Zeilen 
ermittelt und auf dem Bildschirm ausgibt. Als Worte 
zählen beliebige Folgen von druckbaren Zeichen, die 
von mindestens einem Leerzeichen, Punkt, Komma oder 
Semikolon abgeschlossen sind.
*/

// Ausgabe der Dateistatistik
void fileStatistic(char dateiname[]){
    // Filepointer
    FILE *fp;
    if((fp = fopen(dateiname, "rt")) == NULL){
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;
    }else{
        char c;
        int zeichen = 0;
        int woerter = 0;
        int zeilen = 0;
        while((c = fgetc(fp)) != EOF){
            zeichen++;
            if(c == '\n'){
                zeilen++;
            }
            if(c == ' ' || c == '.' || c == ',' || c == ';'){
                woerter++;
            }
        }
        printf("Zeichen: %d\n", zeichen);
        printf("Wörter: %d\n", woerter);
        printf("Zeilen: %d\n", zeilen);
        printf("\n\n", zeilen);
        // Schließen der Datei
        fclose(fp); 
    }
}
int main(){
    char datei_1[50];
    printf("Bitte geben Sie einen Dateinamen an: ");
    if(scanf("%s", datei_1)){
        fileStatistic(datei_1);
    }else{
        printf("Fehler bei der Eingabe!\n");
    }
    return 0;
}