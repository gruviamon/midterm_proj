#include "function.h"

void OnePlayer ( int **hand, char* suits[], char* faces[], int deck[SUITS][FACES] )
{
    cout << "Your cards are:\n";
    printHand(hand, suits, faces);
    cout << "You got: ";
    switch (getStatusOfHand( hand ))
    {
    case 8:
        {
            cout << "Straight Flush "<< endl;
            break;
        }
    case 7:
        {
            cout << "Four of a kind "<< endl;
            break;
        }
    case 6:
        {
            cout << "Full House "<< endl;
            break;
        }
    case 5:
        {
            cout << "Flush "<< endl;
            break;
        }
    case 4:
        {
            cout << "Straight "<< endl;
            break;
        }
    case 3:
        {
            cout << "Three of a kind "<< endl;
            break;
        }
    case 2:
        {
            cout << "Two Pairs "<< endl;
            break;
        }
    case 1:
        {
            cout << "Pair "<< endl;
            break;
        }
    case 0:
        {
            cout << "None "<< endl;
            cout << "The hightest card is the " << getHighestCard(hand) << "card" << endl;
            break;
        }
    default:
        {
            cout << "Nothing " << getStatusOfHand(hand);
        }
    }
}

void MultiplePlayer( int n, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES] )
{
    shuffleCards(deck);
    int ***Players = dealingForHands_2(deck, n);
    int * ranking = rankingHands(Players, n);
    for ( int i = 0; i < n; i++)
    {
        cout << "Score of player " << i + 1 << ": " << getStatusOfHand(Players[i]) << endl;
        cout << "==> Ranking of player " << i + 1 << ": " << ranking[i] << endl;
    }
    cout << "=====> The winner is: " << Congratulate(Players, n) << endl;
}

void Menu( int choice, char* suits[], char* faces[], int deck[SUITS][FACES] )
{
    cout << "Select Mode:" << endl;
    cout << "0) Shuffle Cards\n1) 1 PLAYER\n2) MULTI PLAYER\n ==> Your Choice: ";
    cin >> choice;
        switch(choice)
        {
        case 0:
            {
                shuffleCards(deck);
                printCards(deck, suits, faces);
                break;
            }
        case 1:
            {
                cout << "Select Mode:\n1) Random Hand Test\n2) Input Hand Test\n ==> Your Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    {
                        int **Hand = dealingForHands(deck);
                        OnePlayer(Hand, suits, faces, deck);
                        break;
                    }

                case 2:
                    {
                        int a[HANDS];
                        cout << "Insert 5 cards order :";
                        for ( int i = 0; i < HANDS; i++)
                            cin >> a[i];
                        int **Hand = createHandTest(deck, a);
                        OnePlayer(Hand, suits, faces, deck);
                        break;
                    }
                }
            }
        case 2:
            {
                int n, s;
                cout << "Nhap so nguoi choi( <= 10 ): ";
                cin >> n;
                cout << "1) Choi 1 lan\n2) Choi nhieu lan \n ==> Your Choice: ";
                cin >> (choice);
                switch (choice)
                {
                case 1:
                    {
                        MultiplePlayer(n, suits, faces, deck);
                    }

                case 2:
                    {
                        cout << "Nhap so lan choi: ";
                        cin >> s;
                        for ( int i = 0; i < s; i++)
                        {
                            cout <<"ROUND " << i + 1 << endl;
                            MultiplePlayer(n, suits, faces, deck);
                        }
                    }
                }
            }
        }
}
