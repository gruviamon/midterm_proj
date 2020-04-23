#include "function.h"

int** dealingForHands(int deck[SUITS][FACES])
{
    int ** result = generateMatrix(2,5);
    int hand = 0;

    while (hand < HANDS)
    {
        int temp = rand() % (SUITS*FACES) + 1;
        for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < FACES; j++)
            {
                if ( deck[i][j] == temp )
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

void printHand(int** hand, char* suits[], char* FACES[])
{
        for ( int i = 0; i < HANDS; i++)
        {
            cout << '(' << suits[ hand[0][i] ] << ',' << FACES[ hand[1][i] ] << ')' << endl;
        }
}

int** createHandTest(int deck[SUITS][FACES], int a[HANDS])
{
    int ** result = generateMatrix(2,5);
    int hand = 0;
    while (hand < HANDS)
    {
        for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < FACES; j++)
            {
                if ( deck[i][j] == a[hand] )
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

