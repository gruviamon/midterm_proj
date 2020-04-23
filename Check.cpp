#include"function.h"

// hand: suits[0]; faces[1]

int isFourOfAKind(int** hand) // 7
{
    int *suitsCount = generate_suitsCount(hand);
    for ( int i = 0; i < SUITS; i++ )
    {
        if (suitsCount[i] == 4)
        {
            delete []suitsCount;
            return 7; // true
        }
    }
    delete []suitsCount;
    return 0;
}

int isFullHouse(int** hand) // 6
{
    int *suitsCount = generate_suitsCount(hand);
    for ( int i = 0; i < SUITS; i++ ) //check
        {
            for ( int j = 0; j < SUITS; j++ )
            {
                if ( suitsCount[i] == 2 && suitsCount[j] == 3)
                {
                    free(suitsCount);
                    return 6;
                }
            }
        }
    free(suitsCount);
    return 0;
}

int isFlush(int** hand) // 5
{
    if ( checkFlush(hand) && !checkStraight(hand) ) return 5;
    return 0;
}

int isStraight(int** hand) // 4
{
    if ( !checkFlush(hand) && checkStraight(hand) ) return 4;
    return 0;
}

int isStraightFlush(int** hand) // 8
{
    if ( !checkFlush(hand) || !checkStraight(hand) ) return 0;
    return 8;
}

int isThreeOfAKind(int** hand) //3
{
    int *facesCount = generate_facesCount(hand);
    for ( int i = 0; i < FACES; i++ )
    {
        for ( int j = 0; j < FACES; j++ )
        {
            for ( int k = 0; k < FACES; k++ )
            {
                if (facesCount[i] == 3 && facesCount[j] == 1 && facesCount[k] == 1 )
                {
                    free(facesCount);
                    return 3;
                }
            }
        }
    }
    free(facesCount);
    return 0;
}

int isTwoPairs(int** hand) // 2
{
    int *facesCount = generate_facesCount(hand);
    for ( int i = 0; i < FACES; i++ )
    {
        for ( int j = 0; j < FACES; j++ )
        {
            for ( int k = 0; k < FACES; k++ )
            {
                if (facesCount[i] == 2 && facesCount[j] == 2 && facesCount[k] == 1
                    && i != j && j != k && i != k )
                    {
                        free(facesCount);
                        return 2;
                    }
            }
        }
    }
    free(facesCount);
    return 0;
}

int isPair(int** hand) // 1
{
    int *facesCount = generate_facesCount(hand);
    for ( int i = 0; i < FACES; i++ )
    {
        for ( int j = 0; j < FACES; j++ )
        {
            for ( int k = 0; k < FACES; k++ )
            {
                for ( int m = 0; m < FACES; m++ )
                {
                    if ( facesCount[i] == 2 && facesCount[j] == 1 && facesCount[k] == 1 && facesCount[m] == 1
                         && i != j && j != k && k!= m && i != k && i != m && j != m)
                         {
                                free(facesCount);
                                return 1;
                         }
                }
            }
        }
    }
    free(facesCount);
    return 0;
}

