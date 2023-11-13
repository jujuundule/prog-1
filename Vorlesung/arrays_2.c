#include <stdio.h>
//Arrays Part 2

void printvek(int* v, int anz){
    for(int i = 0; i < anz; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }
}

int main (){
    
    // Ein-dimensionale Arrays
    
    int v[50] = {1,2,3,4,5,6,7,8,};
    int anz = 8;
    
    printvek(v, anz);

    // Mehrdimensionale Arrays

    int num[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    printf("\n%d\n", num[0][2]);
    printf("%d\n", num[1][0]);

    printf("\n");

    return 0;

}