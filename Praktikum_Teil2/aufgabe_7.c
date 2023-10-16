#include <stdio.h>
int main() {
    double eingabe, ergebnis;
    
    // Benutzereingabe eines float-Werts
    printf("Geben Sie einen float-Wert ein: ");
    scanf("%lf", &eingabe);

    // Subtraktion von 1
    ergebnis = eingabe - 1;

    // Ausgabe des Ergebnisses
    printf("Ergebnis: %lf\n", ergebnis);

    // Eine Million Mal 1 subtrahieren
    for (int i = 0; i <= 1000000; i++) {
        eingabe -= 1;
    }
    // Ausgabe des Ergebnisses
    printf("Ergebnis nach einer Million Subtraktionen: %lf\n", eingabe);

    return 0;
}
/*
int main() {
    float eingabe, ergebnis;
    
    // Benutzereingabe eines float-Werts
    printf("Geben Sie einen float-Wert ein: ");
    scanf("%f", &eingabe);

    // Subtraktion von 1
    ergebnis = eingabe - 1;

    // Ausgabe des Ergebnisses
    printf("Ergebnis: %f\n", ergebnis);

    // Eine Million Mal 1 subtrahieren
    for (int i = 0; i <= 1000000; i++) {
        eingabe -= 1;
    }
    // Ausgabe des Ergebnisses
    printf("Ergebnis nach einer Million Subtraktionen: %f\n", eingabe);

    return 0;
}
*/