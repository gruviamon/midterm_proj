#include <iostream>
#include<ctime>
#include <stdlib.h>
using namespace std;

const int SUITS = 4;
const int FACES = 13;
const int CARDS = 52;
const int HANDS = 5;

struct Card
{
    int suit;
    int face;
};

//ShuffleCards
void shuffleCards(int deck[SUITS][FACES]);
void output_matrix (int row, int col, int a[SUITS][FACES] );
void printCards(int deck[SUITS][FACES], char* suits[], char* faces[]);

//OnePlayer
int ** dealingForHands(int deck[SUITS][FACES]);
void printHand(int** hand, char* suits[], char* FACES[]);
int ** createHandTest(int deck[SUITS][FACES], int a[HANDS]);

//check
int isStraightFlush(int** hand);    // 8
int isFourOfAKind(int** hand);      // 7
int isFullHouse(int** hand);        // 6
int isFlush(int** hand);            // 5
int isStraight(int** hand);         // 4
int isThreeOfAKind(int** hand);     // 3
int isTwoPairs(int** hand);         // 2
int isPair(int** hand);             // 1

//supportCheck
int* generate_suitsCount (int **hand);
int* generate_facesCount (int **hand);

int *Copy(int *a);
void sort_FacesAscending (int *hand);

int checkFlush(int** hand);
int checkStraight(int** hand);

int maxArray( int *a, int n );
int getHighestCard(int** hand);

//MultiPlayer
int*** dealingForHands_2(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);
int* rankingHands(int*** hands, int n);
int* evaluateHands(int *evaluate, int ***Players, int n);

//generate
int * generateArray(int number_of_element);
int ** generateMatrix ( int row, int col);

//Menu
void OnePlayer( int **hand, char* suits[], char* faces[], int deck[SUITS][FACES] );
void Menu(int &choice, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES]);
void MultiplePlayer( int*** Players, int numsofPlayers, char* suits[SUITS], char* faces[FACES], int deck[SUITS][FACES], int hasDealer);
bool checkinput( int choice, int Begin, int End );
void handle_input( int &choice, int Begin, int End );

//Dealer
Card drawCard(int card, int deck[SUITS][FACES]);
int** exchangeCard( int ** hand, Card a, int place );
void RandomExchange(int ** hand, char* suits[], char* faces[], int deck[SUITS][FACES], int n, int NumofCardtoExchange, string name);
void VoluntaryExchange(int ** hand, char* suits[], char* faces[], int deck[SUITS][FACES], int n, int NumofCardtoExchange, string name);
void changeCards(int **hand, int deck[SUITS][FACES], char*suits[SUITS], char*faces[FACES], int numofPlayers, string name);
int** dealingForHands_Dealer(int choice, int deck[SUITS][FACES]);
int** dealingForHands_Playler(int **Dealer, int deck[SUITS][FACES]);
bool matrixequal(int **a, int **b, int row, int col);
