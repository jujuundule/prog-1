
#include <stdio.h>


void version_1(){
    printf("1\t2\t3\t4\n");
    printf("2\t4\t6\t8\n");
    printf("3\t6\t9\t12\n");

}


void version_2(){
    for(int  i=1; i<=3; i++){
        printf("%i %i %i %i\n",i*1, i*2, i*3, i*4);
    }
}


int calcNumb(int i){

    printf("%i %i %i %i\n",i*1, i*2, i*3, i*4);
    return ++i;
}

void version_3(){
    for(int  i=1; i<=3; i++){
        calcNumb(i);
    }
}

int main(){
    // version_1();
    // version_2();
    version_3();
}