#pragma once
#include "TClass.h"

class AActor
{
public:
	void Tick();


	// °ªÇü
	TClass<class Bullet*> Bullets;
};