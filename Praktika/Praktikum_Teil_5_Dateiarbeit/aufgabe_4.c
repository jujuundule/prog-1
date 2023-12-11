#include <stdio.h>
#include <string.h>

/*

Aufgabe 4: Umlautersetzung
Ersetzen Sie in einer gegebenen Textdatei die Umlaute 

�, �, � , �, � ,� und � 
durch 
Ae, Ue, Oe, ae, oe, ue und sz. 

Der Dateiname ist als Programmparameter anzugeben 
oder ggf. vom Nutzer abzufragen. Die Zieldatei hat 
den gleichen Namen wie die Originaldatei, die unter 
dem alten Namen, aber mit der Extension ".old" 
abzuspeichern ist.

*/

void replaceUmlaute(){
    char path[256], oldpath[256];
    FILE* fpin, *fpout;
    int c;
    char cc;

    printf("Bitte geben Sie einen Dateinamen an: ");
    scanf("%s", path);
    strcpy(oldpath, path);
    strcat(oldpath, ".old");
    // Benenne Originaldatei um
    rename(path, oldpath);

    // Originaldatei zum Lesen �ffnen
    if((fpin = fopen(oldpath, "rt")) == 0){
        printf("Datei ist nicht lesbar!\n");
        return;
    }
    // Zieldatei zum Schreiben �ffnen
     if((fpout = fopen(path, "wt")) == 0){
        printf("Datei ist nicht erzeugbar!\n");
        return;
    }
    // Zeichenweises Lesen und Schreiben
    while((c = fgetc(fpin)) != EOF){
        cc = (char) c; // Typumwandlung c zu char konvertieren
        switch(cc){
            case '�': fprintf(fpout, "ae"); break;
            case '�': fprintf(fpout, "ue"); break;
            case '�': fprintf(fpout, "oe"); break;
            case '�': fprintf(fpout, "sz"); break;
            case '�': fprintf(fpout, "Ae"); break;
            case '�': fprintf(fpout, "Oe"); break;
            case '�': fprintf(fpout, "Ue"); break;
            // Zeichen unver�ndert �bernehmen
            default: fputc(c, fpout);
        }
    }
    // Schlie�en der Dateien
    fclose(fpin);
    fclose(fpout);
}

int main(){

    replaceUmlaute();
    return 0;
}