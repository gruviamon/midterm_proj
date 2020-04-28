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

void RandomExchange(int ** hand, char* suits[], char* faces[], int deck[SUITS][FACES], int n, int NumofCardtoExchange , string name)
{
    for ( int i = 5*n + 1; i < 5*n + 1 + NumofCardtoExchange; i++ )
    {

        Card a = drawCard(i, deck);
        int place;
        cout << "Choose place of card to exchange: ";
        cin >> place;
        hand = exchangeCard(hand, a, place);
        if ( i == 5*n + NumofCardtoExchange) cout << "***END OF CHANGING***\n";
        cout << "Now " << name <<"'s card are: " << endl;
        printHand(hand, suits, faces);
    }
}

void VoluntaryExchange(int ** hand, char* suits[], char* faces[], int deck[SUITS][FACES], int n, int NumofCardtoExchange, string name)
{
    for ( int i = 5*n + 1; i < 5*n + 1 + NumofCardtoExchange; i++)
    {
        Card a = drawCard(i, deck);
        cout << name << " has just drawn ("<< suits[a.suit] <<", " << faces[a.face] <<") \n";
        cout << "Does " << name << " want to keep this card?\n1) Yes\t0) No\n ==> Your choice: ";
        int choice;
        cin >> choice;
        handle_input(choice, 0, 1);
        if ( choice == 1 )
        {
            int place;
            cout << "Choose place of card to exchange: " ;
            cin >> place;
            hand = exchangeCard(hand, a, place);
        }
        if ( i == 5*n + NumofCardtoExchange) cout << "***END OF CHANGING***\n";
        cout << "Now " << name <<"'s cards are: " << endl;
        printHand (hand, suits, faces);
    }
}

void changeCards(int **hand, int deck[SUITS][FACES], char* suits[], char* faces[], int numofPlayers, string name)
{
    cout << "Now " << name << " cards are:" << endl;
    printHand ( hand, suits, faces);
    cout << "Numbers of Cards that " << name << " wants to exchange (<= 3): " ;
    int num;
    cin >> num;
    handle_input(num, 0, 3);
    if ( num != 0 )
    {
        cout << "1) random replacement\n2) replace to get better situation\n ==> Your choice: ";
        int choice;
        cin >> choice;
        handle_input(choice, 1, 2);
        switch (choice)
        {
        case 1:
            {
                RandomExchange(hand, suits, faces, deck, numofPlayers, num, name); // Player[n] is Dealer
                break;
            }
        case 2:
            {
                VoluntaryExchange(hand,suits, faces, deck, numofPlayers, num, name);
                break;
            }
        }
    }
}

int** dealingForHands_Dealer(int choice, int deck[SUITS][FACES])
{
    int min_score, max_score;
    switch (choice) //determine score of Dealer based on levels
    {
    case 1: // easy
        {
            min_score = 0;
            max_score = 1;
            break;
        }
    case 2: // medium
        {
            min_score = 2;
            max_score = 4;
            break;
        }
    case 3: // difficult
        {
            min_score = 5;
            max_score = 8;
            break;
        }
    }
    int ** hands = generateMatrix(2, 5);
    do hands = dealingForHands(deck); while ((getStatusOfHand(hands) < min_score) || (getStatusOfHand(hands) > max_score));
    return hands;
}

bool checkSameCard(int **a, int **b, int deck[SUITS][FACES])
{
    for ( int i = 0; i < HANDS; i++)
        for ( int j = 0; j < HANDS; j++)
            if ( deck[ a[0][i] ][ a[1][i] ] == deck[ a[0][j] ][ a[1][j] ]) return false;
    return true;
}

int** dealingForHands_Playler(int **Dealer, int deck[SUITS][FACES])
{
    int **Player = generateMatrix(2,5);
    do {
        Player = dealingForHands(deck);
    } while (checkSameCard(Player, Dealer, deck));
    return Player;
}
