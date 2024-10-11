#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "ConsoleImage.h"

void Player::BeginPlay()
{
	PlayerImage.Create({1, 1}, '@');
}

void Player::Tick()
{
	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			Dir = Enums::GAMEDIR::LEFT;
			break;
		case 'D':
		case 'd':
			Dir = Enums::GAMEDIR::RIGHT;
			PosMove = FIntPoint::RIGHT;
			break;
		case 'W':
		case 'w':
			Dir = Enums::GAMEDIR::UP;
			PosMove = FIntPoint::UP;
			break;
		case 'S':
		case 's':
			Dir = Enums::GAMEDIR::DOWN;
			PosMove = FIntPoint::DOWN;
			break;
		default:
			break;
		}

		if (Enums::GAMEDIR::NONE != Dir)
		{
			PosMove = ConsoleImage::CheckWall(GlobalValue::worldSizeX, GlobalValue::worldSizeY, Pos, PosMove);
		}
	}

	switch (Dir)
	{
	case Enums::GAMEDIR::LEFT:
	case Enums::GAMEDIR::RIGHT:
	case Enums::GAMEDIR::UP:
	case Enums::GAMEDIR::DOWN:
		Pos += PosMove;
		break;
	default:
		break;
	}

}

void Player::Render(ConsoleImage* _BackBuffer)
{
	// delete _BackBuffer;
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}