#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3 , COLS = 3;

void fillArrayOrdered(int arr[ROWS][COLS])
{
    int counter = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            counter++;
            arr[i][j] = counter; 
        }
    }
}

void printArray(int arr[ROWS][COLS])
{
    cout << "The Follwing Is a " << ROWS << "x" << COLS <<  " Matrix: \n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    int arr[ROWS][COLS];
    fillArrayOrdered(arr);
    printArray(arr);
}