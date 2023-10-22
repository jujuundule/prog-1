#include <stdio.h>

/*
Aufgabe 7: Bitoperatoren

Erstellen Sie ein kurzes Programm, das folgende Tabelle erstellt.

z hex num Bit     z hex num Bit
	----------------------------------------------
	A 41 65 1000001 | a 61  97 1100001 |
	B 42 66 1000010 | b 62  98 1100010 |
	C 43 67 1000011 | c 63  99 1100011 |
	D 44 68 1000100 | d 64 100 1100100 |
  	E 45 69 1000101 | e 65 101 1100101 |
	F 46 70 1000110 | f 66 102 1100110 |
	G 47 71 1000111 | g 67 103 1100111 |
	H 48 72 1001000 | h 68 104 1101000 |
	I 49 73 1001001 | i 69 105 1101001 |
	J 4a 74 1001010 | j 6a 106 1101010 |
	K 4b 75 1001011 | k 6b 107 1101011 |
	L 4c 76 1001100 | l 6c 108 1101100 |
	M 4d 77 1001101 | m 6d 109 1101101 |
	N 4e 78 1001110 | n 6e 110 1101110 |
	O 4f 79 1001111 | o 6f 111 1101111 |
	P 50 80 1010000 | p 70 112 1110000 |
	Q 51 81 1010001 | q 71 113 1110001 |
	R 52 82 1010010 | r 72 114 1110010 |
	S 53 83 1010011 | s 73 115 1110011 |
	T 54 84 1010100 | t 74 116 1110100 |
	U 55 85 1010101 | u 75 117 1110101 |
	V 56 86 1010110 | v 76 118 1110110 |
	W 57 87 1010111 | w 77 119 1110111 |
	X 58 88 1011000 | x 78 120 1111000 |
	Y 59 89 1011001 | y 79 121 1111001 |
	Z 5a 90 1011010 | z 7a 122 1111010 |
*/

int decimalToBinary(int n);

int main (){
    int i, j;

    printf("z\thex\tnum\tBit\t\tz\thex\tnum\tBit\n");
    printf("--------------------------------------------------------------------------\n");
    
    // Diese Schleife gibt die Tabelle aus:
    for(i=65; i<=90; i++){
        // der Wert i wird in jeder Zeile erhöht
        printf("%c\t%X\t%3d\t%3d\t|\t%c\t%X\t%3d\t%d\t|\n", i, i, i, decimalToBinary(i), i+32, i+32, i+32, decimalToBinary(i+32));
    }
    
    printf("\n");

    return 0;
}
// Diese Funktion wandelt eine Dezimalzahl in eine Binärzahl um:
int decimalToBinary(int n){
    int remainder;
    int binary = 0, i = 1;

    while(n != 0){
        remainder = n%2;
        n = n/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    return binary;
}





