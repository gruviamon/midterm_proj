#include "function.h"

void OnePlayer ( int **hand, char* suits[], char* faces[], int deck[SUITS][FACES] )
{
    cout << "Cards are:\n";
    printHand(hand, suits, faces);
    cout << "\t ==> got: ";
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
    default: break;
    }
}

void MultiplePlayer( int*** Players, int n, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES] )
{

    int * ranking = rankingHands(Players, n);
    cout << "---------- RESULT ----------\n";
    for ( int i = 0; i < n; i++)
    {
        cout << "Player " << i + 1 << ": " << endl;
        OnePlayer(Players[i], suits, faces, deck);
        cout << "\tScore of player " << i + 1 << ": " << getStatusOfHand(Players[i]) << endl;
        cout << "\t==> Ranking of player " << i + 1 << ": " << ranking[i] << endl;
    }
    cout << "=====> The winner is: " << Congratulate(ranking, n) << endl;
}

void Menu( int choice, char* suits[], char* faces[], int deck[SUITS][FACES] )
{
    cout << "Select Mode:" << endl;
    cout << "0) Shuffle Cards" << endl;
    cout << "1) 1 PLAYER" << endl;
    cout << "2) MULTI PLAYER" << endl;
    cout << "3) MULTI PLAYER WITH DEALER" << endl;
    cout << "4) Exit" << endl;
    cout << " ==> Your Choice: ";
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
                break;
            }
        case 2:
            {
                int n, s;
                cout << "Number of Players( <= 10 ): ";
                cin >> n;
                cout << "1) Play one time\n2) Play multiple times\n3) Exit\n ==> Your Choice: ";
                cin >> (choice);
                switch (choice)
                {
                case 1:
                    {
                        shuffleCards(deck);
                        int ***Players = dealingForHands_2(deck, n);
                        MultiplePlayer(Players, n, suits, faces, deck);
                        break;
                    }

                case 2:
                    {
                        cout << "Number of play times : ";
                        cin >> s;
                        for ( int i = 0; i < s; i++)
                        {
                            cout <<" -------ROUND " << i + 1 << "-------" << endl;
                            shuffleCards(deck);
                            int ***Players = dealingForHands_2(deck, n);
                            MultiplePlayer(Players, n, suits, faces, deck);
                        }
                        break;
                    }

                }
                break;
            }
         case 3:
            {
                int n, num;
                cout << "Number of Players (<= 9) : ";
                cin >> n;
                shuffleCards(deck);

                int ***Players = dealingForHands_2(deck, n + 1); // n players + 1 Dealer
                cout << "Now Dealer's cards are (NOTE: Player " << n+1 << " is the Dealer): " << endl;
                printHand ( Players[n], suits, faces);
                cout << "Numbers of Cards that Dealer can exchange (<= 3): " ;
                cin >> num;

                cout << "1) random replacement\n2) replace to get better situation\n ==> Your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    {
                        RandomExchange(Players[n], deck, suits, faces, n + 1, num); // Player[n] is Dealer
                        cout << "Now Dealer's cards are: " << endl;
                        printHand ( Players[n], suits, faces);

                        MultiplePlayer(Players, n+1, suits, faces, deck);
                        break;
                    }

                case 2:
                    {
                        for ( int i = 5*n + 5; i < 5*n + 5 + num; i++)
                        {
                            cout << "Now Dealer's cards are: " << endl;
                            printHand ( Players[n], suits, faces);
                            Card a = drawCard(i, deck);
                            cout << "Dealer has just drawn ("<< suits[a.suit] <<", " << faces[a.face] <<") \n";
                            cout << "Do Dealer wants to keep this card?\n1) Yes\n2) No\n ==> Your choice: ";
                            cin >> choice;
                            if ( choice == 1 )
                            {
                                int place;
                                cout << "Choose place of card to exchange: " ;
                                cin >> place;
                                Players[n] = exchangeCard(Players[n], a, place);
                            }
                        }
                        cout << "Now Dealer's cards are: " << endl;
                        printHand ( Players[n], suits, faces);

                        MultiplePlayer(Players, n+1, suits, faces, deck);
                        break;
                    }
                }

            }

        }
}
