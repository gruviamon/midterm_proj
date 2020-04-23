#include "function.h"

int*** dealingForHands_2(int deck[SUITS][FACES], int n)
{
    int *** Players = new int ** [n];
    for ( int i = 0; i < n; i++) // the (i + 1)_th player
    {
        int a[HANDS];
        for ( int j = 0; j < HANDS; j++) // the (j + 1)_th card
        {
            a[j] = j*n + i + 1;
        }

        Players[i] = createHandTest(deck, a);
    }
    return Players;
}

int getStatusOfHand(int** hand)
{
    if (isStraightFlush(hand)) return 8;
    if (isFourOfAKind(hand)) return 7;
    if (isFullHouse(hand)) return 6;
    if (isFlush(hand)) return 5;
    if (isStraight(hand)) return 4;
    if (isThreeOfAKind(hand)) return 3;
    if (isTwoPairs(hand) ) return 2;
    if (isPair(hand)) return 1;
    return 0;
}

int* rankingHands(int*** hands, int n) //hands [HANDS][SUITS][FACES]
{
    int *RANKS = generateArray(n);
    int Rank = 1;
    int status = 8;

    while (status >= 0 && Rank <= n)
    {
        for ( int i = 0; i < n; i++)
        {
            if ( getStatusOfHand(hands[i]) == status )
            {
                RANKS[i] = Rank++ ;
            }
        }

        status--;
    }

    return RANKS;
}
                                             //n         SUITS    FACES
int* evaluateHands(int s, int ***Players, int height, int row, int col)
{
    int * TotalScore = generateArray(s);
    for ( int i = 0; i < s; i++)
    {
        for ( int j = 0; j < height; j++)
        {
            TotalScore[i] += getStatusOfHand(Players[j]);
        }
    }

    return TotalScore;
}

int Congratulate (int ***Players, int n)
{
    int temp = 0;

    int *ranking = rankingHands(Players, n);

    for ( int i = 0; i < n; i++)
    {
        if (ranking[i] == 1)
        {
            //delete []ranking;
            return i + 1;
        }
    }
}
