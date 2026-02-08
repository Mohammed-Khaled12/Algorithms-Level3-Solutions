#include <iostream>
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

bool isIdentityMarix(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (i == j && arr[i][j] != 1)
            {
                return false;
            }
            else if (i != j && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[ROWS][COLS] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    cout << "Matrix: \n";
    printArray(arr);

    (isIdentityMarix(arr)) ? cout << "YES: Matrix is identity.\n" : cout << "No: Matrix is NOT identity.\n";
}