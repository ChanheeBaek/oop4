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
	// 여기하다가 망 여기도 menu.cpp로 해야할텐데
	while (i < wordlist.getSize())
	{
		system("cls");
		gotoxy(10, 5);
		if (wordlist.getWord(i).getBookmark()) //bookmark 된 것 표시
			cout << "* " << wordlist.getWord(i).getMeaning();
		else
			cout << wordlist.getWord(i).getMeaning();
		i++;
		gotoxy(10, 10);

		do{
			cout << "1. 답 확인하기\n";
			cout << "2. 다음 단어\n";
			cout << "3. 북마크 변경\n";
			cout << "4. 종료\n";

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
				cout << "\n올바른 메뉴를 선택해주세요\n";
				break;
			}
		} while (1/*조건설정..*/);

	}
}
void Study::showWord()
{

}
void Study::showTogether()
{

}

