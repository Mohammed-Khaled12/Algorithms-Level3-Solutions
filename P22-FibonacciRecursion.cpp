#include <iostream>
using namespace std;

int FibRec(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return FibRec(n - 1) + FibRec(n - 2);
}

void FibLoop(int n)
{
    int fib = 0;
    int prev1 = 1, prev2 = 0;

    cout << "1 ";

    for (int i = 2; i <= n; i++)
    {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
        cout << fib << " ";
    }
}

int main()
{
    int n;
    cout << "Enter Number of Elements? \n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << FibRec(i) << " ";
    }
    cout << "\n";

    FibLoop(n);

    return 0;
}