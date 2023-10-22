/* 	
	Standpreise: 1. Meter: 5 Euro, 2. Meter: 4 Euro,
	3. Meter: 3 Euro, 4. Meter: 2 Euro, 5. Meter: 1 Euro
*/

#include <stdio.h>

int main(){

    int meter = 3;
    int preis = 0;

    switch(meter){
    case 5:  preis += 1;
         printf("5. Meter: 1 Euro \n");
    case 4:  preis += 2;
        printf("4. Meter: 2 Euro \n");
    case 3:  preis += 3;
         printf("3. Meter: 3 Euro \n");
    case 2:  preis += 4;
         printf("2. Meter: 4 Euro \n");  
    case 1:	 preis += 5;
         printf("1. Meter: 5 Euro \n");
         printf("Gesamtpreis: %d\n", preis);
         break;
    default: printf("Falsche