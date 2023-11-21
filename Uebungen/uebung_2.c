#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotheken/mylib.h" //Eigene Bibliothek

// Sortieralgorithmen

int main(){
    int anz = 10;
    int vek_1[10] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
    int vek_2[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vek_3[10] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
    int vek_4[10] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1};

    printvek(vek_1, anz);
    bubbleSort(vek_1, anz);
    printvek(vek_1, anz);
    
    printf("***********************\n\n");

    printvek(vek_2, anz);
    selectionSort(vek_2, anz);
    printvek(vek_2, anz);

    printf("***********************\n\n");
    
    printvek(vek_3, anz);
    quickSort(vek_3, 0, anz-1);
    printvek(vek_3, anz);
    
    printf("***********************\n\n");
    
    printvek(vek_4, anz);
    sortUp(vek_4, anz);
    printvek(vek_4, anz);
    sortDown(vek_4, anz);
    printvek(vek_4, anz);
    return 0;
}