#include <iostream>
#include <ctime>
#include <string>
#include "Deck.h"
#include "SidePile.h"

using namespace std;

// Program Constants
const int WHOLE_DECK = 52;
const int HALF_DECK = WHOLE_DECK/2;

//Structures
struct Player {
	string playerName;
	Deck deck;
	SidePile sidePile;
	int totalCards;
	void updateTotalCards() {
		totalCards = deck.cardsLeft() + sidePile.cardsLeft();
	}
};


// Function Prototypes
void assignDecks(int*, int*, int*);
void shuffleDeck(int*, int);
int getValidInput(string, int, int);
void playOneRound(Player, Player, int);


// Main
int main()
{
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

	//Set rules
	string rulePrompt = "\
(1) Select number of rounds\n\
(2) Play until either player ends up with 0 cards\n\
Enter an option: ";
	int numRounds, totalRounds = 0;
	if (getValidInput(rulePrompt, 1, 2) == 1) {
		numRounds = getValidInput("Enter number of rounds (1 or greater): ", 1, INT_MAX);
	}
	else {
		numRounds = INT_MAX;
	}

	//  Play game
	Player player = {"Player", playerDeck, playerSide, 0};
	Player computer = {"Computer", computerDeck, computerSide, 0};
	
    do{
		player.updateTotalCards();
		computer.updateTotalCards();
		playOneRound(player, computer, totalRounds);
		totalRounds++;
	} while (player.totalCards > 0 && computer.totalCards > 0 && totalRounds != numRounds);
	//Final values
	player.updateTotalCards();
	computer.updateTotalCards();
	cout << "Game Over\n";
	
}

/*
Plays one round of the game
*/
int playOneRound(Player player, Player computer, int totalRounds) {
	string choicePrompt = "\
(1) Check how many cards are in your deck\n\
(2) Check how many cards are in the computer's deck\n\
(3) Check how many cards in your side pile\n\
(4) Peek at your top card\n\
(5) Play card. \n\
Enter an option: ";
	int choice = getValidInput(choicePrompt, 1, 5);
	cout << "Round: " << totalRounds + 1 << endl;
	switch (choice) {
	case 1:
		cout << "Cards in your deck: " << player.deck.cardsLeft() << endl;
		break;
	case 2:
		cout << "Cards in computer's deck: " << computer.deck.cardsLeft() << endl;
		break;
	case 3:
		cout << "Cards in your side pile: " << player.sidePile.cardsLeft() << endl;
		break;
	case 4:
		int topCard = player.deck.peek();
		cout << "Your top card is: " << (topCard == 14 ? "Ace" : topCard == 13 ? "King" :
			topCard == 12 ? "Queen" : topCard == 11 ? "Jack" :
			to_string(topCard)) << endl;


		break;
		cout << endl;
	case 5:
		cout << "Playing Card" << endl;
		
	}
	return choice < 3 ? totalRounds : ++totalRounds;
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
    int *newDeck = new int[SIZE];

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
	cout << "OPTIONS:\n";
	cout << prompt;
	cin >> value;
    while(cin.fail() || value < minVal || value > maxVal)
    {
		// Clear buffer and error
		cin.clear();
		cin.ignore();
        
		// Display prompt and accept user input 
		cout << "ERROR:Menu option does not exist. Select different option: ";
        cin >> value;
        cout << endl;
    }
    return value;
}



