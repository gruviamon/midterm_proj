#include "function.h"

void shuffleCards(int deck[SUITS][FACES])
{
    int *checkCards = generateArray(SUITS*FACES);
    for (int i = 0; i < SUITS; i++)
        for (int j = 0; j < FACES; j++)
        {
            int temp;
            do temp = rand() % ( SUITS*FACES) + 1; while (checkCards[temp - 1]); //check if Cards has already existed or not
            deck[i][j] = temp; //deck
            checkCards[temp - 1] = 1; //mark that Cards has existed
        }
    free(checkCards);
}

void output_matrix (int row, int col, int a[SUITS][FACES] )
{
    for ( int i = 0; i < row; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }
}

void printCards(int deck[SUITS][FACES], char* suits[], char* faces[])
{
    int _count = 1;
    while ( _count <= CARDS)
    {
        for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < FACES; j++)
            {
                if ( deck[i][j] == _count )
                {
                     cout << _count << ". " ;
                     cout << '(' << suits[i] << ',' << faces[j] << ')' << endl;
                }
            }
        }
        _count++;
    }
}

