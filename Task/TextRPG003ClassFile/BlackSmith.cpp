#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(100000);

	int NeedGold = 0;
	int UpgradeLevel = 0;

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			system("cls");

			UpgradeLevel = 1 + _Player.GetEquipAtt();
			NeedGold = UpgradeLevel * 100;

			printf_s("+%d강 강화를 시도합니다, %d 골드가 소모 됩니다.\n", UpgradeLevel, UpgradeLevel * 100);
			std::cout << "1. 강화한다\n";
			std::cout << "2. 취소한다\n";
			Select = _getch();
			switch (Select)
			{
			case '1':
				system("cls");

				if (15 < UpgradeLevel)
				{
					std::cout << "+15강을 초과하여 강화할 수 없습니다.\n";
					_getch();
					return;
				}
				else if (_Player.GetGold() < NeedGold)
				{
					std::cout << "강화에 필요한 골드가 부족합니다.\n";
					_getch();
					return;
				}

				_Player.SetGold(_Player.GetGold() - NeedGold);

				if (rand() % 2 == 0)
				{
					printf_s("+%d강 강화에 성공했습니다.\n", UpgradeLevel);
				}
				else
				{
					printf_s("+%d강 강화에 실패했습니다.\n", UpgradeLevel);

					if (5 >= UpgradeLevel)
					{
						UpgradeLevel -= 1;
					}
					else if (10 >= UpgradeLevel)
					{
						UpgradeLevel -= 2;
						printf_s("+%d강으로 강화 단계가 하락 했습니다.\n", UpgradeLevel);
					}
					else if (15 >= UpgradeLevel)
					{
						UpgradeLevel = 0;
						printf_s("+d강으로 무기가 파괴 되었습니다.\n", UpgradeLevel);
					}
				}

				_getch();
				_Player.SetEquipAtt(UpgradeLevel);

			}
			// 확률은 전부다 2분의 1
			// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
			// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.
			// 1~5까지는 실패가 실패확률은 있지만.
			// 다운되지는 않는다.
			// 6~10까지는 실패하면 1씩 다운된다.
			// 10~15는 0으로 실패하면 0으로 떨어진다.
			// 15강 이상이면 강화를 못하게 해야해한다.
			break;
		case '2':
			return;
		default:
			break;
		}
	}
}