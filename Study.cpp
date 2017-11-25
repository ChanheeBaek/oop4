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
	while (i < wordlist.getSize() )
	{
		system("cls");
		gotoxy(8, 3);
		if (wordlist.getWord(i).getBookmark()) //bookmark 된 것 표시
			cout << "*";
		else
			cout << ">";
		gotoxy(10, 5);
		cout << wordlist.getWord(i).getMeaning();
		gotoxy(10, 10);
		cout << endl;
		cout << "1. 답 확인하기\n";
		cout << "2. 다음 단어\n";
		cout << "3. 북마크 변경\n";
		cout << "4. 종료\n";

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
			cout << "다음단어로 넘어가려면 아무 키나 입력하세요!";
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
				cout << "해당 단어를 즐겨찾기 하였습니다.";
				system("pause>null");
			}
			else
			{
				cout << "해당 단어를 즐겨찾기 해제 하였습니다.";
				system("pause>null");
			}
			break;
		case '4':
			return;
		default:
			cout << "올바른 메뉴를 선택해주세요";
			system("pause>null");			
			break;
		}
		if (i == wordlist.getSize())
		{
			system("cls");
			gotoxy(10, 10);
			cout << "모든 단어를 학습하셨습니다. 아무 키나 누르면 메뉴로 돌아갑니다.";
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

