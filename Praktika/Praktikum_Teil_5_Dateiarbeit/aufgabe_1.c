#include <stdio.h>
/*
Aufgabe 1: Dateien lesen

Das von Ihnen zu erstellende Programm soll den Inhalt einer 
gegebenen Textdatei auf dem Bildschirm zur Anzeige bringen. 
Fertigen Sie hierzu zwei Lösungsvarianten an: 
(a) zeichenweises lesen, 
(b) zeilenweises lesen.
*/

// a) zeichenweises lesen   
void zeichenweisesLesen(char dateiname[]){
    // Filepointer
    FILE *fp;
    if((fp = fopen(dateiname, "rt")) == NULL){
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;
    }else{
        char c;
        while((c = fgetc(fp)) != EOF){
            printf("%c", c);
        }
        // Schließen der Datei
        fclose(fp); 
    }
}

// b) zeilenweises lesen
void zeilenweisesLesen(char dateiname[]){
    // Filepointer
    FILE *fp;
    if((fp = fopen(dateiname, "rt")) == NULL){
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;
    }else{
        char zeile[100];
        while(fgets(zeile, 100, fp) != NULL){
            printf("%s", zeile);
        }
        fclose(fp);
    }
}

int main(){
    char datei_1[50] = "text.txt";
    zeichenweisesLesen(datei_1);
    printf("\n\n"); 
    zeichenweisesLesen(datei_1);

    return 0;
}