#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Renderer.h>

class RenderTarget : public AActor
{
public:
	void SetPixel(FIntPoint _Point, char _Value);
	void BeginPlay() override;
	void Tick() override;

	Renderer* TargetRender = nullptr;

	ConsoleImage* GetImage();
};

