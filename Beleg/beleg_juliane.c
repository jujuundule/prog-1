// Juliane Träger | 54004 | s86422 | 23/043/01

// ======================================================================================== 
//                                         Header-Dateien 
// ======================================================================================== 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

// ======================================================================================== 
//                                     Makros und Konstanten
// ======================================================================================== 

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

// Spielzüge
#define MAXGAMEMOVES 42

// Menübreite
#define MENUWIDTH 55

// ======================================================================================== 
//                               Strukturen und Typdefinitionen:
// ======================================================================================== 

// Struktur: Spielzug
typedef struct {
    int number;
    int player;
    char board[ROWS][COLS];
    struct GameMove* next;
    struct GameMove* previous;
} GameMove;

// Struktur: Spielzug Historie
typedef struct {
    GameMove* gamestart;
} GameMoveHistory;

// Enum: Spieler
typedef enum { EMPTY, PLAYER_1, PLAYER_2 } Player_number;

// Struktur: Spieler
typedef struct {
    char name[26];
    char piece; 
}Player;

// Initialisiere Spieler
Player player_1 = {"Spieler 1", 'X'};
Player player_2 = {"Spieler 2", 'O'};



// ======================================================================================== 
//                                  Funktions-Deklarationen 
// ======================================================================================== 

// ASCII Art
void printLine(char, int);
void printGameTitle(void);
void printTrophy(void);
void printGoodbye(void);
void printEmoticon(void);

// Konsole leeren
void clearConsole(void);

// Nutzereingabe und Validierung
int getUserInput(char*, int, int);
int inputName(Player*, int);

// Menüs
void mainMenu(void);
void newGameMenu(void);
void twoPlayersMenu(void);
void namePlayersMenu(void);
void exitGameMenu();
void loadGameMenu(void);
void gameMenu(GameMove*, int);

// Spiel starten: 2 Spieler
void startGame(void);

// Spielfunktionen
void initializeBoard(GameMove*);
void printBoard(GameMove*);
int dropPiece(int, GameMove*);
int checkwin(GameMove*);
void announceWinner(int, int);

// End Screen
void printEndScreen(void);

// Doppelt verkettete Liste
void appendGameMove(GameMoveHistory*, GameMove*);
GameMove* getLastMove(GameMoveHistory*);
void freeGameMoveHistory(GameMoveHistory*);
void undoLastMove(GameMoveHistory*);


// ======================================================================================== 
//                                      Globale Variablen
// ======================================================================================== 





// ======================================================================================== 
//                                   Funktions-Definitionen  
// ======================================================================================== 

// Linie ausgeben
void printLine(char linetype, int length){
int i;
for(i = 0; i <= length; i++){
    printf("%c", linetype);
}
printf("\n");
}

// -------------------------------------- ASCII Art --------------------------------------

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

void printEmoticon(){
    printf("\n                      ¯\\_(ツ)_/¯\n");

}

// -------------------------------------- Konsole leeren --------------------------------------

void clearConsole(){
    printf("\e[1;1H\e[2J");
}

// -------------------------------------- Nutzereingabe und Validierung --------------------------------------

int getUserInput(char *instruction, int min, int max) {
    int input;
    int validInput;

    do {
        // Aufforderung an den Nutzer ausgeben
        printf("%s [%d-%d]: ", instruction, min, max);

        validInput = scanf("%d", &input);

        // Eingabe überprüfen
        if (validInput != 1 || input < min || input > max) {
            // Fehlerhafte Eingabe behandeln
            printf("%sFalsche Eingabe%s\n", F_RED, RESET);

            // Den Eingabepuffer leeren
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            validInput = 0; // Markiere die Eingabe als ungültig
        } else {
            // Überprüfen, ob der Eingabepuffer weitere Zeichen enthält (Buchstaben oder Symbole)
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                if (!isspace(c)) {
                    // Fehlerhafte Eingabe behandeln
                    printf("%sFalsche Eingabe%s\n", F_RED, RESET);

                    // Den Eingabepuffer leeren
                    while ((c = getchar()) != '\n' && c != EOF);

                    validInput = 0; // Markiere die Eingabe als ungültig
                    break;
                }
            }
        }

    } while (validInput != 1);

    return input;
}

