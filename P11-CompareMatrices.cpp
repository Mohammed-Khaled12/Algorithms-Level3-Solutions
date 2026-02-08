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

int SumArray(int arr[ROWS][COLS])
{
    int sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
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

    // You Can Make a bool Function
    if (SumArray(arr1) == SumArray(arr2))
    {
        cout << "YES: both matrices are equal.\n";
    }
    else
    {
        cout << "No: matrices are NOT equal.\n";
    }
    
    // Using ternary operator "Short Hand if"
    // (SumArray(arr1) == SumArray(arr2))? cout << "YES: both matrices are equal.\n" : cout << "No: matrices are NOT equal.\n";
}