#include"function.h"

Card drawCard(int card, int deck[SUITS][FACES])
{
    Card a;
    for ( int i = 0; i < SUITS; i++)
        {
            for ( int j = 0; j < FACES; j++)
            {
                if ( deck[i][j] == card )
                {
                     a.suit = i;
                     a.face = j;
                }
            }
        }
    return a;
}

int** exchangeCard( int ** hand, Card a, int place )
{
    swap ( hand[0][place], a.suit );
    swap ( hand[1][place], a.face );
    return hand;
}

void RandomExchange(int ** hand, int deck[SUITS][FACES], char*suits[SUITS], char*faces[FACES], int n, int NumofCardtoExchange)
{
    for ( int i = 5*n + 5; i < 5*n + 5 + NumofCardtoExchange; i++ )
    {
        cout << "Now Dealer's card are: " << endl;
        printHand ( hand, suits, faces);
        Card a = drawCard(i, deck);
        int place;
        cout << "Choose place of card to exchange: ";
        cin >> place;
        hand = exchangeCard(hand, a, place);
    }
}
