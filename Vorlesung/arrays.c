#include <stdio.h>
#include <string.h>

int main (){
    int v[100] = {0};
    int anz = 3;
    
    v[0] = 99;
    v[1] = 999;

    for(int i = 0; i < anz; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n");

    v[anz++] = 99;
    v[anz++] = 999;


    for(int i = 0; i < anz; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n");

/*
    printf("\nBitte die Umsätze der letzten Woche eingeben:\n");
    
    for(int i = 1; i <= 7; i++){
        printf("Tag %d: ", i);
        scanf("%d", &v[i]);
    } */

    printf("\n");

    char v2[100] = "Hallo";
    printf("%d\n", strlen(v2));
    printf("%s\n", v2);
    strcpy(v2, "Welt");
    printf("%s\n", v2);
    printf("\n");

}