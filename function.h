#include <iostream>
#include<ctime>
using namespace std;

const int SUITS = 4;
const int RANKS = 13;
const int CARDS = 52;

struct Cards_Element
{
    int Suit;
    int Rank;
};

//ShuffleCatds
int ** generateMatrix ( int row, int col);
int * generateArray(int block);

void shuffleCards(int deck[SUITS][RANKS]);
void output_matrix (int row, int col, int *a );

//OnePlayer
int ** generateMatrix ( int row, int col);
int ** dealingForHands(int deck[SUITS][RANKS]);
void printHand(int** hand, char* suits[], char* ranks[]);
