#include "function.h"

int * generateArray(int row,int col)
{
    int* checkCards = (int*) calloc (row*col, sizeof(int));
    return checkCards;
}

void shuffleCards(int deck[SUITS][RANKS])
{
    srand(time(NULL));
    int *checkCards = generateArray(SUITS,RANKS);
    int *p = (int*) deck;
    for ( int i = 0; i < SUITS*RANKS;)
    {
        int temp;
        do
        {
            temp = rand() % (SUITS*RANKS + 1);
        } while ((*(checkCards + temp) == 1)); //check if Cards has already exist
                *(p + i) = temp;
                *(checkCards + temp) = 1;
                i++;
    }
    delete[]checkCards;
}

void output_matrix ( int a[SUITS][RANKS], int row, int col)
{
    for ( int i = 0; i < row; i++)
    {
        for ( int jj = 0; jj < col; jj++)
            cout << a[i][jj] << ' ';
        cout << endl;
    }
}

int main()
{
    int deck[SUITS][RANKS] = {0};
    output_matrix(deck, SUITS, RANKS);
    shuffleCards(deck);
    output_matrix(deck, SUITS, RANKS);
}
