#include "function.h"


int * generateArray(int block)
{
    int* Array = (int*) calloc (block, sizeof(int));
    return Array;
}

void shuffleCards(int deck[SUITS][RANKS])
{
    srand(time(NULL));
    int *checkCards = generateArray(SUITS*RANKS);
    int *p = (int*) deck;
    for ( int i = 0; i < SUITS*RANKS;)
    {
        int temp;
        do
        {
            temp = rand() % ( SUITS*RANKS) + 1;
        } while ((*(checkCards + temp) == 1)); //check if Cards has already existed or not

                *(p + i) = temp; //deck
                *(checkCards + temp) = 1; //mark that Cards has existed

                i++;
    }
    delete[]checkCards;
}

//void output_matrix (int row, int col, int a[SUITS][RANKS] )
void output_matrix (int row, int col, int *a )
{
    for ( int i = 0; i < row; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            cout << *a << ' ';
            a++;
        }

        cout << endl;
    }
}

int main()
{
    char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    char* ranks[RANKS] = {"Ace", "Two", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    int deck[SUITS][RANKS] = {0};
    output_matrix(SUITS, RANKS, &deck[0][0]);
    shuffleCards(deck);
    output_matrix(SUITS, RANKS, &deck[0][0]);
    dealingForHands(deck);

    int **Hands = dealingForHands(deck);
    printHand(Hands, suits,ranks);
}
