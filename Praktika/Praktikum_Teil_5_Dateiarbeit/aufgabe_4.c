#include <stdio.h>
#include <string.h>

/*

Aufgabe 4: Umlautersetzung
Ersetzen Sie in einer gegebenen Textdatei die Umlaute 

Ä, Ü, Ö , ä, ü ,ö und ß 
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

    // Originaldatei zum Lesen öffnen
    if((fpin = fopen(oldpath, "rt")) == 0){
        printf("Datei ist nicht lesbar!\n");
        return;
    }
    // Zieldatei zum Schreiben öffnen
     if((fpout = fopen(path, "wt")) == 0){
        printf("Datei ist nicht erzeugbar!\n");
        return;
    }
    // Zeichenweises Lesen und Schreiben
    while((c = fgetc(fpin)) != EOF){
        cc = (char) c; // Typumwandlung c zu char konvertieren
        switch(cc){
            case 'ä': fprintf(fpout, "ae"); break;
            case 'ü': fprintf(fpout, "ue"); break;
            case 'ö': fprintf(fpout, "oe"); break;
            case 'ß': fprintf(fpout, "sz"); break;
            case 'Ä': fprintf(fpout, "Ae"); break;
            case 'Ö': fprintf(fpout, "Oe"); break;
            case 'Ü': fprintf(fpout, "Ue"); break;
            // Zeichen unverändert übernehmen
            default: fputc(c, fpout);
        }
    }
    // Schließen der Dateien
    fclose(fpin);
    fclose(fpout);
}

int main(){

    replaceUmlaute();
    return 0;
}