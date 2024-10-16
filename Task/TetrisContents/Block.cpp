#include "Block.h"
#include <EngineCore/Renderer.h>
#include <conio.h>
#include <EngineCore/Enums.h>
#include <EngineCore/ConsoleImage.h>
#include <EngineCore/ConsoleWindow.h>

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();
	FIntPoint Pos = FIntPoint::NONE;
	FIntPoint PosDummy = FIntPoint::NONE;

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Pos = FIntPoint::LEFT;
			break;
		case 'D':
		case 'd':
			Pos = FIntPoint::RIGHT;
			break;
		case 'W':
		case 'w':
			Pos = FIntPoint::UP;
			break;
		case 'S':
		case 's':
			Pos = FIntPoint::DOWN;
			break;
		default:
			break;
		}
		
		PosDummy = GetActorLocation() + Pos;

			if (PosDummy.Y == 5)
			{
				GetBackBufferRef()->SetPixel(PosDummy, 'm');
				SetActorLocation({1, 0});
			}
			else
			{
				AddActorLocation(Pos);
			}

	}


}