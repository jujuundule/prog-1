#include<stdio.h>
#include<stdlib.h>
/*
Erstellen Sie ein C-Programm, das nacheinander 
die folgenden Zeichenkettenkonstanten auf dem 
Bildschirm ausgibt:
"Eine Meinungsumfrage unter Löwen ergab:
Die Mehrheit lehnt den Käfig ab,
wünscht jedoch eine geregelte Verpflegung!"
*/
int main() {
	system("chcp 1252 > NIL");
	printf("Eine Meinungsumfrage unter Löwen ergab:\nDie Mehrheit lehnt den Käfig ab,\nwünscht jedoch eine geregelte Verpflegung!\n");
	return 0;
}