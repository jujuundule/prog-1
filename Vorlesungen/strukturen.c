#include <stdio.h>

struct Datum{
        int tag;
        char monat[19];
        int jahr;
    };
struct buch{
    long buchnummer;
    char autor[20];
    char titel[30];
    unsigned int jahr;
    char verlag[20];
};

// DATE ist ein Alias für struct Datum
typedef struct Datum DATE; 

void printdatum(const DATE *pd){
    // "->"-Operator
    printf("Datum: %d. %s %d\n", pd->tag, pd->monat, pd->jahr);
    // "*"-Operator
    printf("Datum: %d. %s %d\n", (*pd).tag, (*pd).monat, (*pd).jahr);
}

int main(){

    struct Datum d1, d2, d3;

    struct Datum geburtstag = {6, "August", 1997};
    struct Datum heute = {29, "November", 2023};

    // Speicherbedarf in Byte
    int speicher = sizeof(struct Datum); 

    printf("Speicherbedarf: %d\n", speicher);
    printf("Heute ist der %d. %s %d\n", heute.tag, heute.monat, heute.jahr);
    printf("Geburtstag: %d. %s %d\n", geburtstag.tag, geburtstag.monat, geburtstag.jahr);
   
    // Zuweisung von Strukturen 
    heute = geburtstag;
    
    printdatum(&heute);

    struct buch katalog[200] = {
        {1234, "Lusitg", "C is funny", 1989, "Addison Wesley"},
        {1235, "Lusitg", "C++ is funny", 1989, "Addison Wesley"},
        {1236, "Lusitg", "C is funny", 1989, "Addison Wesley"},
        {1237, "Lusitg", "C is funny", 1989, "Addison Wesley"},
        {1238, "Lusitg", "C is funny", 1989, "Addison Wesley"}
    };
    
    printf("Buch: %s\n", katalog[0].titel);

    printf("Buch: %s\n", (katalog+1)->titel);
    return 0;
}