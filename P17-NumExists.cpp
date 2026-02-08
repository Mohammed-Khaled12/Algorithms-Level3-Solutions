#include <iostream>
#include <limits>
using namespace std;

const int ROWS = 3, COLS = 3;

int readNumber()
{
    int num;
    cout << "Enter the number to Find in The matrix? \n";
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

int main()
{
    int arr[ROWS][COLS] = {{4, 0, 0}, {0, 4, 0}, {0, 0, 4}};

    cout << "Matrix: \n";
    printArray(arr);

    int num = readNumber();

    if (IsNumberExists(arr, num))
    {
        cout << "Yes, it exists\n";
    }
    else
    {
        cout << "No, it Not exists\n";
    }

    return 0;
}