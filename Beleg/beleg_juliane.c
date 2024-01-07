// Juliane Träger | 54004 | s86422 | 23/043/01
#include <stdio.h>
#include <stdlib.h>

// ANSI Escape-Sequenzen für die formatierte Ausgabe in der Konsole

// Text Attribute
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"
#define HIDDEN      "\033[8m"

// Text Color
#define F_BLACK     "\033[30m"
#define F_RED       "\033[31m"
#define F_GREEN     "\033[32m"
#define F_YELLOW    "\033[33m"
#define F_BLUE      "\033[34m"
#define F_MAGENTA   "\033[35m"
#define F_CYAN      "\033[36m"
#define F_WHITE     "\033[37m"

// Background Color
#define B_BLACK     "\033[40m"
#define B_RED       "\033[41m"
#define B_GREEN     "\033[42m"
#define B_YELLOW    "\033[43m"
#define B_BLUE      "\033[44m"
#define B_MAGENTA   "\033[45m"
#define B_CYAN      "\033[46m"
#define B_WHITE     "\033[47m"

// Spielfeld 

#define ROWS 6
#define COLS 7
#define MAXGAMEMOVES 42

char board[ROWS][COLS];

// Spielzüge

struct GameMove{
    char board[ROWS][COLS];
    struct GameMove *next;
    struct GameMove *previous;
};

struct Player{
    char name[25];
    char piece; 
}player_1, player_2;

// Initialisiere Spieler
struct Player player_1 = {"Spieler 1", 'X'};
struct Player player_2 = {"Spieler 2", 'O'};

//-------------------------------------------- Funktions Deklarationen --------------------------------------------


void printLine(char, int);
void printGameTitle(void);
void printTrophy(void);
void printGoodbye(void); 

void mainMenu(void);
void newGameMenu(void);
void twoPlayersMenu(void);
void namePlayersMenu(void);
void exitGameMenu(void);
void loadGameMenu(void);
void gameMenu(int, int);

void startGame(void);

void printEndScreen(void);

int getUserInput(char*, int, int);

void initializeBoard(void);
void printBoard(void);
int dropPiece(int, int);
int checkwin(int);
void announceWinner(int);



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

// 4 Gewinnt
void  printGameTitle(){
    printf("\n  %s_  _%s      ____                  _                _   \n", F_RED, F_YELLOW);
    printf(" %s| || |%s    / ___|  ___ __      __(_) _ __   _ __  | |_ \n", F_RED, F_YELLOW);
    printf(" %s| || |_%s  | |  _  / _ \\\\ \\ /\\ / /| || '_ \\ | '_ \\ | __|\n", F_RED, F_YELLOW);
    printf(" %s|__   _|%s | |_| ||  __/ \\ V  V / | || | | || | | || |_ \n", F_RED, F_YELLOW);
    printf("    %s|_|%s    \\____| \\___|  \\_/\\_/  |_||_| |_||_| |_| \\__|\n", F_RED, F_YELLOW);
    printf("%s\n", RESET);
}

// Trophy
void printTrophy(){
printf("	              ___________\n");
printf("	             '._==_==_=_.'\n");
printf("                     .-\\:      /-.\n");
printf("                    | (|:.     |) |\n");
printf("                     '-|:.     |-'\n");
printf("                       \\::.    /\n");
printf("                        '::. .'\n");
printf("                          ) (\n");
printf("                        _.' '._\n");
printf("                       '''''''''\n");
}
// Goodbye
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
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                       %sHAUPTMENÜ%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Neues Spiel starten\n");
    printf("                 2 - Spielstand laden\n");
    printf("                 3 - Spiel beenden\n\n");
    printLine('=', 55);
    printf("%s", RESET);
    
    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

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
            printf("%sFalsche Eingabe%s\n", F_RED, RESET);
            break;
    }
}

