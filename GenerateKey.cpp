#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

int GetRandomNumber(int From, int To)
{
    int RandomNum = rand() % (To - From + 1) + From;
    return RandomNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter :
        return GetRandomNumber(97, 122);
        break;
    case enCharType::CapitalLetter :
        return GetRandomNumber(65, 90);
        break;
    case enCharType::SpecialCharacter :
        return GetRandomNumber(33, 47);
        break;
    case enCharType::Digit :
        return GetRandomNumber(48, 57);
        break;
    }
    return CharType;
}

string GenrateWord(enCharType CharType, short Length)
{
    string Word = "";
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";
    Key = Key + GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenrateWord(enCharType::CapitalLetter, 4) + "-";
    Key += GenrateWord(enCharType::CapitalLetter, 4);

    return Key;
}

void FillArrayWtihKeys(string *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        *(ptr + i) = GenerateKey();
}

void PrintArray(string *ptr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << "Array ["<< i + 1 << "]  " << *(ptr + i) << ".\n";
}

int main()
{
    srand((unsigned)time(NULL));
    string *ptr;
    int arrlength;
    arrlength = ReadPositiveNumber("Pleaes enter how many keys to generate");
    ptr = new string[arrlength];
    FillArrayWtihKeys(ptr, arrlength);
    PrintArray(ptr, arrlength);
    delete[] ptr;
    return 0;
}