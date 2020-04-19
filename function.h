#include <iostream>
#include<ctime>
using namespace std;

const int SUITS = 4;
const int RANKS = 13;
const int CARDS = 52;

int * generateArray(int row,int col);
void shuffleCards(int deck[SUITS][RANKS]);
void output_matrix ( int a[SUITS][RANKS], int row, int col);
