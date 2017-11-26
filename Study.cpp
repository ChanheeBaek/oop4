#include "Study.h"
#include <iostream>
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
using namespace std;

Study::Study(Vocabulary* v)
{
	wordlist = v;
}

void Study::showBookmark()
{
	system("cls");
	wordlist->showBookmark();

	cout << endl << endl;
	cout << "1. �ϸ�ũ �����ϱ�\n";
	cout << "2. ����\n";

	string input;
	char select;
	cin >> select;

	switch (select)
	{
	case '1':
		system("cls");
		wordlist->showBookmark();
		cout << endl << endl;
		cout << "� �ܾ��� �ϸ�ũ�� �����Ͻðڽ��ϱ� > ";
		/*�Է� ���� ����*/
		cin >> input;
		if (wordlist->search(input) == -1)
		{
			cout << "�ش� �ܾ ���� ���� �ʽ��ϴ�.";
			system("pause>null");
			showBookmark();
			break;
		}		
		wordlist->changeBookmark(wordlist->search(input));	
		showBookmark();
		break;
	case '2':
		break;
	default:
		cout << "�ùٸ� �޴��� �������ּ���";
		system("pause>null");
		showBookmark();
		break;
	}
	
}

void Study::showMeaning()
{
	int i = 0, size;
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		gotoxy(8, 3);
		cout << "�ܾ �������� �ʽ��ϴ�. �����޴��� ���ư��ϴ�.";
		system("pause>null");
	}
	while (i < size )
	{
		system("cls");
		gotoxy(8, 3);
		if (wordlist->getWord(i).getBookmark()) //bookmark �� �� ǥ��
			cout << "*";
		else
			cout << ">";
		gotoxy(10, 5);
		cout << wordlist->getWord(i).getMeaning();
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
			if (wordlist->getWord(i).getBookmark())
				cout << "*";
			else
				cout << ">";
			gotoxy(10, 5);
			cout << wordlist->getWord(i).getMeaning();
			gotoxy(10, 3);
			cout << wordlist->getWord(i).getWord();
			gotoxy(10, 10);
			cout << "�����ܾ�� �Ѿ���� �ƹ� Ű�� �Է��ϼ���!";
			system("pause>null");
			i++;
			break;
		case '2':
			i++;
			break;
		case '3':
			wordlist->changeBookmark(i);
			system("cls");
			gotoxy(10, 10);
			if (wordlist->getWord(i).getBookmark())
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
		if (i == wordlist->getSize())
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

