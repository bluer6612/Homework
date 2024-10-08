﻿// 001_NumberCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 음수 안함
// 0 이외의 양수의 자릿수를 세자.
int NumberCount(int _Value)
{
    // /(나누기를 최대한) 연산을 사용하세요.
    int Result = 0;

    while (0 < _Value)
    {
        _Value /= 10;
        Result += 1;
    }

    return Result;
}

int NumberCount2(int _Value)
{
    // /(나누기를 최대한) 연산을 사용하세요.
    int Multiple = 1;
    int Result = 0;

    if (0 >= _Value)
    {
        return 0;
    }

    while (true)
    {
        if ((_Value / Multiple) >= 1)
        {
            Result += 1;
        }
        else {
            break;
        }

        Multiple *= 10;
    }

    return Result;
}

// 해도 되고 안해도 됩니다.
// 내 기준으로 지금
// _Value 를 넣어주면 Buffer에 
// 숫자를 문자열로 만드는 함수.
void NumberToString(char* Buffer, int BufferSize, int _Value)
{

    //std::cout << Buffer;
    return;
}

int main()
{
    // 9
    int Result0 = NumberCount(123583463);
    int Result1 = NumberCount2(123583463);
    // 3
    int Result2 = NumberCount(528);
    int Result3 = NumberCount2(528);
    // 0은 영
    int Result4 = NumberCount(0);

    char Buffer[100] = { 0 };
    
    NumberToString(Buffer, 100, 3712);
    //Buffer == "3712"
}