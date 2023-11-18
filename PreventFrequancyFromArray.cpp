#include <iostream>
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

void FillArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Enter element number [" << i + 1 << "] : ";
        cin >> *(ptr + i);
    }
}

int FindNumberPositionInArray(int index, int *ptr, int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        if (*(ptr + i) == index)
            return i;
    }
    return -1;
}

bool IsNumberInArray(int Number, int *ptr, int arrlength)
{
    return FindNumberPositionInArray(Number, ptr, arrlength) != -1;
}

void AddArrayElement(int index, int *ptr_2, int& arr2Length)
{
    arr2Length++;
    *(ptr_2 + arr2Length - 1) = index;
}

void CreatNewArrayByRemoveFrequancyFromOldArray(int *ptr, int *ptr_2, int arr1length, int& arr2length)
{
    for (int i = 0; i < arr1length; i ++)
    {
        if (!IsNumberInArray(*(ptr + i), ptr_2, arr1length))
        {
            AddArrayElement(*(ptr + i), ptr_2, arr2length);
        }
    }
}

void PrintArray(int *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i ++)
        cout << *(ptr + i) << " ";
}

int main()
{
    int *ptr_1, *ptr_2, arr1Length = 0, arr2Length = 0;
    arr1Length = ReadPositiveNumber("How many number of array elements ?");
    ptr_1 = new int[arr1Length];
    ptr_2 = new int[arr2Length];
    FillArray(ptr_1, arr1Length);
    PrintArray(ptr_1, arr1Length);
    cout << "\n__________________________________\n";
    CreatNewArrayByRemoveFrequancyFromOldArray(ptr_1, ptr_2, arr1Length, arr2Length);
    PrintArray(ptr_2, arr2Length);
    delete[] ptr_2;
    delete[] ptr_1;
    return 0;
}