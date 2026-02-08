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
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }

        cout << "\n";
    }
}

void transposeMatrix(int arr[ROWS][COLS] , int arrTranspose[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arrTranspose[i][j] = arr[j][i];
        }
        
    }
    
}

int main()
{
    int arr[ROWS][COLS] , arrTranspose[ROWS][COLS];
    fillArrayOrdered(arr);
    
    cout << "The Following Is a " << ROWS << "x" << COLS <<  " Matrix: \n";
    printArray(arr);

    transposeMatrix(arr , arrTranspose);

    cout << "The Following Is a Transpose Matrix \n";
    printArray(arrTranspose);
}