int inputName(Player* player, int maxLength) {
    int validInput = 0;
    while(!validInput){
        printf("Bitte geben Sie einen neuen Namen ein (maximal %d Buchstaben): ", maxLength);

        // Lese den Namen vom Benutzer ein
        fgets(player->name, sizeof(player->name), stdin);
        validInput = 1; // Erfolgreiche Eingabe

        // Überprüfe, ob der Name länger als 0 ist
        if (player->name[0] == '\0' || player->name[0] == '\n') {
            printf("\n%sUngültige Eingabe. Der Name darf nicht leer sein.%s\n", F_RED, RESET);
            validInput = 0; // Fehler, wenn der Name leer ist
        }

        // Überprüfe, ob der Name die maximale Länge überschreitet
        if (strlen(player->name) > maxLength + 1) {
            printf("\n%sUngültige Eingabe. Der Name darf maximal %d Buchstaben haben.%s\n", F_RED, maxLength, RESET);
            validInput = 0; // Fehler, wenn der Name zu lang ist
        }

        // Überprüfe, ob alle Zeichen im Namen Buchstaben sind
        for (int i = 0; player->name[i] != '\0' && player->name[i] != '\n'; i++) {
            if (!isalpha(player->name[i])) {
                printf("\n%sUngültige Eingabe. Der Name darf nur Buchstaben enthalten.%s\n", F_RED, RESET);
                validInput = 0; // Fehler, wenn ein nicht-alfabetisches Zeichen gefunden wird
            }
        }
        // Entferne das newline-Zeichen am Ende des Namens, das durch fgets hinzugefügt wurde
        player->name[strcspn(player->name, "\n")] = '\0';
    }
    return validInput;
}

// -------------------------------------- Hauptmenü --------------------------------------

