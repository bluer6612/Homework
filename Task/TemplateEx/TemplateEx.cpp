// TemplateEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "TClass.h"
#include "AActor.h"

// 템플릿 주의사항

template<typename DataType>
DataType Function(DataType _Data)
{
    std::cout << _Data << std::endl;
    return _Data;
}

template<typename DataType>
class MyClass
{
public:
    DataType Data;
};

int main()
{
    // MyClass 
    // 컴파일러가 MyClass<int>라는 클래스를 만들어내는 것.
    MyClass<int> NewInt;

    // Function<int>(10);
    // 템플릿 함수는 명시적으로 하면 위와 같이 사용해야 하지만
    Function(10);

    // 템플릿 인자추론
    // 템플릿이 이미 무슨자료형인지 추론한다는 것입니다.
    Function<char>('C');

    // 이 스택에서 지역변수가 n바이트 사용되었다. => 고정되어 있는 문법들이 있어야 한다.
    // 명확하게 템플릿의 타입을 명확하게 지정해주지 않으면 안된다.
    MyClass<int> NewMyClass = MyClass<int>();

    TClass<AActor> TestValue;

    AActor NewActor;

    TestValue.Function(NewActor);

    //int Value;
    //char Arr[Value];
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
