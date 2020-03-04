#include <iostream>
#include <ctime>
#include <string>
#include "Deck.cpp"
#include "SidePile.cpp"

using namespace std;

// Program Constants
const int WHOLE_DECK = 52;
const int HALF_DECK = WHOLE_DECK/2;

// Function Prototypes
void assignDecks(int*, int*, int*);
void shuffleDeck(int*, int);
int getValidInput(string, int, int);

// Main
int main()
{
    // Initialize Prompt Strings
    string choicePrompt = "\
(1) Check how many cards are in your deck\n\
(2) Check how many cards are in the computer's deck\n\
(3) Check how many cards in your side pile\n\
(4) Peek at your top card\n\
(5) Thing five\n\
Enter an option: ";

    // Seed Random
    srand(time(0));

    // Initialize Game Deck Arrays
    int* playerArray = new int[HALF_DECK];
    int* computerArray = new int[HALF_DECK];

    // Create Base Deck Array
    int baseArray[WHOLE_DECK] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                                 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                                 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                                 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    // Randomly Shuffle Base Deck Array
    shuffleDeck(baseArray, WHOLE_DECK);

    // Assign Cards to Game Decks Arrays
    assignDecks(playerArray, computerArray, baseArray);

    // Randomly Shuffle Each Deck Array
    shuffleDeck(playerArray, HALF_DECK);
    shuffleDeck(computerArray, HALF_DECK);

    // Create Instances of Game Decks
    Deck playerDeck(playerArray, HALF_DECK);
    Deck computerDeck(computerArray, HALF_DECK);

    // Create Instances of Side Piles
    SidePile playerSide;
    SidePile computerSide;

    while((playerDeck.cardsLeft() + playerSide.cardsLeft() > 0) && (computerDeck.cardsLeft() + computerSide.cardsLeft() > 0))
    {
        int choice = getValidInput(choicePrompt, 1, 5);

        switch(choice)
        {
            case 1:
                cout << "Cards in your deck: " << playerDeck.cardsLeft() << endl;
                cout << endl;
                break;
            case 2:
                cout << "Cards in computer's deck: " << computerDeck.cardsLeft() << endl;
                cout << endl;
                break;
            case 3:
                cout << "Cards in your side pile: " << playerSide.cardsLeft() << endl;
                cout << endl;
                break;
            case 4:
                int topCard = playerDeck.peek();
                cout << "Your top card is: " << (topCard == 14 ? "Ace" : topCard == 13 ? "King" :
                                                 topCard == 12 ? "Queen" : topCard == 11 ? "Jack" :
                                                 to_string(topCard)) << endl;
                cout << endl;
                break;
        }

    }
}

/*
    Assign Decks Function

    Iterates through each index of the base deck to randomly
    distribute the deck between the player and computer.
*/
void assignDecks(int* playerDeck, int* computerDeck, int* baseDeck)
{
    // Tracks how many cards each deck still needs
    int playerAssignmentsLeft = HALF_DECK;
    int computerAssignmentsLeft = HALF_DECK;


    for(int i = 0; i < WHOLE_DECK; i++)
    {
        // Assigns card to the players deck
        if((rand()%2 == 0 && playerAssignmentsLeft > 0) || computerAssignmentsLeft == 0)
        {
            playerDeck[HALF_DECK-playerAssignmentsLeft] = baseDeck[i];
            playerAssignmentsLeft--;
        }

        // Assigns card to the computers deck
        else
        {
            computerDeck[HALF_DECK-computerAssignmentsLeft] = baseDeck[i];
            computerAssignmentsLeft--;
        }
    }
}

/*
    Shuffle Deck Function

    Takes a deck array and randomizes the entries, and alters
    the original array with the new randomization.
*/
void shuffleDeck(int* deckArray, int SIZE)
{
    int newDeck[SIZE];

    // Keeps track of items left in deck array
    int itemsRemaining = SIZE;

    while(itemsRemaining > 0)
    {
        // Randomly selects a position in the array
        int random = rand()%SIZE;
        if(deckArray[random] != -1)
        {
            // Writes the random value to the new array and marks this position
            // as previously read using a sentinel value of -1
            newDeck[SIZE-itemsRemaining] = deckArray[random];
            deckArray[random] = -1;
            itemsRemaining--;
        }
    }

    // Assign Deck Array with New Arrangement
    for(int i = 0; i < SIZE; i++)
    {
        deckArray[i] = newDeck[i];
    }
}

/*
    Get Valid Input Function

    Takes in a prompt, a minimum value, and maximum value
    and returns a valid input.
*/

int getValidInput(string prompt, int minVal, int maxVal)
{
    int value = minVal - 1;
    while(value < minVal || value > maxVal)
    {
        cout << prompt;
        cin >> value;
        cout << endl;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
        }
    }
    return value;
}



