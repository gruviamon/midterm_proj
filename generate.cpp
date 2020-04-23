#include "function.h"

int * generateArray(int number_of_element)
{
    int* Array = (int*) calloc (number_of_element, sizeof(int));
    return Array;
}

int ** generateMatrix ( int row, int col)
{
    int **Matrix = new int* [row];
    for (int i = 0; i < row; i++)
    {
        Matrix[i] = new int[col];
    }
    return Matrix;
}
