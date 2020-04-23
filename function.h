#include <iostream>
#include<ctime>
#include <stdlib.h>
using namespace std;

const int SUITS = 4;
const int FACES = 13;
const int CARDS = 52;
const int HANDS = 5;

struct Cards_Element
{
    int Suit;
    int Rank;
};

void REMEMBER_TO_DELETE_IT(int deck[SUITS][FACES]);

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

void deleteCopy (int **Copy);
int **Copy(int **a);
void sort_FacesAscending (int **hand);

int checkFlush(int** hand);
int checkStraight(int** hand);

int maxArray( int *a, int n );
int getHighestCard(int** hand);

//MultiPlayer
int*** dealingForHands_2(int deck[SUITS][FACES], int n);
int getStatusOfHand(int** hand);
int* rankingHands(int*** hands, int n);
int* evaluateHands(int s, int ***Players, int height, int row, int col);
int Congratulate (int ***Players, int n);

//generate
int * generateArray(int number_of_element);
int ** generateMatrix ( int row, int col);
