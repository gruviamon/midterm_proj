#include "function.h"

int main()
{
    char* suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    char* faces[FACES] = {"Ace", "Two", "Three", "Four", "Five",
                          "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    //1.1
    int deck[SUITS][FACES] ;
    //REMEMBER_TO_DELETE_IT(deck);
    //output_matrix(SUITS, FACES, deck);
/*
    shuffleCards(deck);
    output_matrix(SUITS, FACES, deck);

    //1.2
    printCards(deck, suits, faces);

    //2.1.a
    dealingForHands(deck);
    //2.1.b
    int **Hand = dealingForHands(deck);
    printHand(Hand, suits, faces);
    //2.1.c
    int a[] = {43, 44, 1, 15, 29};
    cout << "a = 21, 1, 23, 7, 28 \n";

    int **Hand = createHandTest(deck, a); //error in here
    printHand(Hand, suits, faces);

    cout << "FourOfAKind: " << isFourOfAKind(Hand)<<endl;
    cout << "FullHouse: " << isFullHouse(Hand) << endl;
    cout << "Flush: " << isFlush(Hand) << endl;
    cout << "Straight: " << isStraight(Hand) << endl;
    cout << "StraightFlush: " << isStraightFlush(Hand) << endl;
    cout << "ThreeOfAKind: " << isThreeOfAKind(Hand) << endl;
    cout << "TwoPairs: " << isTwoPairs(Hand) << endl;
    cout << "Pair: " << isPair(Hand) << endl;
    cout << "the HIGHESTCARD is the :" << getHighestCard(Hand) << endl;
*/
    shuffleCards(deck);
    output_matrix(SUITS, FACES, deck);

    int n;
    cout << "Nhap so nguoi choi( <= 10 ): ";
    cin >> n;

    int ***Players = dealingForHands_2(deck, n);

    for ( int i = 0; i < n; i++)
    {
        cout << "Score of player" << getStatusOfHand(Players[i]) << ' ';
    }

        cout << endl;

    int * ranking = rankingHands(Players, n);

    for ( int i = 0; i < n; i ++)
    {
        cout << "Ranking of player "<< ranking[i] << ' ';
    }
    cout << endl;

    cout << "The winner is: " << Congratulate(Players, n);

//    int s;
//    cout << "Nhap so lan choi ";
//    cin >> s;
//    int result[n];
//    for ( int i = 0; i < s; i++)
//    {
//        shuffleCards(deck);
//        output_matrix(SUITS, FACES, deck);
//
//        Players = dealingForHands(deck, n);
//
//        for ( int j = 0; j < n; j++)
//        {
//            result[j] = getStatusOfHand(Players[j]);
//        }
//
//        rankingHands( Players , n); // error in here
//        evaluateHands(s, Players, n, SUITS, FACES);
//        Congratulate(Players, n, i);
//        cout << endl;

//    }
}


