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

void multiplyArrays(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int multiplyArr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            multiplyArr[i][j] = arr1[i][j] * arr2[i][j];
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
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr1[ROWS][COLS];
    int arr2[ROWS][COLS];
    int multiplyArr[ROWS][COLS];

    fillArrayrandom(arr1);
    fillArrayrandom(arr2);
    multiplyArrays(arr1, arr2, multiplyArr);

    cout << "First Matrix: \n";
    printArray(arr1);

    cout << "Second Matrix: \n";
    printArray(arr2);

    cout << "Multiply Matrix: \n";
    printArray(multiplyArr);
}