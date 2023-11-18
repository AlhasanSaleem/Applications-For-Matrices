#pragma once
#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Please enter a number : ";
    cin >> Number;

    while (cin.fail())
    {
        
    }
    
    return Number;
}

float MyABS(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;    
}

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

float MyRournd(float Number)
{
    int IntPart = int(Number);
    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) >= .5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;    
    }
    else
    {
        return IntPart;
    }
}

int MyFloor(float Number)
{
    if (Number > 0)
        return int(Number);
    else    
        return int(Number) - 1;    
}

int MyCeil(float Number)
{
    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);    
    }
    else
    {
        return int(Number);
    }
}

int MySqrt(int Number)
{
    return pow(Number, .5);
}

int MyPower(int Base, int Power)
{
    if (Power == 0)
        return 1;
    else
    {
        int x = (Base * MyPower(Base, Power - 1));
        return x;
    } 
}
