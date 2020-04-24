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



int * generateArray(int number_of_element)
{
    int* Array = (int*) calloc (number_of_element, sizeof(int));
    return Array;
}

int ** generateMatrix ( int row, int col)
{
    int **Matrix = new int* [row];
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = new int[col];
    }
    return Matrix;
}


int** dealingForHands(int deck[SUITS][FACES])
{
    shuffleCards(deck);

    int ** result = generateMatrix(2, HANDS);
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
    int ** result = generateMatrix(2,HANDS);
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
    int * ranking = rankingHands(Players, height);
    Congratulate(ranking, height);
    return TotalScore;
}

int Congratulate (int *ranking, int n)
{
    for ( int i = 0; i < n; i++)
    {
        if (ranking[i] == 1)
        {
            free (ranking);
            return i + 1;
        }
    }
    return 0;
}

