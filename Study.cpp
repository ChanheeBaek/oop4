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
	while (i < wordlist.getSize() )
	{
		system("cls");
		gotoxy(8, 3);
		if (wordlist.getWord(i).getBookmark()) //bookmark �� �� ǥ��
			cout << "*";
		else
			cout << ">";
		gotoxy(10, 5);
		cout << wordlist.getWord(i).getMeaning();
		gotoxy(10, 10);
		cout << endl;
		cout << "1. �� Ȯ���ϱ�\n";
		cout << "2. ���� �ܾ�\n";
		cout << "3. �ϸ�ũ ����\n";
		cout << "4. ����\n";

		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			system("cls");
			gotoxy(8, 3);
			if (wordlist.getWord(i).getBookmark())
				cout << "*";
			else
				cout << ">";
			gotoxy(10, 5);
			cout << wordlist.getWord(i).getMeaning();
			gotoxy(10, 3);
			cout << wordlist.getWord(i).getWord();
			gotoxy(10, 10);
			cout << "�����ܾ�� �Ѿ���� �ƹ� Ű�� �Է��ϼ���!";
			system("pause>null");
			i++;
			break;
		case '2':
			i++;
			break;
		case '3':
			wordlist.changeBookmark(i);
			system("cls");
			gotoxy(10, 10);
			if (wordlist.getWord(i).getBookmark())
			{				
				cout << "�ش� �ܾ ���ã�� �Ͽ����ϴ�.";
				system("pause>null");
			}
			else
			{
				cout << "�ش� �ܾ ���ã�� ���� �Ͽ����ϴ�.";
				system("pause>null");
			}
			break;
		case '4':
			return;
		default:
			cout << "�ùٸ� �޴��� �������ּ���";
			system("pause>null");			
			break;
		}
		if (i == wordlist.getSize())
		{
			system("cls");
			gotoxy(10, 10);
			cout << "��� �ܾ �н��ϼ̽��ϴ�. �ƹ� Ű�� ������ �޴��� ���ư��ϴ�.";
			system("pause>null");
		}
	}


}
void Study::showWord()
{

}
void Study::showTogether()
{

}

