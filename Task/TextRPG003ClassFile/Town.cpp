#include "Town.h"
#include <conio.h>
#include "Player.h"

// �����ͳ� ���۷����� ������ 8����Ʈ �̱� ������
int UTown::InPlayer(class UPlayer& _Player, int _Number)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������̵�\n";
		if (0 == _Number)
		{
			std::cout << "3. �߱޸����� �̵�\n";
		}
		else if (1 == _Number)
		{
			std::cout << "3. �ʱ޸����� �̵�\n";
		}
		int Select = _getch();

		switch (Select)
		{
		case '0':
			printf_s("0�������ϴ�.");
			_getch();
			break;
		case '1':
			printf_s("1�������ϴ�.");
			_getch();
			break;
		case '2':
		{
			printf_s("2�������ϴ�.");
			_getch();
			return 2;
		}
		case '3':
			printf_s("3�������ϴ�.");
			_getch();
			if (0 == _Number)
			{
				return 1;
			}
			else if (1 == _Number)
			{
				return 0;
			}
			break;
		default:
			break;
		}

	}
}
