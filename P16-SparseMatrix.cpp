#include <iostream>
#include <limits>
using namespace std;

const int ROWS = 3, COLS = 3;

void printArray(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int countNum(int arr[ROWS][COLS], int num)
{
    int counter = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (num == arr[i][j])
            {
                counter++;
            }
        }
    }
    return counter;
}

bool isSparse(int arr[ROWS][COLS])
{
    int zerosCount = countNum(arr, 0);
    if (zerosCount > ((ROWS * COLS) / 2))
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[ROWS][COLS] = {{4, 0, 0}, {0, 4, 0}, {0, 0, 4}};

    cout << "Matrix: \n";
    printArray(arr);

    if (isSparse(arr))
    {
        cout << "The Matrix is Sparse\n";
    }
    else
    {
        cout << "The Matrix is Not Sparse\n";
    }

    return 0;
}