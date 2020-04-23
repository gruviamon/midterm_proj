#include "function.h"

int** dealingForHands(int deck[SUITS][FACES])
{
    shuffleCards(deck);

    int ** result = generateMatrix(HANDS, 2);
    int hand = 0;
    int temp;
    int *checktemp = generateArray(CARDS);
    while (hand < HANDS)
    {
        do temp = rand() % ( SUITS*FACES) + 1; while (checktemp[temp - 1]);
        for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < FACES; j++)
            {
                if (deck[i][j] == temp)
                {
                    result[0][hand] = i;
                    result[1][hand] = j;
                    checktemp[temp - 1] = 1;
                }
            }
        }
        hand++;
    }
    free(checktemp);
    return result;
}

void printHand(int** hand, char* suits[SUITS], char* faces[FACES])
{
        for ( int i = 0; i < HANDS; i++)
           cout << '(' << suits[hand[0][i]] << ',' << faces[hand[1][i]] << ')' << endl;
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

