#include <stdio.h>
#include <stdlib.h>

// Juliane Träger | 54004 | s86422 | 23/043/01

#define ROWS 6
#define COLS 7

struct GameMove{
    char board[COLS][ROWS];
    struct GameMove *next;
    struct GameMove *previous;
};

struct Player{
    char name[25];
    char piece; 
}player_1, player_2;
// Initialisiere Spielernamen
struct Player player_1 = {"Spieler 1", 'X'};
struct Player player_2 = {"Spieler 2", 'O'};

//-------------------------------------------- Funktions Deklarationen --------------------------------------------


void printLine(char, int);
void printGameTitle(void); 
void mainMenu(void);
void newGameMenu(void);
void twoPlayersMenu(void);
void namePlayersMenu(void);
void exitGameMenu(void);
void loadGameMenu(void);
void printEndScreen(void);
void UserSelection(char*, int*);
void initializeBoard(void);
void appendMove(struct GameMove**, int);

//-------------------------------------------- Main Funktion --------------------------------------------
int main(){
    
    
    printGameTitle();
    mainMenu();
    
    return 0;
}

//-------------------------------------------- Funktions Definitionen --------------------------------------------

// Linie ausgeben
void printLine(char linetype, int length){
int i;
for(i = 0; i <= length; i++){
    printf("%c", linetype);
}
printf("\n");
}

// ASCII Art

// Game Title
void  printGameTitle(){
    printf("\n  \033[31m_  _\033[33m      ____                  _                _   \n");
    printf(" \033[31m| || |\033[33m    / ___|  ___ __      __(_) _ __   _ __  | |_ \n");
    printf(" \033[31m| || |_\033[33m  | |  _  / _ \\\\ \\ /\\ / /| || '_ \\ | '_ \\ | __|\n");
    printf(" \033[31m|__   _|\033[33m | |_| ||  __/ \\ V  V / | || | | || | | || |_ \n");
    printf("    \033[31m|_|\033[33m    \\____| \\___|  \\_/\\_/  |_||_| |_||_| |_| \\__|\n");
    printf("\033[0m\n");
}

void printGoodbye() {
    printf("   ____                    _  _                   \n");
    printf("  / ___|  ___    ___    __| || |__   _   _   ___  \n");
    printf(" | |  _  / _ \\  / _ \\  / _` || '_ \\ | | | | / _ \\ \n");
    printf(" | |_| || (_) || (_) || (_| || |_) || |_| ||  __/ \n");
    printf("  \\____| \\___/  \\___/  \\__,_||_.__/  \\__, | \\___| \n");
    printf("                                     |___/        \n");
}

// Hauptmenü
void mainMenu(){
    int choice = 0;
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      HAUPTMENÜ\n\n");
        printf("               1 - Neues Spiel starten\n");
        printf("               2 - Spielstand laden\n");
        printf("               3 - Spiel beenden\n\n");
        printLine('=', 55);
        printf("\033[0m");
        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch(choice) {
            case 1:
                newGameMenu();
                break;
            case 2:
                loadGameMenu();
                break;
            case 3:
                printEndScreen();
                break;
            default:
                printf("\033[31mFalsche Eingabe\033[0m\n");
                break;
        } 
    }while(choice < 1 || choice > 3);
}

// Untermenü "Neues Spiel starten"
void newGameMenu(){
    int choice = 0;
    
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      NEUES SPIEL STARTEN\n\n");
        printf("               1 - 2 Spieler\n");
        printf("               2 - Gegen Computer spielen\n");
        printf("               3 - Zurück\n\n");
        printLine('=', 55);
        printf("\033[0m");

        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch (choice){
                case 1:
                    twoPlayersMenu();
                    break;
                case 2:
                    printf("2\n");
                    break;
                case 3:
                    mainMenu();
                    break;
                default:
                    printf("\033[31mFalsche Eingabe\033[0m\n");
                    break;
        }
    }while(choice < 1 || choice > 3);
}

// Untermenü "2 Spieler"
void twoPlayersMenu(){
    int choice = 0;
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      2 SPIELER\n\n");
        printf("               1 - Spiel starten\n");
        printf("               2 - Spieler umbenennen\n");
        printf("               3 - Zurück\n\n");
        printLine('=', 55);
        printf("\033[0m");

        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch (choice){
                case 1:
                    printf("\n\033[32mViel Spaß!\033[0m");
                    initializeBoard();
                    break;
                case 2:
                    namePlayersMenu();
                    break;
                case 3:
                    newGameMenu();
                    break;
                default:
                    printf("\033[31mFalsche Eingabe\033[0m\n");
                    break;
        }
    }while(choice < 1 || choice > 3);
}

