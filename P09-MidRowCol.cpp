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
}

void printMiddleCol(int arr[ROWS][COLS])
{
    int middleCol = COLS / 2;

    for (int i = 0; i < ROWS; i++)
    {
        printf("%0*d \n", 2, arr[i][middleCol]);
    }
    cout << "\n";
}

void printMiddleRow(int arr[ROWS][COLS])
{
    int middleRow = ROWS / 2;

    for (int i = 0; i < COLS; i++)
    {
        printf("%0*d ", 2, arr[middleRow][i]);
    }
    cout << "\n";
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr[ROWS][COLS];

    fillArrayrandom(arr);

    cout << "Matrix: \n";
    printArray(arr);

    cout << "Middle Row: \n";
    printMiddleRow(arr);

    cout << "Middle Column: \n";
    printMiddleCol(arr);
}