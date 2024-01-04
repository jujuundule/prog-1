#include <stdio.h>
#include <stdlib.h>

// Dynamische Speicherverwaltung

int main(){
    int anz, *vek;
    
    do{
        printf("Wie viele Werte brauchst du heute? ");
        scanf("%d", &anz);

        // Speicherplatz reservieren
        
        if((vek = (int*)malloc(anz * sizeof(int))) == NULL){
            printf("Speicherplatz konnte nicht reserviert werden!\n");
            exit(1);
        }

        for(int i = 0; i < anz; i++){
        vek[i] = i;
        }

        for(int i = 0; i < anz; i++){
            printf("%d\n", vek[i]);
        }
        // Speicherplatz freigeben
         free(vek);

    }while(anz != 0);
    

    return 0;
}