#include<stdio.h>

/*
Aufgabe 4:
Schreiben Sie ein Programm, dass den n-ten Buchstaben
des Alphabetes auf dem Bildschirm ausgibt, nachdem es 
Sie nach der Zahl n gefragt hat.
*/

char abc(int nummer) {
    return (64 + nummer);
}

int main() {
    int nummer = 0;
    printf("Alphabet-Buchstaben: ");
    scanf("%i", &nummer);

	printf("Der %i. Alphabet-Buchstabe ist: %c\n", nummer, abc(nummer));
	
	return 0;
}