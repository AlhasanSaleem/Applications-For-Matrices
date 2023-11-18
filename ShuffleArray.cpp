#include <iostream>
#include <cstdlib>
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

void Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

int GetRandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From ;
    return RandomNumber;
}

void FilArrayWith1ToN(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        *(ptr + i) = i + 1;
}


void ShuffleArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(*(ptr + (GetRandomNumber(1, arrLength) - 1)), *(ptr + (GetRandomNumber(1, arrLength) - 1)));
    }
}

void PrintArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << *(ptr + i) << " ";
}

int main()
{
    srand((unsigned)time(NULL));
    int *ptr;
    int arrLength = ReadPositiveNumber("Enter number of elements");
    ptr = new int[arrLength];
    FilArrayWith1ToN(ptr, arrLength);
    PrintArray(ptr, arrLength);
    cout << "\n____________________________\n";
    ShuffleArray(ptr, arrLength);
    PrintArray(ptr, arrLength);
    delete[] ptr;
    return 0;
}