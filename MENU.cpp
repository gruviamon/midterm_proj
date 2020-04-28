#include "function.h"

void OnePlayer ( int **hand, char* suits[], char* faces[], int deck[SUITS][FACES] )
{
    cout << "Cards are:\n";
    printHand(hand, suits, faces);
    cout << "\t ==> got: " ;
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
            cout << "\t The hightest card: " << getHighestCard(hand) << endl;
            break;
        }
    default: break;
    }
}

void MultiplePlayer( int*** Players, int numsofPlayers, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES], int hasDealer)
{
    cout << "-------------------- RESULT ---------------------\n\n";
    for ( int i = 0; i < numsofPlayers; i++)
    {
        cout << "Player " << i + 1 ;
        if (i == numsofPlayers - 1 && hasDealer) cout << " (Dealer) ";
        cout << ": \n";
        OnePlayer(Players[i], suits, faces, deck);
    }
    int * ranking = rankingHands(Players, numsofPlayers);
    cout << "\n*** Ranking of players *** \n";
    for ( int i = 1; i < numsofPlayers + 1; i++)
    {
        for ( int j = 0; j < numsofPlayers; j++)
        {
            if (ranking[j] == i)
            {
                cout << "\t" << ranking[j] << ") Player " << j + 1 << " (Score = " << getStatusOfHand(Players[j]) << ") " ;
                if (j == numsofPlayers - 1 && hasDealer) cout << "(Dealer) ";
                cout << endl;
            }
        }
    }
    free(ranking);
}

void Menu( int &choice, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES] )
{
    cout << "\nSelect Mode:" << endl;
    cout << "\t0) Shuffle Cards" << endl;
    cout << "\t1) Print Cards" << endl;
    cout << "\t2) 1 PLAYER" << endl;
    cout << "\t3) MULTIPLE-PLAYER" << endl;
    cout << "\t4) MULTIPLE-PLAYER WITH DEALER" << endl;
    cout << "\t5) 1-PLAYER WITH DEALER" << endl;
    cout << "\tOther numbers) Exit" << endl;
    cout << " ==> Your Choice: ";

    cin >> choice;
        switch(choice)
        {
        case 0:
            {
                shuffleCards(deck);
                cout << "=> Cards has been shuffled\n";
                break;
            }
        case 1:
            {
                printCards(deck, suits, faces);
                break;
            }
        case 2:
            {
                cout << "Select Mode:" << endl;
                cout << "\t1) Random Hand Test" << endl;
                cout << "\t2) Input Hand Test" << endl;
                cout << "\tOther numbers) Exit" << endl;
                cout << " ==> Your Choice: " ;
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
                        cout << "Insert 5 cards order: ";
                        for ( int i = 0; i < HANDS; i++)
                            cin >> a[i];
                        int **Hand = createHandTest(deck, a);
                        OnePlayer(Hand, suits, faces, deck);
                        break;
                    }
                }
                break;
            }
        case 3:
            {
                int n, s;
                cout << "Number of Players ( 0 <= n <= 10 ): ";
                cin >> n;
                handle_input(n, 0, 10);
                cout << "\t1) Play one time" << endl;
                cout << "\t2) Play multiple times (Cards will be shuffled automatically each time)" << endl;
                cout << "\tOther numbers) Exit" << endl;
                cout << " ==> Your Choice: " ;
                cin >> (choice);
                switch (choice)
                {
                case 1:
                    {
                        //shuffleCards(deck);
                        int ***Players = dealingForHands_2(deck, n);
                        MultiplePlayer(Players, n, suits, faces, deck, 0); //dont have dealer => there are n players
                        break;
                    }

                case 2:
                    {
                        cout << "Number of play times : ";
                        cin >> s;
                        cin.ignore();
                        int *evaluate = generateArray(n);
                        for ( int i = 0; i < s; i++)
                        {
                            cout <<"-------------------- ROUND " << i + 1 << " --------------------" << endl;
                            shuffleCards(deck); // NOTE THIS !!!!

                            int ***Players = dealingForHands_2(deck, n);
                            MultiplePlayer(Players, n, suits, faces, deck, 0); //dont have dealer => there are n players
                            evaluate = evaluateHands(evaluate, Players, n);
                            system("pause");
                            if ( i == (s - 1) )
                            {
                                cout << "\nPress any key to see the final result\n";
                                system("pause");
                                cout << "--------------------- SUMMARY ---------------------\n";
                                int MaxScore = maxArray(evaluate, n);
                                for ( int k = maxArray(evaluate, n); k >= 0; k--) // output by descending order of evaluate array
                                {
                                    for ( int j = 0; j < n; j++)
                                        if ( k == evaluate[j] )
                                            cout << "\tTotal score of Player " << j + 1 << ": " << evaluate[j] << endl;
                                }
                                cout << "=======> The WINNER(s) is/ are: ";
                                for ( int j = 0; j < n; j++)
                                    if (evaluate[j] == MaxScore)
                                        cout << "Player " << j + 1 << " " ;
                                cout << endl;
                            }
                        }
                        free (evaluate);
                        break;
                    }
                }
                break;
            }
        case 4:
            {
                int n, num;
                cout << "Number of Players (0 <= n <= 9) : ";
                cin >> n;
                handle_input(n, 0, 9);
                int ***Players = dealingForHands_2(deck, n + 1); // n players + 1 Dealer
                cout << "(NOTE: Player " << n + 1 << " is the Dealer) \n";
                changeCards(Players[n], deck, suits, faces, n + 1, "Dealer"); //there are n+1 players
                cout << "\nPress any key to see the result\n";
                system("pause");
                MultiplePlayer(Players, n + 1, suits, faces, deck, 1); //has dealer
                break;
            }
        case 5:
            {
                cout << "Choose Level: " << endl;
                cout << "1) easy\t\t2) medium\t 3) hard" << endl;
                cout << " ==> Your Choice: " ;
                cin >> choice;
                handle_input(choice, 1, 3);
                int ***Players = new int **[2];
                for ( int i = 0; i < 2; i++ ) Players[i] = generateMatrix(5, 2);
                Players[1] = dealingForHands_Dealer(choice, deck); //Dealer_Hand, choice = level;
                Players[0] = dealingForHands_Playler(Players[1], deck); //Player_Hand
                cout << "(NOTE: Player 1 is you, Player 2 is the Dealer) \n";
                changeCards(Players[0], deck, suits, faces, 2, "Player"); //there are 2 players
                cout << "\nPress any key to see the result\n";
                system("pause");
                MultiplePlayer(Players, 2, suits, faces, deck, 1); //has dealer
                if (getStatusOfHand(Players[0]) == getStatusOfHand(Players[1])) cout << "\tIt's a tie\n";
                break;
            }
        default:
            {
                cout << "\t\t  THANK YOU FOR PLAYING!!!\n\t\t\t SEE YOU NEXT TIME\n";
                break;
            }
        }
}

bool checkinput( int choice, int Begin, int End)
{
    if ( choice < Begin || choice > End) return false;
    return true;
}

void handle_input( int &choice, int Begin, int End )
{
    while ( !checkinput(choice, Begin, End) )
    {
        cout << "Please choose again: ";
        cin >> choice;
    }
}

