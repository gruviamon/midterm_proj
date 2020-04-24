#include"function.h"

// hand: suits[0]; faces[1]

int* generate_suitsCount (int **hand)
{
    char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int *suitsCount = generateArray(SUITS);
    for ( int i = 0; i < HANDS; i++ ) //count
    {
        for ( int j = 0; j < SUITS; j++ )
        {
            if ( suits[ hand[0][i] ] == suits[j] )
            {
                suitsCount[j]++;
            }
        }
    }
    return suitsCount;
}

int* generate_facesCount (int **hand)
{
    char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int *facesCount = generateArray(FACES);
    for ( int i = 0; i < HANDS; i++ ) //count
    {
        for ( int j = 0; j < FACES; j++ )
        {
            if ( faces[ hand[0][i] ] == faces[j] )
            {
                facesCount[j]++;
            }
        }
    }
    return facesCount;
}
int **Copy(int **a)
{
    int ** copy_a = generateMatrix(2, HANDS);
    for ( int i = 0; i < 2; i++)
    {
        for ( int j = 0; j < HANDS; j++)
        {
            *(*(copy_a + i) + j) = *(*(a + i) + j) ;
        }
    }

    return copy_a;
}

void deleteCopy (int **Copy)
{
    for ( int i = 0; i < HANDS; i++)
        delete []Copy[i];
    delete[]Copy;
}

void sort_FacesAscending (int **hand)
{
    for ( int i = 0; i < HANDS - 1; i++)
    {
        for ( int j = i + 1; j < HANDS; j++)
        {
            if (hand[1][i] > hand[1][j])
            {
                swap(hand[0][i] , hand[0][j]);
                swap(hand[1][i] , hand[1][j]);
            }
        }
    }
}

int checkFlush(int** hand) // 5
{
    int *suitsCount = generate_suitsCount(hand);
    for ( int i = 0; i < SUITS; i++ )
    {
        if (suitsCount[i] == 5 ) return 5; // true
    }
    return 0;
}

int checkStraight(int** hand) // 4
{
    int **hand_copy = Copy(hand);

    sort_FacesAscending(hand_copy);

    for ( int i = 0; i < 5 - 1; i++ )
    {
        if ( hand_copy[1][i+1] - hand_copy[1][i]  != 1 )
        {
            deleteCopy(hand_copy);
            return 0; // false
        }
    }
    deleteCopy(hand_copy);
    return 4;
}

int maxArray( int *a, int n )
{
    int Max = -sizeof(int);
    for ( int i = 0; i < n; i++)
    {
        Max = max(Max, *(a + i));
    }
    return Max;
}

int getHighestCard(int** hand)
{
    for ( int i = 0; i < HANDS; i++)
    {
        if ( hand[1][i] == 0 ) //check if has Ace in hand
            return i; // (i+1) th is the highest card in hand array
    }

    int Max = maxArray(&hand[1][0], HANDS);
    for ( int i = 0; i < HANDS; i++)
    {
        if ( hand[1][i] == Max )
            return i; // (i+1) th is the highest card in hand array
    }
}


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
                if ( suitsCount[i] == 2 && suitsCount[j] == 3 && i != j )
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
                if (facesCount[i] == 3 && facesCount[j] == 1 && facesCount[k] == 1 && i != j && j != k && i != k )
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
                if (facesCount[i] == 2 && facesCount[j] == 2 && facesCount[k] == 1 && i != j && j != k && i != k )
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
                    if ( facesCount[i] == 2 && facesCount[j] == 1 && facesCount[k] == 1 && facesCount[m] == 1 && i != j && j != k && k!= m && i != k && i != m && j != m)
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

