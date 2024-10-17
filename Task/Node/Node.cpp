#include <iostream>

// 자료구조는 [1] [0] [2] => 자료
// 배치하라.
// [1][0][2] 배치할께요. => 자료구조 vector
// [0][1][2] 배치할께요. => 자료구조 sorted list
// list와 vector는 완전히 동일한 자료구조 이론에서 자료구조로 보지도
// 자료구조라는 것은 애초에 자료구조는 기본적으로
// 100만개여도 1000만개도 동일하다.
// 프로그래밍에서의 자료구조의 이용법은 
// GPS가 대표적으로 자료구조를 기반으로 만들어지죠. KD트리나

// 공식적이지 않지만 2가지 메모리 구분하고
// 노드형과 배열형 
// 프로그래밍에서 실체를 가지려면 메모리에 존재해야 한다.
// N개의 S크기의 데이터가 있다면 배열형은 메모리를 인접시켜서 N*S만큼의 메모리를
// 완전히 붙여서 할당하면 => 배열

// 공식적으로 3가지 컨테이너로 분류합니다.
// 어떻게 구현하는건 중요하지 않는다.

// 대표적인 3대장은 List Vector Map
// 어떻게 구현해야한

// 연관 Map  
// 시퀀스 List vector
// 어뎁터

// 게임에서 가장 많이 사용되는 데이터 처리 형태
// C++ 어떠한 클래스가 자신의 계열에 속한 객체의 주소(참조) 포인터를
// N개 가지고 있으면 그걸 노드구조라고 합니다.
//class Player
//{
//    Player* Player;
//};

class Node
{
    // Node* LinkNode;
    Node* LinkNode[10];
};

class Zone
{
private:
    // 값형으로 들고 있으면 
    // Zone Has a의 개념중에서도 말그대로 내안에 완전히 들어 있는 것이다.

    // 한지역에 연결될수 있는 한계는
    // 정적 바인딩
    // 정적 메모리
    // 정적 배열
    // 코드가 실행되고 난 다음에 바꿀수 있나요 없나요?
    // 초보지역 딱 1개지역 
    // 누군가 상수를 말하면 => 변수로 생각하고 짜야 합니다.
    
    // 남은 4개의 메모리가 낭비가 된다.
    Zone* LinkZone[5] = {};

public:
    void Link(Zone* _Link)
    {

    }
};

class Town : public Zone
{
public:
    void InPlayer()
    {
        // 
       // FightZone Zone;
    }
};

class FightZone : public Zone
{

};

class Sword
{

};

class Shop
{
    Sword* SellItem;
};

class Player
{
    Sword* Item;
};

int main()
{
    Sword S;

    // 고급언어 C++의 목표 객체지향
    // 현실을 표현하려고 하는 것이다.
    // 인간적인 개념에 맞춰서 표현하려는것.

    // 자신이 코딩하려고 하는 모든 컨텐츠에서 동일하다.
    // 만드는것과 지우는건 비용(처리력) CPU에게 부탁 CPU내 부탁을 
    // 

    Town TZone;
    FightZone FZone;
    // Town TZone;
}
