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

int findMax(int Matrix[ROWS][COLS])
{
    int max = Matrix[0][0];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (Matrix[i][j] > max)
            {
                max = Matrix[i][j];
            }
        }
    }

    return max;
}

int findMin(int Matrix[ROWS][COLS])
{
    int min = Matrix[0][0];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (Matrix[i][j] < min)
            {
                min = Matrix[i][j];
            }
        }
    }

    return min;
}

int main()
{
    int Matrix[ROWS][COLS] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};

    cout << "Matrix: \n";
    printArray(Matrix);

    cout << "Max Numbers Is: " << findMax(Matrix) << "\n";
    cout << "MIn Numbers Is: " << findMin(Matrix) << "\n";

    return 0;
}