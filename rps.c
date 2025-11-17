#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void showMenu();
void printChoice(int choice);
int decideWinner(int user, int comp);
void explainLoss(int user, int comp);
void explainWin(int user, int comp);
void playRound();

// Display the game menu to the user
void showMenu()
{
    printf("\n==============================\n");
    printf("   Rock Paper Scissors Game   \n");
    printf("==============================\n");
    printf("Choose one option:\n");
    printf("  1 -> Rock\n");
    printf("  2 -> Paper\n");
    printf("  3 -> Scissors\n");
    printf("Enter your choice (1-3): ");
}

/* 
   Print Rock / Paper / Scissors
   depending on the integer choice
*/
void printChoice(int choice)
{
    switch (choice)
    {
    case 1:
        printf("Rock");
        break;

    case 2:
        printf("Paper");
        break;

    case 3:
        printf("Scissors");
        break;

    default:
        printf("Unknown");
        break;
    }
}

/*
   Decide the winner:
   return 0 → draw
   return 1 → user wins
   return -1 → computer wins
*/
int decideWinner(int user, int comp)
{
    if (user == comp)
        return 0; // same choice → draw

    /*
       Rules:
       Rock (1) beats Scissors (3)
       Paper (2) beats Rock (1)
       Scissors (3) beats Paper (2)
    */

    switch (user)
    {
    case 1: // Rock
        if (comp == 3)
            return 1;
        else
            return -1;

    case 2: // Paper
        if (comp == 1)
            return 1;
        else
            return -1;

    case 3: // Scissors
        if (comp == 2)
            return 1;
        else
            return -1;
    }

    // Should never happen
    return -1;
}

// Explain WHY the user lost
void explainLoss(int user, int comp)
{
    if (user == 1 && comp == 2)
        printf("Paper covers Rock.\n");
    else if (user == 2 && comp == 3)
        printf("Scissors cut Paper.\n");
    else if (user == 3 && comp == 1)
        printf("Rock smashes Scissors.\n");
    else
        printf("\n");
}

// Explain WHY the user lost
void explainWin(int user, int comp)
{
    if (user == 2 && comp == 1)
        printf("Paper covers Rock.\n");
    else if (user == 3 && comp == 2)
        printf("Scissors cut Paper.\n");
    else if (user == 1 && comp == 3)
        printf("Rock smashes Scissors.\n");
    else
        printf("\n");
}

/*
   This function plays one full round:
   - takes user input
   - generates computer choice
   - prints choices
   - decides winner
*/
void playRound()
{
    int userChoice;
    int computerChoice;
    int gameResult;

    showMenu();

    scanf("%d", &userChoice);

    // Validate the input
    if (userChoice < 1 || userChoice > 3)
    {
        printf("Invalid choice! Please choose between 1 and 3.\n");
        return;
    }

    // Generate computer choice (1–3)
    computerChoice = rand() % 3 + 1;

    // Display choices
    printf("\nYou chose: ");
    printChoice(userChoice);

    printf("\nComputer chose: ");
    printChoice(computerChoice);
    printf("\n\n");

    // Decide winner
    gameResult = decideWinner(userChoice, computerChoice);

    // Display result
    switch (gameResult)
    {
    case 0:
        printf("Result: It's a DRAW!\n");
        break;

    case 1:
        printf("Result: YOU WIN! Great job!\n");
        explainWin(userChoice, computerChoice);
        break;

    case -1:
        printf("Result: YOU LOST! ");
        explainLoss(userChoice, computerChoice);
        break;
    }
}

int main()
{
    srand(time(0)); // Seed random number generator

    while (1)
    {
        playRound(); // play infinite rounds
    }

    return 0;
}
