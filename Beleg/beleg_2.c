#include <stdio.h>
#include <stdbool.h>

// include bool

#define FIELDWIDTH 7
#define FIELDLENGTH 6


// STRUKTUREN

// Das ist das Schema für einen Spielzug


// Schablone von einem Knoten
struct GameFieldState
{
    char gameField[FIELDLENGTH][FIELDWIDTH];
    struct GameFieldState *next;
    struct GameFieldState *previous;
};

int getUserInput()
{

    // return column
}

// create empty game field
void initializeEmptyGameField(struct GameFieldState *gameState)
{
    for (int i = 0; i < FIELDLENGTH; i++)
    {
        for (int j = 0; j < FIELDWIDTH; j++)
        {
            gameState->gameField[i][j] = ' ';
        }
    }
}

void drawGameField(struct GameFieldState *gameState)
{
    for (int i = 0; i < FIELDLENGTH; i++)
    {
        for (int j = 0; j < FIELDWIDTH; j++)
        {
            printf("%c", gameState->gameField[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    struct GameFieldState initialGameState;
    bool isWon = false;

    initializeEmptyGameField(&initialGameState);

    int index = 0;

    do
    {
        // wenn index gerade -> spieler 1
        // wenn index ungerade -> spieler 2
        int player = index % 2;


        // get move option
        // is undo ?
        // -> set previous game field state and draw gamefield
        // is redo ?
        // -> set next game field state and draw gamefield
        // is player move ?
        // -> set new game field state and draw gamefield


        // check if game is won

        index++;
    } while (!isWon);

    // create next game field state
}