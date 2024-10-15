#pragma once

// 템플릿 클래스는 헤더 CPP 분할이 되지 않아요.
// 이유가 있습니다. 

// 템플릿 클래스의 이름은 
// TClass<자료형>

// 이게 꼬이지 않게 하려고
// 템플릿 클래스의 코드 생성은 다른 모든 CPP가 코드를 생성하고 난후 합니다.
// Ex


template<typename DataType>
class TClass
{
public:
	// 헤더에서 다 구현해야 합니다.
	void Function(DataType _Actor)
	{
		DataType NewActor;
		NewActor = _Actor;
	}
};