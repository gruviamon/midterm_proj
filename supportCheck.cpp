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

