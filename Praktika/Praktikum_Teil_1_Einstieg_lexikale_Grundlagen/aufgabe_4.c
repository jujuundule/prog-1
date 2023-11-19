
#include <stdio.h>
/*
Schreiben Sie ein Programm, dass mit 
Hilfe von Tabulatoren, möglicht wenigen 
Variablen :-) und 3 Ausgabeanweisungen 
folgende Tabelle auf dem Bildschirm ausgibt:

    1 2 3 4
    2 4 6 8
	3 6 9 12
*/

void version_1();
void version_2();
void version_3();
int calcNumb(int i);

int main(){
    // version_1();
    // version_2();
    version_3();
}

void version_1(){
    /*
    Version 1.0: Nutzen Sie 3 printf-Anweisungen 
    und konstante Zahlenwerte für die Ausgabe.
    */
    printf("1\t2\t3\t4\n");
    printf("2\t4\t6\t8\n");
    printf("3\t6\t9\t12\n");

}


void version_2(){
    /*
    Version 2.0: Nutzen Sie eine Variable für 
    die zu berechnenden Zahlenwerte.
    */

   int a = 1;
   printf("%d %d %d %d\n",i, i*2, i*3, i*4); a = a + 1;
   printf("%d %d %d %d\n",i, i*2, i*3, i*4); a = a + 1;
   printf("%d %d %d %d\n",i, i*2, i*3, i*4);
}

    /*
    Version 3.0: Schreiben Sie eine Funktion, die 
    zur Ausgabe einer Zeile dient und als Parameter 
    die Zeilennummer übergeben bekommt. Der return-Wert 
    ist die um 1 erhöhte Zeilennummer.
    */

void zeile(int zn){
    printf("%d\t%d\t%d\t%d", zn, zn * 2, zn * 3, zn * 4);
}

void version_3(){
    
   void zeile(1);
   void zeile(2);
   void zeile(3);
}

//*************************************************************
void version_4(){
    for(int  i=1; i<=3; i++){
        printf("%i %i %i %i\n",i*1, i*2, i*3, i*4);
    }
}


