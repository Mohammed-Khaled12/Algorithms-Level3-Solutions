#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int const ROWS = 3, COLS = 3;

int getRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void fillArrayrandom(int arr[ROWS][COLS], short rows, short col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = getRandomNumber(1, 100);
        }
    }
}

void printArray(int arr[ROWS][COLS], short rows, short col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << "\n";
    }
}

int colSum(int arr[ROWS][COLS], short row, short colnum)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += arr[i][colnum];
    }
    return sum;
}

void sumMatrixColsInArray(int arrSum[COLS], int arr[ROWS][COLS], short rows, short cols)
{
    for (int i = 0; i < cols; i++)
    {
        arrSum[i] = colSum(arr, rows, i);
    }
}

void printColsSumArray(int arrSum[COLS], short size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Column " << i + 1 << " Sum= " << arrSum[i] << "\n";
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr[ROWS][COLS];
    int arrSum[COLS];

    fillArrayrandom(arr, ROWS, COLS);

    cout << "The Follwing Is a 3x3 Matrix: \n";
    printArray(arr, ROWS, COLS);

    sumMatrixColsInArray(arrSum, arr, ROWS, COLS);
    cout << "The Follwing Is a Sum of Each Column: \n";
    printColsSumArray(arrSum, 3);
}