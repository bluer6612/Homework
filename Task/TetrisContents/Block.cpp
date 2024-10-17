#include "Block.h"
#include <EngineCore/Renderer.h>
#include <conio.h>
#include "RenderTarget.h"
#include <EngineBase/EngineDebug.h>


void Block::BeginPlay()
{
	Super::BeginPlay();

	// 이미지도 => 배열메모리 덩어리.
	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	if (nullptr == RenderValue)
	{
		MSGASSERT("랜더타겟이 세팅되지 않아서 로직을 진행할수가 없습니다.");
		return;
	}

	Super::Tick();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
		{
			AddActorLocation(FIntPoint::DOWN);

			FIntPoint DownPos = GetActorLocation() + FIntPoint::DOWN;
			ConsoleImage* TargetImage = RenderValue->GetImage();
			char Ch = TargetImage->GetPixel(DownPos.X, DownPos.Y);
			if (Ch == '@')
			{
				TargetImage->SetPixel(GetActorLocation(), '@');
				SetActorLocation({ 0, 0 });
			}
			break;
		}
		default:
			break;
		}

	}


}