// Untermenü "Spieler umbenennen"
void namePlayersMenu(){
    int choice = 0;
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      SPIELER UMBENENNEN\n\n");
        printf("               1 - Spieler 1 umbenennen\n");
        printf("               2 - Spieler 2 umbenennen\n");
        printf("               3 - Zurück\n\n");
        printLine('=', 55);
        printf("\033[0m");

        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch (choice){
                case 1:
                    printf("\nBitte geben Sie einen Namen für Spieler 1 ein: ");
                    if(scanf("%24s", &player_1.name)){
                        printf("Spieler 1 wurde in \033[35m%s\033[0m umbenannt\n", player_1.name);
                    }else{
                        printf("Spieler 1 konnte nicht umbenannt werden");
                    }
                    namePlayersMenu();
                    break;
                case 2:
                    printf("\nBitte geben Sie einen Namen für Spieler 2 ein: ");
                    if(scanf("%24s", &player_2.name)){
                        printf("Spieler 2 wurde in \033[35m%s\033[0m umbenannt\n", player_2.name);
                    }else{
                        printf("Spieler 2 konnte nicht umbenannt werden");
                    }
                    namePlayersMenu();
                    break;
                case 3:
                    twoPlayersMenu();
                    break;
                default:
                    printf("\033[31mFalsche Eingabe\033[0m\n");
                    break;
        }
    }while(choice < 1 || choice > 3);
}


// Untermenü "Spiel beenden"
void exitGameMenu(){
    int choice = 0;
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      SPIEL BEENDEN\n\n");
        printf("               1 - Spielstand speichern\n");
        printf("               2 - Ohne Speichern beenden\n");
        printf("               3 - Spiel wieder aufnehmen\n\n");
        printLine('=', 55);
        printf("\033[0m");

        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch (choice){
                case 1:
                    printf("TODO: Spielstand speichern Funktion\n");
                    break;
                case 2:
                    mainMenu();
                    break;
                case 3:
                    initializeBoard();
                    break;
                default:
                    printf("\033[31mFalsche Eingabe\033[0m\n");
                    break;
        }
    }while(choice < 1 || choice > 3);
}

// Untermenü "Spiel beenden"
void loadGameMenu(){
    int choice = 0;
    do{
        printf("\033[36m");
        printLine('=', 55);
        printf("\n                      SPIELSTAND LADEN\n\n");
        printf("               1 - 'Dateiname' - DDMMYY\n");
        printf("               2 - 'Dateiname' - DDMMYY\n");
        printf("               3 - Zurück\n\n");
        printLine('=', 55);
        printf("\033[0m");

        UserSelection("Bitte wählen Sie eine Option: ", &choice);

        switch (choice){
                case 1:
                    printf("TODO: Spielstand laden Funktion\n");
                    break;
                case 2:
                    printf("TODO: Spielstand laden Funktion\n");
                    break;
                case 3:
                    mainMenu();
                    break;
                default:
                    printf("\033[31mFalsche Eingabe\033[0m\n");
                    break;
        }
    }while(choice < 1 || choice > 3);
}

// EndScreen

void printEndScreen(){
    printGoodbye();
    printf("\n\033[31m");
    printLine('=', 55);
    printf("\n                      SPIEL BEENDET\n\n");
    printLine('=', 55);
    printf("\033[0m\n");
}

// Nutzereingaben

void UserSelection(char* instruction, int* input){
    printf("\n%s", instruction);
    scanf("%d", input);
}

// Spielfeld initialsieren

void initializeBoard(){
    int i, j, choice;
    printf("\n\n");
    // Zeilen
    printLine('-', 28);
    for(i = 0; i < ROWS; i++){
        // Spalten
        printf("|");
        for (j = 0; j < COLS; j++){
            printf("   |");
        }
        printf("\n");
        printLine('-', 28);
    }
    printf("\033[36m");
    for (i = 0; i < COLS; i++){
        printf("  %i ", i+1);
    }
    printf("\n\n8 - Spiel beenden\n9 - Zurück\033[0m\n\n");

    printf("\033[35m%s\033[0m:", player_1.name);
    UserSelection("Bitte wählen Sie eine Spalte aus: ", &choice);

    switch (choice)
    {
    case 8:
        exitGameMenu();
        break;
    case 9:
        printf("TODO: Zurück Funktion\n");
        initializeBoard();
    break;
    default:
        break;
    }
}

// Funktion zum Hinzufügen eines neuen Knotens am Ende der Liste
void appendMove(struct GameMove** head, int col){
    int i;
    // Neuen Knoten erstellen
    struct GameMove* newGameMove = (struct GameMove*)malloc(sizeof(struct GameMove));
    // Spielfeld aktualisieren
    for (i = ROWS - 1; i >= 0; i--) {
            if (newGameMove->board[i][col] == ' ') {
                newGameMove->board[i][col] = 'X';
            }
    }
    newGameMove->next = NULL;
    // Wenn die Liste leer ist, wird der neue Knoten der Kopf der Liste
    if (*head == NULL) {
        newGameMove->previous = NULL;
        *head = newGameMove;
        return;
    }
    // Andernfalls zum Ende der Liste gehen
    struct GameMove* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    // Den neuen Knoten an das Ende der Liste anhängen
    last->next = newGameMove;
    newGameMove->previous = last;
}

void printBoard(struct GameMove* ){

}

