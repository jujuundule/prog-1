#include <stdio.h>
/*
Erweitern Sie das Programm aus Aufgabe 4 
indem Sie sich zusätzlich die Gleitkommakonstante 
pi mit dem Wert 3.1415926 definieren, jeden Wert 
in der Tabelle vor seiner Ausgabe mit pi 
multiplizieren und das Ergebnis als Gleitkommazahl 
ebenfalls mit Tabulatoren und 3 Ausgabeanweisungen 
tabellarisch darstellen. Auch hier ist eine möglichst 
einfache Lösung anzustreben.
*/
int main(){

    const float pi = 3.1415926;

    for(int  i=1; i<=3; i++){
        printf("%f %f %f %f\n",i*pi, i*pi, i*pi, i*pi);
    }
}