// Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 보통 템플릿을 붙일수 있는 것은 2가지가 있습니다.
// 함수, 클래스

// 함수에 붙일때
// 참고로 전역함수 맴버함수 가리지 않고
// template<typename 메타> 메타 => 바뀔수 있는 메타
// template<typename 변수자료형이름> 과 같이 붙여주면 된다.
// 바뀌는 자료형을 대신할 부분만 지정한다.

// 템플릿 문법을 통해서 메타가 어느 곳인지 지정해준다.

// 코드량 <=> 컴파일 시간
//template<typename Type>
//void Print(Type _Value)
//{
//    std::cout << _Value << std::endl;
//}

// 특정 자료형을 처리할때 아래와같이 처리해라.
// 템플릿 특수화는 쉽게 말해서 템플릿이 코드를 만들어내기 전에 내가 먼저 만드는 것입니다.
// 템플릿 특수화
void Print(int _Value)
{
    std::cout << _Value << std::endl;
}

void Print(int* _Value)
{
    std::cout << _Value << std::endl;
}
//
//// 모든코드가 동일하지만 => 자료형만 달라지고 있다.
//// 여러번 치고 싶지가 않은 코드가 나온다.
//template<bool*>
//void Print(bool* _Value)
//{
//    std::cout << _Value << std::endl;
//}

// template<typename Type, typename Type0 = int>

//         자료형을 대표할 이름
template<typename Type>
class IntArray
{
public:
    Type* Values;

    void Test(Type _Test)
    {
        _Test;
    }
};


int main()
{
    // Array<Actor*> Array;

    // IntArray<int> Array;
    /*IntArray<short> Array;
    IntArray<int*> Array;
    IntArray<Actor*> Array;
    IntArray<Monster*> Array;*/



    //Print(10);

    //int* Ptr = nullptr;
    //Print(Ptr);

    //bool* bPtr = nullptr;
    //Print(bPtr);

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
