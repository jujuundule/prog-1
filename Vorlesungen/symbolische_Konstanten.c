#include <stdio.h>

int main(){
    
    #define QUADRAT(a) ((a)*(a))

    int x = 5;
    int z;
    z = QUADRAT(++x);
    
    printf("Quadrat von 10: %d\n", z);
    
    int c, c1=9, c2=5;
    float f1=9.f, f2=5.f, f, f3;

    c=c1/c2;
    f= (float) c1/ (float) c2;
    f3=c1/c2;
    printf("f = %f\n", f);
    printf("c = %d\n", c);
    printf("f3 = %f\n", f3);
    return 0;
}