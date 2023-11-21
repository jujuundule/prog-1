//
// mylib.h
// Meine Bibliothek getesteter Funktionen 
// WIEDERVERWENDBARKEIT
//

// *********************************************************************************

// AUSGABEN

// Array ausgeben
void printvek(int v[], int a){
    printf("Vektor: ");
    for(int i = 0; i < a; i++){
        printf("%d ", v[i]);
    }
    printf("\n\n");
}

// *********************************************************************************

// SORTIERALGORITHMEN

// Bubble-Sort Algorithmus
void bubbleSort(int *v, int a){  
    int temp, i, tausch; // Hilfvariable
    
    do{
        a--;
        for(tausch = i = 0; i < a; i++){ // tausch mit 0 initialisieren
            if (v[i] > v[i + 1]){
                temp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = temp;
                tausch = 1;   
            }
        }  
    } while (tausch);
}

// Selection-Sort Algorithmus
void selectionSort(int *v, int a){
    int min, i, h;
    
    while(a > 1) {
        for(i = 1, min = 0; i < a ; i++){
            if (v[i] < v[min]){
                min = i; 
            }
        }
        h = v[0];
        v[0] = v[min];
        v[min] = h;
        v++; // Vektor beginnt bei nächsten Element
        a--; // Vektor ist um 1 Element kürzer
    }
}

void quickSort(int *v, int left, int right){
    int l = left, r = right, h;
    int teiler = v[(l+r)/2];

    do{
        while(v[l] < teiler) l++;
       
        while(teiler < v[r]) r--;
        
        if(l <= r){
            h = v[l];
            v[l] = v[r];
            v[r] = h;
            l++;
            r--;
        }
    }while(l <= r);
    if(left<r) quickSort(v, left, r);
    if(l<right) quickSort(v, l, right);
}
  
// Eigene Sortier Algorithmen

// Aufwärts Sortieren
void sortUp(int *v, int a){ 
    int temp, i, j; // Hilfvariable
    for(i = 0; i < a; i++){
        for(j = i + 1; j < a; j++){
            if (v[i] > v[j]){
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;   
            }
        }
    }  
}

// Abwärts Sortieren
void sortDown(int *v, int a){ 
    int temp, i, j; // Hilfvariable
    for(i = 0; i < a; i++){
        for(j = i + 1; j < a; j++){
            if (v[i] < v[j]){
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;   
            }
        }
    }  
}

// *********************************************************************************

// EINGABEN 

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