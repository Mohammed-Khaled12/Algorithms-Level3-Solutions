#include <iostream>
#include <limits>
using namespace std;

const int ROWS = 3, COLS = 3;

int readNumber()
{
    int num;
    cout << "Enter the number to count in matrix? \n";
    cin >> num;

    while (cin.fail())
    {

        cin.clear();

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid input! Please enter a numeric value: ";
        cin >> num;
    }
    return num;
}

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

int countNum(int arr[ROWS][COLS], int num)
{
    int counter = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (num == arr[i][j])
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    int arr[ROWS][COLS] = {{4, 0, 0}, {0, 4, 0}, {0, 0, 4}};
    int num = readNumber();

    cout << "Matrix: \n";
    printArray(arr);

    cout << "Number " << num << " count in matrix is " << countNum(arr, num) << "\n";
}