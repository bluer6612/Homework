#pragma once
#include <EngineCore/Actor.h>

class Bullet : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
};