// Untermenü "Neues Spiel starten"
void newGameMenu(){
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                  %sNEUES SPIEL STARTEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - 2 Spieler\n");
    printf("                 2 - Gegen Computer spielen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', 55);
    printf("%s", RESET);
    
    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                twoPlayersMenu();
                break;
            case 2:
                printf("TODO: Menü 'Gegen Computer spielen'\n");
                break;
            case 3:
                mainMenu();
                break;
            default:
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// Untermenü "2 Spieler"
void twoPlayersMenu(){
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                        %s2 SPIELER%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spiel starten\n");
    printf("                 2 - Spieler umbenennen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', 55);
    printf("%s", RESET);
    
    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                startGame();
                break;
            case 2:
                namePlayersMenu();
                break;
            case 3:
                newGameMenu();
                break;
            default:
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// Untermenü "Spieler umbenennen"
void namePlayersMenu(){
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                    %sSPIELER UMBENENNEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spieler 1 umbenennen\n");
    printf("                 2 - Spieler 2 umbenennen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', 55);
    printf("%s", RESET);
    
    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                printf("\nBitte geben Sie einen Namen für Spieler 1 ein: ");
                if(scanf("%24s", &player_1.name)){
                    printf("Spieler 1 wurde in %s%s%s umbenannt\n", F_MAGENTA, player_1.name, RESET);
                }else{
                    printf("Spieler 1 konnte nicht umbenannt werden");
                }
                namePlayersMenu();
                break;
            case 2:
                printf("\nBitte geben Sie einen Namen für Spieler 2 ein: ");
                if(scanf("%24s", &player_2.name)){
                    printf("Spieler 2 wurde in %s%s%s umbenannt\n", F_MAGENTA, player_2.name, RESET);
                }else{
                    printf("Spieler 2 konnte nicht umbenannt werden");
                }
                namePlayersMenu();
                break;
            case 3:
                twoPlayersMenu();
                break;
            default:
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// Untermenü "Spiel beenden"
void exitGameMenu(){
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                      %sSPIEL BEENDEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spielstand speichern\n");
    printf("                 2 - Ohne Speichern beenden\n");
    printf("                 3 - Spiel wieder aufnehmen\n\n");
    printLine('=', 55);
    printf("%s", RESET);

    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

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
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// Untermenü "Spiel beenden"
void loadGameMenu(){
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', 55);
    printf("\n                    %sSPIELSTAND LADEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - 'Dateiname' - DDMMYY\n");
    printf("                 2 - 'Dateiname' - DDMMYY\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', 55);
    printf("%s", RESET);

    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

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
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// Untermenü Game Menü
void gameMenu(const int game_move_number, const int game_move_status) {
    // Menü ausgeben
    printf("%s", F_CYAN);
    for (int i = 0; i < COLS; i++) {
        printf("  %d ", i + 1);
    }
    printf("\n\n8 - Spiel beenden\n9 - Zurück" RESET "\n\n");
    printf("%sSpielzug: %d von %d%s\n\n", F_YELLOW, game_move_number, MAXGAMEMOVES, RESET);

    const char* currentPlayer = (game_move_number % 2 != 0) ? player_1.name : player_2.name;
    printf("%s%s%s ", F_MAGENTA, currentPlayer, RESET);

    if (game_move_status == 0) {
        printf("%sDie Zeile ist voll%s\n", F_RED, RESET);
    }
}

// EndScreen

void printEndScreen(){
    printGoodbye();
    printf("\n%s", F_RED);
    printLine('=', 55);
    printf("\n                      SPIEL BEENDET\n\n");
    printLine('=', 55);
    printf("%s\n", RESET);
}

int getUserInput(char *instruction, int min, int max) {
    int input;

    // Aufforderung an den Nutzer ausgeben
    printf("%s [%d-%d]: ", instruction, min, max);

    // Schleife wird durchlaufen, solange die Nutzereingabe falsch ist
    while (1) {
        // Eingabe überprüfen
        if (scanf("%d", &input) != 1 || input < min || input > max) {
            // Fehlerhafte Eingabe behandeln
            printf("%sFalsche Eingabe%s\n", F_RED, RESET);
            printf("%s: ", instruction);
            // Den Eingabepuffer leeren
            while (getchar() != '\n');
        } else {
            // Gültige Eingabe, die Schleife verlassen
            break;
        }
    }
    return input;
}

// Spiel starten

void startGame(){
    // Initialisiere Variablen
    int choice;
    int game_move_number, winner = 0;
    int currentPlayer, game_move_status = 1;
    
    printf("\n%sViel Spaß!%s\n\n", F_GREEN, RESET);
    
    initializeBoard();
    
    do{
        if(checkwin(currentPlayer)){
            winner = currentPlayer;
            break;
        }
        if(game_move_status){
            game_move_number++;
        }
        if(game_move_number % 2 == 0){
            currentPlayer = 2;
        }else{
            currentPlayer = 1;
        }
        printBoard();
        gameMenu(game_move_number, game_move_status);
        // Menüauswahl
        choice = getUserInput("Bitte wählen Sie eine Option", 1, 9);
        
        switch (choice)
        {
        case 8:
            exitGameMenu();
            break;
        case 9:
            printf("TODO: Zurück Funktion\n");
        break;
        default:
            game_move_status = dropPiece(choice - 1, game_move_number);
        }
    }while((choice  != 8) && (game_move_number < MAXGAMEMOVES) && (winner == 0));
    announceWinner(winner);
}

// Spielfeld initialsieren
void initializeBoard(){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Spielfeld ausgeben
void printBoard() {
    int i,j;
    printLine('-', 28);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printLine('-', 28);
    }
}

// Stein fallen lassen
int dropPiece(int col, int n) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if ((board[i][col] == ' ') && (n % 2 != 0)) {
            board[i][col] = player_1.piece;
            return 1;  // Erfolgreicher Spielzug
        }
        if ((board[i][col] == ' ') && (n % 2 == 0)) {
            board[i][col] = player_2.piece;
            return 1;  // Erfolgreicher Spielzug
        }
    }
    return 0;  // Zeile ist voll   
}

// Überprüfung ob ein Spieler gewonnen hat

int checkwin(int currentPlayer) {
    currentPlayer = (currentPlayer % 2 != 0) ? player_1.piece : player_2.piece;
    // Überprüfen horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == currentPlayer &&
                board[i][j + 1] == currentPlayer &&
                board[i][j + 2] == currentPlayer &&
                board[i][j + 3] == currentPlayer) {
                return 1;
            }
        }
    }

    // Überprüfen vertikal
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == currentPlayer &&
                board[i + 1][j] == currentPlayer &&
                board[i + 2][j] == currentPlayer &&
                board[i + 3][j] == currentPlayer) {
                return 1;
            }
        }
    }

    // Überprüfen diagonal (nach rechts oben)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == currentPlayer &&
                board[i - 1][j + 1] == currentPlayer &&
                board[i - 2][j + 2] == currentPlayer &&
                board[i - 3][j + 3] == currentPlayer) {
                return 1;
            }
        }
    }

    // Überprüfen diagonal (nach links oben)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == currentPlayer &&
                board[i - 1][j - 1] == currentPlayer &&
                board[i - 2][j - 2] == currentPlayer &&
                board[i - 3][j - 3] == currentPlayer) {
                return 1;
            }
        }
    }
    return 0;
}

void announceWinner(int winner){
    printf("%s", F_YELLOW);
    printLine('=', 55);
    printTrophy();
    printf("\n                 %sHERZLICHEN GLÜCKWUNSCH%s%s\n\n", UNDERLINE, RESET, F_YELLOW);
    (winner % 2 != 0)? printf("                 %s%s%s hat gewonnen \n\n", F_MAGENTA, player_1.name, F_YELLOW) : printf("                 %s%s%s hat gewonnen \n\n", F_MAGENTA, player_2.name, F_YELLOW);
    printLine('=', 55);
    printf("%s", RESET);
    mainMenu();
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


