#include "function.h"

int ** generateMatrix ( int row, int col)
{
    int **Matrix = new int* [row];
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = new int[col];
    }
    return Matrix;
}

int** dealingForHands(int deck[SUITS][RANKS])
{
    int ** result = generateMatrix(2,5);
    int hand = 0;

    while (hand <= 4)
    {
        for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < RANKS; j++)
            {
                if ( deck[i][j] == hand + 1 )
                {
                    result[0][hand] = i; //suit
                    result[1][hand] = j; //rank
                    hand++;
                }
            }
        }
    }
    return result;
}

void printHand(int** hand, char* suits[], char* ranks[])
{
        for ( int i = 0; i < 5; i++)
        {
            cout << '(' << suits[ hand[0][i] ] << ',' << ranks[ hand[1][i] ] << ')' << endl;
        }
}
