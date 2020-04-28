#include "function.h"

int main()
{
    char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[SUITS][FACES];
    srand(time(NULL));

    int choice;
    shuffleCards(deck);

    do
    {
        cout << "--- WELCOME TO THE PLAY CARDS GAME ---" << endl;
        Menu(choice, suits, faces, deck);
        system("pause");
        system("cls");
    } while (choice >= 0 && choice <= 5);
    return 0;
}


