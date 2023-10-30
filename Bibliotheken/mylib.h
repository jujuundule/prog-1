//
// mylib.h
// Meine Bibliothek getesteter Funktionen 
// WIEDERVERWENDBARKEIT
//


// DAU-sichere Eingabe:

int DAUEingabe(char* prompt, int min, int max, int toleranz);       //char* = Zeichenkette | Deklaration

int DAUEingabe(char* prompt, int min, int max, int toleranz){       // Definition
    int i;
   
    if (toleranz == 0){
        printf("Du DAU\n");
        exit(1);
    }

    printf("%s\n", prompt);           // %s als Platzhalter für eine Zeichenkette
                
    while (fgetc(stdin) != '\n');  // Leert den Eingabepuffer | !!FUNKTIONIERT NICHT!!
           
    if ( scanf("%d", &i) != 1){
        printf(">> Bitte eine Zahl eingeben! <<\n");
        i = DAUEingabe(prompt, min, max, toleranz-1);   // Teilproblem: DAU sichere Eingabe mit Toleranz-1
    }
    
    if ( (i<min) || (i>max) ){
        printf(">> Wertebereich [%d, %d] beachten! <<\n", min, max);
        i = DAUEingabe(prompt, min, max, toleranz-1);   // Teilproblem: DAU sichere Eingabe mit Toleranz-1
    }

    return i;
}