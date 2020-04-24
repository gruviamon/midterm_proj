#include "function.h"

int main()
{
    srand(time(NULL));

    char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    int deck[SUITS][FACES] ;

    int choice;
    cout << "--- WELCOME TO THE PLAY CARDS GAME ---" << endl;
    shuffleCards(deck);
    do
    {
       Menu(choice, suits, faces, deck);
    }  while(choice >= 0);


}


