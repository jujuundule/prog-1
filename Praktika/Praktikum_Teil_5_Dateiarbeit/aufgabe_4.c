#include <stdio.h>

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

int main(){
    char datei_1[50];

    printf("Bitte geben Sie einen Dateinamen an: ", datei_1);
    if (scanf("%s", datei_1)){
        printf("Dateiname: %s\n", datei_1);
    }else{
        printf("Fehler bei der Eingabe!\n");
    }
    return 0;
}