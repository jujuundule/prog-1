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
    printf("Bitte Zahl zwischen 1 und 26 eingeben: ");
    scanf("%i", &nummer);
    if((nummer >= 1)&&(nummer <= 26)){
        printf("\n\nDer %i. Alphabet-Buchstabe ist: %c\n\n", nummer, abc(nummer));
    }else{
        printf("\n\nDie Zahl ist ungültig\n\n");
    }
	
	
	return 0;
}