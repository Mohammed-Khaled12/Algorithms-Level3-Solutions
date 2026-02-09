#include <iostream>
#include <iomanip>
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

bool IsNumberExists(int arr[ROWS][COLS], int num)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (num == arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

void printIntersected(int arr1[ROWS][COLS], int arr2[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (IsNumberExists(arr2, arr1[i][j]))
            {
                cout << setw(3) << arr1[i][j] << "  ";
            }
        }
    }
    cout << "\n";
}

int main()
{
    int Matrix1[ROWS][COLS] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    int Matrix2[ROWS][COLS] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};

    cout << "Matrix 1: \n";
    printArray(Matrix1);
    cout << "Matrix 2: \n";
    printArray(Matrix2);

    cout << "Intersected NUmbers are: \n";

    printIntersected(Matrix1, Matrix2);

    return 0;
}