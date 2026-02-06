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

int main()
{
    srand(unsigned(time(NULL)));
    int arr[3][3];
    fillArrayrandom(arr, 3, 3);
    printArray(arr, 3, 3);
}