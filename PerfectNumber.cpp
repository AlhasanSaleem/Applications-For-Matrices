#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    cout << Message << " : ";
    cin >> Number;

    while (Number < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one : ";
        cin >> Number;
    }
    
    return Number;
}

bool isPerfectNumber(int Number)
{
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }
    return Number == Sum;
}

void PrintPerfectNumberFrom1ToN(int Number)
{
    for (int i = 1; i < Number; i++)
    {
        if (isPerfectNumber(i))
            cout << i << "\n";
    }
}

int main()
{
    PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Please Enter a Positive Number"));
    return 0;
}