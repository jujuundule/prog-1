#include <stdio.h>

int main(){
    int i = 1;

    printf("i = %d\n", -i); // Negation von i

    printf("i = %d\n", ++i); // Preinkrement
    printf("i = %d\n", i); // i wurde inkrementiert

    printf("\n                                                      n");

    printf("i = %d\n", i++); // Postinkrement
    printf("i = %d\n", i); // i wurde inkrementiert

    printf("\n");
    i = 5;
    for(int j = 0; j < 5; j++){
        printf("i = %d\n", i--); // Postdekrement
    }
    printf("\n"); 
    i = 5;
    for(int j = 0; j < 5; j++){
        printf("i = %d\n", --i); // Predekrement
    }

    
}