void mainMenu(){
    
    // Konsole leeren
    clearConsole();
    
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                       %sHAUPTMENÜ%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Neues Spiel starten\n");
    printf("                 2 - Spielstand laden\n");
    printf("                 3 - Spiel beenden\n\n");
    printLine('=', MENUWIDTH);
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

// -------------------------------------- Untermenü "Neues Spiel starten" --------------------------------------

void newGameMenu(){
    
    // Konsole leeren
    clearConsole();

    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                  %sNEUES SPIEL STARTEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - 2 Spieler\n");
    printf("                 2 - Gegen Computer spielen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', MENUWIDTH);
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

// -------------------------------------- Untermenü "2 Spieler" --------------------------------------

void twoPlayersMenu(){
    
    // Konsole leeren
    clearConsole();

    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                        %s2 SPIELER%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spiel starten\n");
    printf("                 2 - Spieler umbenennen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', MENUWIDTH);
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

// -------------------------------------- Untermenü "Spieler umbenennen" --------------------------------------

void namePlayersMenu(){

    // Konsole leeren
    clearConsole();

    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                    %sSPIELER UMBENENNEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spieler 1 umbenennen\n");
    printf("                 2 - Spieler 2 umbenennen\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', MENUWIDTH);
    printf("%s", RESET);
    
    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                printf("\n%sSpieler 1:%s\n", F_MAGENTA, RESET);
                printf("[Aktueller Name: %s%s%s]\n\n", F_MAGENTA, player_1.name, RESET);
                if(inputName(&player_1, 25)){
                    printf("Spieler 1 wurde in %s%s%s umbenannt.\n", F_MAGENTA, player_1.name, RESET);
                }else{
                    printf("Spieler 1 konnte nicht umbenannt werden.");
                }
                sleep(2);
                namePlayersMenu();
                break;
            case 2:
                printf("\n%sSpieler 2:%s\n", F_MAGENTA, RESET);
                printf("[Aktueller Name: %s%s%s]\n\n", F_MAGENTA, player_2.name, RESET);
                if(inputName(&player_2, 25)){
                    printf("Spieler 2 wurde in %s%s%s umbenannt.\n", F_MAGENTA, player_2.name, RESET);
                }else{
                    printf("Spieler 2 konnte nicht umbenannt werden.");
                }
                sleep(2);
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

// -------------------------------------- Untermenü "Spiel beenden" --------------------------------------

void exitGameMenu(){
    
    // Konsole leeren
    clearConsole();

    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                      %sSPIEL BEENDEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - Spielstand speichern\n");
    printf("                 2 - Ohne Speichern beenden\n");
    printf("                 3 - Spiel wieder aufnehmen\n\n");
    printLine('=', MENUWIDTH);
    printf("%s", RESET);

    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                printf("TODO Spielstand speichern Funktion\n");
                break;
            case 2:
                mainMenu();
                break;
            case 3:
                startGame();
                break;
            default:
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}
// -------------------------------------- Untermenü "Spiel laden" --------------------------------------

void saveGameMenu(struct GameMove* head) {
    char fileName[50];
    
    // Benutzer nach dem Dateinamen fragen
    printf("Bitte geben Sie den Dateinamen zum Speichern des Spielstands ein: ");
    scanf("%s", fileName);
}

// -------------------------------------- Untermenü "Spiel laden" --------------------------------------

void loadGameMenu(){
    
    // Konsole leeren
    clearConsole();

    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                    %sSPIELSTAND LADEN%s%s\n\n", UNDERLINE, RESET, F_CYAN);
    printf("                 1 - 'Dateiname' - DDMMYY\n");
    printf("                 2 - 'Dateiname' - DDMMYY\n");
    printf("                 3 - Zurück\n\n");
    printLine('=', MENUWIDTH);
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

// -------------------------------------- Game Menü --------------------------------------

void gameMenu(GameMove* currentMove, int game_move_status) {
    // Menü ausgeben
    printf("%s", F_CYAN);
    for (int i = 0; i < COLS; i++) {
        printf("  %d ", i + 1);
    }
    printf("\n\n8 - Spiel beenden\n9 - Letzten Spielzug rückgängig machen" RESET "\n\n");
    printf("%sSpielzug: %d von %d %s\n\n", F_YELLOW, currentMove->number, MAXGAMEMOVES, RESET);

    printf("%s%s:%s\n", F_MAGENTA, (currentMove->player == 1)? player_1.name : player_2.name, RESET);

    if (game_move_status == 0) {
        printf("%sDie Zeile ist voll%s\n", F_RED, RESET);
    }
}

// -------------------------------------- Siegerehrung Menü --------------------------------------
void announceWinnerMenu() {
    // Menü ausgeben
    printf("%s", F_CYAN);
    printLine('=', MENUWIDTH);
    printf("\n                 1 - Zurück zum Hauptmenü\n");
    printf("                 2 - Spiel neustarten\n");
    printf("                 3 - Spiel beenden\n\n");
    printLine('=', MENUWIDTH);
    printf("%s", RESET);

    // Menüauswahl
    int choice = getUserInput("Bitte wählen Sie eine Option", 1, 3);

    switch (choice){
            case 1:
                mainMenu();
                break;
            case 2:
                startGame();
                break;
            case 3:
                printEndScreen();
                break;
            default:
                printf("%sFalsche Eingabe%s\n", F_RED, RESET);
                break;
    }
}

// -------------------------------------- Spiel starten --------------------------------------

void startGame(){
    
    // Erselle eine Historie für die Spielzüge
    GameMoveHistory history;

    // Erstelle den ersten Spielzug
    GameMove* currentMove = calloc(1, sizeof(GameMove));
    
    // Den ersten Spielzug initialisieren
    currentMove->number = 0;
    currentMove->player = 1;
    currentMove->next = NULL;
    currentMove->previous = NULL;

    // Den ersten Spielzug in die Historie eintragen
    history.gamestart = currentMove;

    // weitere Spielvariablen initialisieren
    int choice = 0, winner = 0, game_move_status = 1, win_reason = 0;

    // Konsole leeren
    clearConsole();
    
    printf("\n%sEin neues Spiel wird gestartet.\nViel Spaß!%s %s %sund%s %s%s \n\n", F_GREEN, F_MAGENTA, player_1.name, F_GREEN, F_MAGENTA, player_2.name, RESET);

    sleep(2);

    // Spielfeld wird initialisiert --> alle Felder mit " " füllen
    initializeBoard(currentMove);

    // leeres Spielfeld in die Historie eintragen (Spielzug 0)
    appendGameMove(&history, currentMove);

    
    // Schleife für abwechselnde Spielzüge
    // Schleife wird beendet, wenn ein Spieler gewonnen hat, die maximale Anzahl von Spielzügen erreicht ist, oder der Spieler das Spiel beendet
    while((choice != 8)  && (checkwin(currentMove) == 0) && (currentMove->number < MAXGAMEMOVES)){

        // Spielzug hochzählen
        currentMove->number++;

        // Spielerwechsel
        switch (currentMove->number % 2) {
            case 0:
                currentMove->player = PLAYER_2;
                break;
            default:
                currentMove->player = PLAYER_1;
                break;
        }

        // Konsole leeren
        clearConsole();

        // Spielfeld ausgeben
        printBoard(currentMove);

        // aktuelles Spielmenü ausgeben
        gameMenu(currentMove, game_move_status);

        // Menüauswahl
        choice = getUserInput("Bitte wählen Sie eine Option", 1, 9);

        switch (choice){
            case 8:
                exitGameMenu(currentMove);
                break;
            case 9:
                if(currentMove->number == 1){
                    printf("%sEs gibt keinen vorherigen Spielzug%s\n", F_RED, RESET);
                    sleep(2);
                    currentMove->number = 0;
                }else if (currentMove->number == 2){
                    // letzten Spielzug löschen
                    undoLastMove(&history);
                    // aktuellen Spielzug aktualisieren
                    currentMove = getLastMove(&history);
                    // Spielzug auf 0 setzen
                    currentMove->number = 0;
                    appendGameMove(&history, currentMove);
                }else if (currentMove->number > 2){
                    // letzten Spielzug löschen
                    undoLastMove(&history);
                    // aktuellen Spielzug aktualisieren
                    currentMove = getLastMove(&history); 
                }
                break;
            default:
                // Stein fallen lassen
                game_move_status = dropPiece(choice - 1, currentMove);
                // Spielzug in die Historie eintragen
                appendGameMove(&history, currentMove);
                break;
        }
    }
    // Siegerehrung, wenn ein Spieler gewonnen 
    if(checkwin(currentMove) != 0){
        winner = currentMove->player;
        win_reason = checkwin(currentMove);        
        clearConsole();
        printBoard(currentMove);
        announceWinner(winner, win_reason);
    }
    // Unentschieden, wenn alle Felder belegt sind und kein Spieler gewonnen hat
    if((checkwin(currentMove) == 0) && (currentMove->number == MAXGAMEMOVES)){
        clearConsole();
        printBoard(currentMove);
        announceWinner(0, 0);
    }
    freeGameMoveHistory(&history);
}

// -------------------------------------- Spielfunktionen --------------------------------------

// Spielfeld initialsieren
void initializeBoard(GameMove* currentMove){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            currentMove->board[i][j] = ' ';
        }
    }
}

// Spielfeld ausgeben
void printBoard(GameMove* currentMove) {
    int i,j;
    printLine('-', 28);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("| %c ", currentMove->board[i][j]);
        }
        printf("|\n");
        printLine('-', 28);
    }
}

// Stein fallen lassen
int dropPiece(int column, GameMove* currentMove) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if ((currentMove->board[i][column] == ' ') && (currentMove->number % 2 != 0)) {
            currentMove->board[i][column] = player_1.piece;
            return 1;  // Erfolgreicher Spielzug
        }
        if ((currentMove->board[i][column] == ' ') && (currentMove->number % 2 == 0)) {
            currentMove->board[i][column] = player_2.piece;
            return 1;  // Erfolgreicher Spielzug
        }
    }
    return 0;  // Zeile ist voll   
}

// Überprüfung ob ein Spieler gewonnen hat

int checkwin(GameMove* currentMove) {
    char piece = (currentMove->player == 1) ? player_1.piece : player_2.piece;
    // Überprüfen horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (currentMove->board[i][j] == piece &&
                currentMove->board[i][j + 1] == piece &&
                currentMove->board[i][j + 2] == piece &&
                currentMove->board[i][j + 3] == piece) {
                return 1;
            }
        }
    }

    // Überprüfen vertikal
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (currentMove->board[i][j] == piece &&
                currentMove->board[i + 1][j] == piece &&
                currentMove->board[i + 2][j] == piece &&
                currentMove->board[i + 3][j] == piece) {
                return 2;
            }
        }
    }

    // Überprüfen diagonal (nach rechts oben)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (currentMove->board[i][j] == piece &&
                currentMove->board[i - 1][j + 1] == piece &&
                currentMove->board[i - 2][j + 2] == piece &&
                currentMove->board[i - 3][j + 3] == piece) {
                return 3;
            }
        }
    }

    // Überprüfen diagonal (nach links oben)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 3; j < COLS; j++) {
            if (currentMove->board[i][j] == piece &&
                currentMove->board[i - 1][j - 1] == piece &&
                currentMove->board[i - 2][j - 2] == piece &&
                currentMove->board[i - 3][j - 3] == piece) {
                return 4;
            }
        }
    }
    return 0;
}

