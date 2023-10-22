#include <stdio.h>
int main(){

    int v[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int i;
    int j;
    
    for(i=1; i>=0; i--) {
        for(j=3; j>=0; j--) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}