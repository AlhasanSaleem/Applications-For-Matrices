#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrimeOrNot(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;  
    }
    return enPrimeNotPrime::Prime;
}

int GetRandomNumbers(int From, int To)
{
    int RandomNum = rand() % (To - From + 1) + From;
    return RandomNum;
}

void FillArrayWithRandomNumbers(int *ptr, int& arrLength)
{
    cout << "Enter number of elements : ";
    cin >> arrLength;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one : ";
        cin >> arrLength;
    }
    

    for(int i = 0; i < arrLength; i++)
        *(ptr + i) = GetRandomNumbers(1, 100);
}

void PrintArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << *(ptr + i) << " ";
}

void CopyOnlyPrimeNumbers(int *ptr_1, int *ptr_2, int arrLength, int& arr2Length)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrimeOrNot(*(ptr_1 + i)) == enPrimeNotPrime::Prime)
        {
            *(ptr_2 + Counter) = *(ptr_1 + i);
            Counter++;
        }
    }
    arr2Length = --Counter;
}

int main()
{
    srand((unsigned)time(NULL));
    int *ptr_1, *ptr_2, arrLength, arr2Length;
    ptr_1 = new int[arrLength];
    ptr_2 = new int[arr2Length];
    FillArrayWithRandomNumbers(ptr_1, arrLength);
    PrintArray(ptr_1, arrLength);
    cout << "\n";
    CopyOnlyPrimeNumbers(ptr_1, ptr_2, arrLength, arr2Length);
    cout << "\nPrime Numbers in Array2 : ";
    PrintArray(ptr_2, arr2Length);
    delete[] ptr_2;
    delete[] ptr_1;
    return 0;
}