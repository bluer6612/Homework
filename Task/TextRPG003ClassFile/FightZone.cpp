#include "FightZone.h"
#include <conio.h>
#include "Player.h"


int UFightZone::InPlayer(class UPlayer& _Player, int _Number)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. �ʱ޸����� �̵�\n";
		std::cout << "3. �߱޸����� �̵�\n";
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
			return 0;
		}
		case '3':
			printf_s("3�������ϴ�.");
			_getch();
			return 1;
		default:
			break;
		}
	}
}