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

bool isPalindrome(int Matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][COLS - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int Matrix[ROWS][COLS] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};

    cout << "Matrix: \n";
    printArray(Matrix);

    if (isPalindrome(Matrix))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    

    return 0;
}