void announceWinner(int winner, int r){
   
   // Grund für den Gewinn
   char* reason;
   switch (r)
   {
   case 1:
        reason = "horizontal";
    break;
    case 2:
        reason = "vertikal";
    break;
    case 3:
        reason = "diagonal (nach rechts oben)";
    break;
    case 4:
        reason = "diagonal (nach links oben)";
    break;
   default:
    break;
   }

    // Bekanntgabe des Gewinners
   printf("%s", F_YELLOW);
   printLine('=', MENUWIDTH);
    if(winner != 0){
        printTrophy();
        printf("\n                 %sHERZLICHEN GLÜCKWUNSCH%s%s\n\n", UNDERLINE, RESET, F_YELLOW);
        printf("                 %s%s [%c]%s hat gewonnen \n", F_MAGENTA, (winner == 1)? player_1.name : player_2.name, (winner == 1)? player_1.piece : player_2.piece, F_YELLOW);
        printf("                 [%s]\n\n", reason);
        printLine('=', MENUWIDTH);    
    }
    // Unentschieden
    else{
        printEmoticon();
        printf("\n                     %sUNENTSCHIEDEN%s%s\n\n", UNDERLINE, RESET, F_YELLOW);
        printLine('=', MENUWIDTH);
    }
    printf("%s", RESET);
    announceWinnerMenu();
}

