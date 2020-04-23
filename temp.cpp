#include "function.h"

void REMEMBER_TO_DELETE_IT(int deck[SUITS][FACES])
{
    int count = 1;
    for ( int i = 0; i < SUITS; i++)
    {
        for ( int j =0; j < FACES; j++)
            deck[i][j] = count++ ;
    }
}

