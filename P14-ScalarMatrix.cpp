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

bool isScalarMarix(int arr[ROWS][COLS])
{
    int ref = arr[0][0];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (i == j && arr[i][j] != ref)
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
    int arr[ROWS][COLS] = {{4, 0, 0}, {0, 4, 0}, {0, 0, 4}};

    cout << "Matrix: \n";
    printArray(arr);

    (isScalarMarix(arr)) ? cout << "YES: Matrix is Scalar.\n" : cout << "No: Matrix is NOT Scalar.\n";
}