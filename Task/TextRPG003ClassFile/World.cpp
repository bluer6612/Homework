#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include "Player.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0, };

	while (true)
	{
		if (0 == InputName[0])
		{
			system("cls");
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;

			system("cls");
			printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		}

		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();
		bool IsEnd = false;
		switch (Select)
		{
		case 'a':
		case 'A':
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			InputName[0] = 0;
			IsEnd = false;
			break;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			Select = _getch();
			IsEnd = false;
			break;
		}

		if (IsEnd)
		{
			_Player.SetName(InputName);
			break;
		}

	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 

	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);

		//_Player.SetName("Test Player");
	}



}