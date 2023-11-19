#include <stdio.h>

int main(){

    FILE* fp;
    char Dateiname[50];
    scanf("%s", Dateiname); // Der Name des Arrays ist bereits der Zeiger auf das 0. Element
   
    if((fp = fopen("test.txt", "rt")) == NULL){
        
        printf("Fehler beim Öffnen der Datei!\n");
        return ;

    }else{
        printf("Datei erfolgreich geöffnet!\n");
    }

    //fseek(fp, 0, 2); // Position im File setzen | 2 = Ende des Files
    int i = ftell(fp); // Aktuelle Position im File
    printf("Ich bin an der Stelle: %d(%c)\n", i, fgetc(fp)); // Aktuelle Position im File
    
    
    fclose(fp); // Datei schließen

    return 0;
}