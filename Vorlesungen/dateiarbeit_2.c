#include <stdio.h>

int main(){

    FILE* fp;
    char Dateiname[50] = "test.txt";
    if((fp = fopen("test.txt", "rt")) == NULL){
            
            printf("Fehler beim Öffnen der Datei!\n");
            return ;

        }else{
            printf("Datei erfolgreich geöffnet!\n");
    }

    int c;
    // Ausgabe der einzelnen Zeichen der Datei
    while((c = fgetc(fp)) != EOF){ // EOF = End of File 
        fputc(c, stdout); // stdout = Filepointer der Standardausgabe
    }

    printf("\n");
    
    
    fclose(fp); // Datei schließen

    return 0;
}