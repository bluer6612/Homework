#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
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
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			system("cls");

			UpgradeLevel = 1 + _Player.GetEquipAtt();
			NeedGold = UpgradeLevel * 100;

			printf_s("+%d�� ��ȭ�� �õ��մϴ�, %d ��尡 �Ҹ� �˴ϴ�.\n", UpgradeLevel, UpgradeLevel * 100);
			std::cout << "1. ��ȭ�Ѵ�\n";
			std::cout << "2. ����Ѵ�\n";
			Select = _getch();
			switch (Select)
			{
			case '1':
				system("cls");

				if (15 < UpgradeLevel)
				{
					std::cout << "+15���� �ʰ��Ͽ� ��ȭ�� �� �����ϴ�.\n";
					_getch();
					return;
				}
				else if (_Player.GetGold() < NeedGold)
				{
					std::cout << "��ȭ�� �ʿ��� ��尡 �����մϴ�.\n";
					_getch();
					return;
				}

				_Player.SetGold(_Player.GetGold() - NeedGold);

				if (rand() % 2 == 0)
				{
					printf_s("+%d�� ��ȭ�� �����߽��ϴ�.\n", UpgradeLevel);
				}
				else
				{
					printf_s("+%d�� ��ȭ�� �����߽��ϴ�.\n", UpgradeLevel);

					if (5 >= UpgradeLevel)
					{
						UpgradeLevel -= 1;
					}
					else if (10 >= UpgradeLevel)
					{
						UpgradeLevel -= 2;
						printf_s("+%d������ ��ȭ �ܰ谡 �϶� �߽��ϴ�.\n", UpgradeLevel);
					}
					else if (15 >= UpgradeLevel)
					{
						UpgradeLevel = 0;
						printf_s("+%d������ ���Ⱑ �ı� �Ǿ����ϴ�.\n", UpgradeLevel);
					}
				}
				_getch();
				_Player.SetEquipAtt(UpgradeLevel);
			}
			break;
		case '2':
			return;
		default:
			break;
		}
	}
}