// -------------------------------------- Funktionen zum Speichern des aktuellen Spielstands --------------------------------------


// -------------------------------------- EndScreen --------------------------------------

void printEndScreen(){
    clearConsole();
    printGoodbye();
    printf("\n%s", F_RED);
    printLine('=', MENUWIDTH);
    printf("\n                      SPIEL BEENDET\n\n");
    printLine('=', MENUWIDTH);
    printf("%s\n", RESET);
    sleep(3);
    clearConsole();
}

// -------------------------------------- Doppelt verkettete Liste --------------------------------------

// Funktion zum Einfügen eines neuen Spielzugs am Ende der Liste
void appendGameMove(GameMoveHistory* history, GameMove* currentMove) {
    // Erstelle einen neuen Spielzug
    GameMove* newMove = malloc(sizeof(GameMove));
    
    if (newMove == NULL) {
        // Fehler beim Speicher reservieren
        printf("%sFehler beim Speicher reservieren%s\n", F_RED, RESET);
        return;
    }

    // Setze die Werte für den neuen Spielzug
    newMove->number = currentMove->number;
    newMove->player = currentMove->player;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            newMove->board[i][j] = currentMove->board[i][j];
        }
    }
    newMove->next = NULL;  // Der neue Spielzug wird das letzte Element sein
    newMove->previous = NULL; 

    // Wenn die Liste leer ist, setze gamestart auf den neuen Spielzug
    if (history->gamestart == NULL) {
        history->gamestart = newMove;
    } else {
        // Andernfalls füge den neuen Spielzug am Ende der Liste ein
        GameMove* currentMove = history->gamestart;
        // Durchlaufe die Liste bis zum letzten Spielzug (next == NULL)
        while (currentMove->next != NULL) {
            currentMove = currentMove->next;
        }
        // Verknüpfe den letzten Spielzug mit dem neuen Spielzug
        currentMove->next = newMove;
        // Verknüpfe den neuen Spielzug mit dem letzten Spielzug
        newMove->previous = currentMove;
    }
}

// Funktion zum Abrufen des letzten Spielzugs
GameMove* getLastMove(GameMoveHistory* history) {
    if (history->gamestart == NULL) {
        // Die Liste ist leer
        return NULL;
    }

    // Finde das letzte Element in der Liste
    GameMove* lastMove = history->gamestart;
    while (lastMove->next != NULL) {
        lastMove = lastMove->next;
    }

    return lastMove;
}

// Funktion zum freigeben des Speichers der doppelt verketteten Liste
void freeGameMoveHistory(GameMoveHistory* history) {
    GameMove* currentMove = history->gamestart;
    GameMove* nextMove;
    // Durchlaufe die Liste und gib den Speicher für jeden Spielzug frei
    while (currentMove != NULL) {
        nextMove = currentMove->next;
        free(currentMove);
        currentMove = nextMove;
    }
    // Setze den Zeiger in der GameMoveHistory auf NULL, um sicherzustellen, dass er nicht auf ungültigen Speicher zeigt.
    history->gamestart = NULL;
}

// Funktion zum Rückgängigmachen des letzten Spielzugs

void undoLastMove(GameMoveHistory* history) {
    // Die Liste ist leer
    if (history->gamestart == NULL) {
        return;
    }

    // Finde das letzte Element in der Liste
    GameMove* lastMove = getLastMove(history);

    // Der vorherige Spielzug wird das neue letzte Element
    GameMove* newLastMove = lastMove->previous;
    // Der Zeiger des neuen letzten Spielzugs auf NULL setzen
    newLastMove->next = NULL;

    // Freigabe des Speichers für den letzten Spielzug
    free(lastMove);
}

// ======================================================================================== 
//                                        Main Funktion
// ======================================================================================== 

void main(){
    printGameTitle();
    sleep(2);
    mainMenu();
}


