#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int getRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void fillArrayrandom(int arr[3][3], short rows, short col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = getRandomNumber(1, 100);
        }
    }
}

void printArray(int arr[3][3], short rows, short col)
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

int rowSum(int arr[3][3], short rowNum, short col)
{
    int sum = 0;
    for (int j = 0; j < col; j++)
    {
        sum += arr[rowNum][j];
    }
    return sum;
}

void printRowSum(int arr[3][3], short rows, short col)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " = " << rowSum(arr, i, col) << "\n";
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    int arr[3][3];
    fillArrayrandom(arr, 3, 3);

    cout << "The Follwing Is a 3x3 Matrix: \n";
    printArray(arr, 3, 3);

    cout << "\n";

    cout << "The Follwing Is a Sum of Each Row: \n";
    printRowSum(arr, 3, 3);
}