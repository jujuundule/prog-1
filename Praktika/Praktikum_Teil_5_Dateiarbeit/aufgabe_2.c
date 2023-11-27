#include <stdio.h>
/*
Aufgabe 2: Textausgabe

Erstellen Sie ein Programm, das folgenden Text in eine Datei 
schreibt:

      Menschliches Denken ist vom Irrtum begleitet,
      menschliches Handeln ist an das Unzulängliche gebunden,
      also sind Fehler prinzipiell unvermeidlich.

Der Dateiname ist vom Nutzer zu erfragen. 
Gab es bereits eine Datei mit diesem Namen, dann
1. wird sie überschrieben.
2. wird der Text an die Datei angefügt.

*/

// 1. Datei überschreiben
void textReplace(char dateiname[]){
    // Filepointer
    FILE *fp;
    if((fp = fopen(dateiname, "w")) == NULL){
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;
    }else{
        fprintf(fp, "Menschliches Denken ist vom Irrtum begleitet,\n");
        fprintf(fp, "menschliches Handeln ist an das Unzulängliche gebunden,\n");
        fprintf(fp, "also sind Fehler prinzipiell unvermeidlich.\n");
        fclose(fp);
    }
}

// 2. Text an Datei anfügen
void textAppend(char dateiname[]){
    // Filepointer
    FILE *fp;
    if((fp = fopen(dateiname, "a")) == NULL){
        printf("Datei konnte nicht geoeffnet werden!\n");
        return;
    }else{
        fprintf(fp, "Menschliches Denken ist vom Irrtum begleitet,\n");
        fprintf(fp, "menschliches Handeln ist an das Unzulängliche gebunden,\n");
        fprintf(fp, "also sind Fehler prinzipiell unvermeidlich.\n");
        fclose(fp);
    }
}

int main(){
    char datei_1[50];
    char modus = 0;

    printf("Bitte geben Sie den Dateinamen ein: ");
    if(scanf("%s", datei_1)){ //kein &, weil ein Array schon ein Pointer auf Adresse ist
        printf("Soll die Datei überschrieben werden? (j/n): ");
        if(scanf(" %c", &modus)){
            if(modus == 'j'){
                textReplace(datei_1);
                printf("Datei '%s' wurde überschrieben!\n", datei_1);
            }else if(modus == 'n'){
                textAppend(datei_1);
                printf("Text wurde an Datei '%s' angehangen\n", datei_1);
            }else{
                printf("Fehler bei der Eingabe!\n");
                return 1;
            }
        }
    }else{
        printf("Fehler bei der Eingabe!\n");
        return 1;
    }
    
    return 0;
}
