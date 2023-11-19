#include <stdio.h>

/*
Aufgabe 9: Noch einmal Maximum

Modifizieren Sie Ihr Programm aus der vorangegangen Aufgabe derart, 
dass das Programm nach der Ausgabe des Maximums den Benutzer fragt, 
ob weitere Werte zu bearbeiten sind, und ggf. wieder von vorn beginnt. 

Nutzen Sie zur Lösung zunächst die do-while-Schleife, 
dann die while-Schleife 
und zum Schluss die for-Schleife. 

Machen Sie sich die Unterschiede klar!
*/

int main(){
    int a, b = 0;
    char weiter = 'j';
    /*
    // do-while-Schleife
    do{
        // erste Zahl einlesen
        printf("\nGeben Sie eine Zahl ein: ");
        scanf("%d", &a);

        // zweite Zahl einlesen
        printf("Geben Sie eine weitere Zahl ein: ");
        scanf("%d", &b);

        // der bedingte Operator ist eine Abkürzung für eine if-else-Verzweigung
        a > b ? printf("Die erste Zahl ist größer als die zweite Zahl.\n") : a < b ? printf("Die zweite Zahl ist größer als die erste Zahl.\n") : printf("Die beiden Zahlen sind gleich groß.\n");

        // Abfrage, ob weitere Werte zu bearbeiten sind
        printf("\n*********************************************\n\nWollen Sie weitere Werte bearbeiten? (j/n): ");
        scanf(" %c", &weiter);
    } while (weiter == 'j' || weiter == 'J');

    // while-Schleife
    weiter = 'j';

    while(weiter == 'j' || weiter == 'J'){
        // erste Zahl einlesen
        printf("Geben Sie eine Zahl ein: ");
        scanf("%d", &a);

        // zweite Zahl einlesen
        printf("\nGeben Sie eine weitere Zahl ein: ");
        scanf("%d", &b);

        // der bedingte Operator ist eine Abkürzung für eine if-else-Verzweigung
        a > b ? printf("Die erste Zahl ist größer als die zweite Zahl.\n") : a < b ? printf("Die zweite Zahl ist größer als die erste Zahl.\n") : printf("Die beiden Zahlen sind gleich groß.\n");

        // Abfrage, ob weitere Werte zu bearbeiten sind
        printf("\n*********************************************\n\nWollen Sie weitere Werte bearbeiten? (j/n): ");
        scanf(" %c", &weiter);
    }   */

    // for-Schleife
    for(weiter = 'j'; weiter == 'j' || weiter == 'J';){
        // erste Zahl einlesen
        printf("\nGeben Sie eine Zahl ein: ");
        scanf("%d", &a);

        // zweite Zahl einlesen
        printf("Geben Sie eine weitere Zahl ein: ");
        scanf("%d", &b);

        // der bedingte Operator ist eine Abkürzung für eine if-else-Verzweigung
        a > b ? printf("Die erste Zahl ist größer als die zweite Zahl.\n") : a < b ? printf("Die zweite Zahl ist größer als die erste Zahl.\n") : printf("Die beiden Zahlen sind gleich groß.\n");

        // Abfrage, ob weitere Werte zu bearbeiten sind
        printf("\n*********************************************\n\nWollen Sie weitere Werte bearbeiten? (j/n): ");
        scanf(" %c", &weiter);
    }

    
}