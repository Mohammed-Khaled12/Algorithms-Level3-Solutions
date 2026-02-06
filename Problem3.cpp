#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

int getRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void fillArrayRandoms(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = getRandomNumber(1, 100);
        }
    }
}

void printArray(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int rowSum(int arr[3][3], short rowNum, short cols)
{
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
        sum += arr[rowNum][j];
    }
    return sum;
}

void sumMatrixRowsInArray(int arrSum[3], int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        arrSum[i] = rowSum(arr, i, cols);
    }
}

void printRowsSumArray(int arrSum[3], short size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Row " << i + 1 << " Sum= " << arrSum[i] << "\n";
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr[3][3], rows = 3, cols = 3;
    int arrSum[3];

    fillArrayRandoms(arr, rows, cols);

    cout << "The Follwing Is a 3x3 Matrix: \n";
    printArray(arr, rows, cols);

    sumMatrixRowsInArray(arrSum, arr, rows, cols);
    cout << "The Follwing Is a Sum of Each Row: \n";
    printRowsSumArray(arrSum, 3);
    return 0;
}