#pragma once
#include <EngineCore/Actor.h>
#include <BaseSystem/EngineMath.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
};

