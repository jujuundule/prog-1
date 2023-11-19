#include <stdio.h>

int main(){
    // Filepointer
    FILE *fp, *fp_2;    
    
    // Dateiname
    char Dateiname[50] = "test.txt";

    // Datei mit Lesezugriff öffnen
    if((fp = fopen("test.txt", "rt")) == NULL){
            
            printf("Fehler beim Öffnen der Datei!\n");
            return ;

        }else{
            printf("Datei erfolgreich geöffnet!\n");
    }

    // Datei mit Schreibzugriff öffnen
    if((fp_2 = fopen("test.txt", "wt")) == NULL){
            
            printf("Fehler beim Öffnen der Datei!\n");
            return ;

        }else{
            printf("Datei erfolgreich geöffnet!\n");
    }

    // Zeichen in Datei schreiben
    for(int i = 0; i < 26; i++){
        int c = i+65;
        fputc(c, fp_2);
    }

    // Dateien schließen
    fclose(fp);
    fclose(fp_2);

}