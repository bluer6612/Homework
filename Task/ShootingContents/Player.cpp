#include "Player.h"

#include <conio.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/Renderer.h>

#include "Bullet.h"

Player* Player::MainPlayer = nullptr;

void Player::BeginPlay()
{
	// 딱 1개 만들어지는 플레이어가 static 공유되게 됩니다.
	MainPlayer = this;

	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	// 1. 적당히 아래 위치에 놓아달라.
	SetActorLocation({ 10, 8 });
}

void Player::Tick()
{
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
			AddActorLocation(FIntPoint::DOWN);
			break;
		case 'Z':
		case 'z':
		{
			Bullet* NewBullet = ConsoleEngine::GetEngine().SpawnActor<Bullet>();
			NewBullet->SetActorLocation(this->GetActorLocation());
			BulletVector.push_back(NewBullet);
			break;
		}
		default:
			break;
		}

	}
}

