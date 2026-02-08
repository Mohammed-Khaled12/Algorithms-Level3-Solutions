#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int ROWS = 3, COLS = 3;

int getRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void fillArrayrandom(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = getRandomNumber(1, 10);
        }
    }
}

void printArray(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%0*d ", 2, arr[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

bool AreTypicalMatrices(int arr1[ROWS][COLS], int arr2[ROWS][COLS])
{
    bool isTypical = 1;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                isTypical = 0;
                return isTypical;
            }
        }
    }
    return isTypical;
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr1[ROWS][COLS];
    int arr2[ROWS][COLS];

    fillArrayrandom(arr1);
    fillArrayrandom(arr2);

    cout << "Matrix 1: \n";
    printArray(arr1);
    cout << "Matrix 2: \n";
    printArray(arr2);

    if (AreTypicalMatrices(arr1, arr2))
    {
        cout << "YES: both matrices are Typical.\n";
    }
    else
    {
        cout << "No: matrices are NOT Typical.\n";
    }

    // YOU CAN USE TERNARY OPERATOR "SHORT HAND IF"
    // (AreTypicalMatrices(arr1, arr2)) ? cout << "YES: both matrices are Typical.\n" : cout << "No: matrices are NOT Typical.\n";
}