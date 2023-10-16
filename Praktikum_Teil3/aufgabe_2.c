#include <stdio.h>

/*
Aufgabe 2: Kreiszylinder
In Analogie zur vorangegangen Würfel-Aufgabe ist ein Programm 
für gerade Kreiszylinder zu schreiben, das bei gegebener (einzugebender) 
Höhe und Durchmesser

die Mantelfläche (=pi*d*h),
Oberfläche (=0.5pi*d*(d+2h)) und
das Volumen (=0.25*pi*d*d*h) 

berechnet und ausgibt.
*/

int main(){
    float hoeheKreiszylinder, durchmesserKreiszylinder, mantelflaecheKreiszylinder, oberflaecheKreiszylinder, volumenKreiszylinder = 0;
    const float pi = 3.1415926;

//Werte eingeben:
    printf("Kreiszylinder berechnen:\n\n");
    printf("Geben Sie die Höhe ein: ");
    scanf("%f", &hoeheKreiszylinder);
    printf("Geben Sie den Durchmesser ein: ");
    scanf("%f", &durchmesserKreiszylinder);

//Ergebnisse berechnen:
    mantelflaecheKreiszylinder = pi * durchmesserKreiszylinder * hoeheKreiszylinder;
    oberflaecheKreiszylinder = 0.5 * pi * durchmesserKreiszylinder * (durchmesserKreiszylinder + 2 * hoeheKreiszylinder);
    volumenKreiszylinder = 0.25 * pi * durchmesserKreiszylinder * durchmesserKreiszylinder * hoeheKreiszylinder;

//Ausgabe der Ergebnisse:
    printf("Mantelfläche: %f cm²\n", mantelflaecheKreiszylinder);
    printf("Oberfläche: %f cm²\n", oberflaecheKreiszylinder);
    printf("Volumen: %f cm³\n", volumenKreiszylinder);

}