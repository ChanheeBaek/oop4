#include <Windows.h>
#include "Study.h"
#ifdef _WIN32
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

#else

#include <unistd.h>
#include <term.h>

void gotoxy(int x, int y)
{
	int err;
	if (!cur_term)
		if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
			return;
	putp(tparm(tigetstr("cup"), y, x, 0, 0, 0, 0, 0, 0, 0));
}

#endif
#include <iostream>
using namespace std;


Study::Study(Vocabulary& v)
{
	wordlist = v;
}

void Study::showBookmark()
{
	wordlist.showBookmark();
}

void Study::showMeaning()
{
	int i = 0;
	// �����ϴٰ� �� ���⵵ menu.cpp�� �ؾ����ٵ�
	while (i < wordlist.getSize())
	{
		system("cls");
		gotoxy(10, 5);
		if (wordlist.getWord(i).getBookmark()) //bookmark �� �� ǥ��
			cout << "* " << wordlist.getWord(i).getMeaning();
		else
			cout << wordlist.getWord(i).getMeaning();
		i++;
		gotoxy(10, 10);

		do{
			cout << "1. �� Ȯ���ϱ�\n";
			cout << "2. ���� �ܾ�\n";
			cout << "3. �ϸ�ũ ����\n";
			cout << "4. ����\n";

			char select;
			cin >> select;

			switch (select)
			{
			case '1':
				gotoxy(10, 3);
				cout << wordlist.getWord(i).getWord();
				break;
			case '2':
				break;
			case '3':
				wordlist.getWord(i).changeBookmark();
				break;
			case '4':

				break;
			default:
				cout << "\n�ùٸ� �޴��� �������ּ���\n";
				break;
			}
		} while (1/*���Ǽ���..*/);

	}
}
void Study::showWord()
{

}
void Study::showTogether()
{

}

