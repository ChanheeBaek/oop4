#include "Study.h"
#include <iostream>
#include "gotoxy.h"

using namespace std;

Gotoxy a;

Study::Study(Vocabulary* v)
{
	wordlist = v;
}

void Study::showBookmark()
{
	system("cls");
	wordlist->showBookmark();

	cout << endl << endl;
	cout << "1. 북마크 변경하기\n";
	cout << "2. 종료\n";

	string input;
	char select;
	cin >> select;

	switch (select)
	{
	case '1':
		system("cls");
		wordlist->showBookmark();
		cout << endl << endl;
		cout << "어떤 단어의 북마크를 변경하시겠습니까 > ";
		/*입력 버퍼 주의*/
		cin >> input;
		if (wordlist->search(input) == -1)
		{
			cout << "해당 단어가 존재 하지 않습니다.";
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
		cout << "올바른 메뉴를 선택해주세요";
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
		a.gotoxy(8, 3);
		cout << "단어가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
	}
	while (i < size )
	{
		system("cls");
		a.gotoxy(8, 3);
		if (wordlist->getWord(i).getBookmark()) //bookmark 된 것 표시
			cout << "*";
		else
			cout << ">";
		a.gotoxy(10, 5);
		cout << wordlist->getWord(i).getMeaning();
		a.gotoxy(10, 10);
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
			a.gotoxy(8, 3);
			if (wordlist->getWord(i).getBookmark())
				cout << "*";
			else
				cout << ">";
			a.gotoxy(10, 5);
			cout << wordlist->getWord(i).getMeaning();
			a.gotoxy(10, 3);
			cout << wordlist->getWord(i).getWord();
			a.gotoxy(10, 10);
			cout << "다음단어로 넘어가려면 아무 키나 입력하세요!";
			system("pause>null");
			i++;
			break;
		case '2':
			i++;
			break;
		case '3':
			wordlist->changeBookmark(i);
			system("cls");
			a.gotoxy(10, 10);
			if (wordlist->getWord(i).getBookmark())
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
		if (i == wordlist->getSize())
		{
			system("cls");
			a.gotoxy(10, 10);
			cout << "모든 단어를 학습하셨습니다. 아무 키나 누르면 메뉴로 돌아갑니다.";
			system("pause>null");
		}
	}


}
void Study::showWord()
{
	int i = 0, size;
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		a.gotoxy(8, 3);
		cout << "단어가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
	}
	while (i < size)
	{
		system("cls");
		a.gotoxy(8, 3);
		if (wordlist->getWord(i).getBookmark()) //bookmark 된 것 표시
			cout << "*";
		else
			cout << ">";
		a.gotoxy(10, 3);
		cout << wordlist->getWord(i).getWord();
		a.gotoxy(10, 10);
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
			a.gotoxy(8, 3);
			if (wordlist->getWord(i).getBookmark())
				cout << "*";
			else
				cout << ">";
			a.gotoxy(10, 5);
			cout << wordlist->getWord(i).getMeaning();
			a.gotoxy(10, 3);
			cout << wordlist->getWord(i).getWord();
			a.gotoxy(10, 10);
			cout << "다음단어로 넘어가려면 아무 키나 입력하세요!";
			system("pause>null");
			i++;
			break;
		case '2':
			i++;
			break;
		case '3':
			wordlist->changeBookmark(i);
			system("cls");
			a.gotoxy(10, 10);
			if (wordlist->getWord(i).getBookmark())
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
		if (i == wordlist->getSize())
		{
			system("cls");
			a.gotoxy(10, 10);
			cout << "모든 단어를 학습하셨습니다. 아무 키나 누르면 메뉴로 돌아갑니다.";
			system("pause>null");
		}
	}
}
void Study::showTogether()
{
	int i = 0, size;
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		a.gotoxy(8, 3);
		cout << "단어가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
	}
	while (i < size)
	{
		system("cls");
		a.gotoxy(8, 3);
		if (wordlist->getWord(i).getBookmark()) //bookmark 된 것 표시
			cout << "*";
		else
			cout << ">";
		a.gotoxy(10, 3);
		cout << wordlist->getWord(i).getWord();
		a.gotoxy(10, 5);
		cout << wordlist->getWord(i).getMeaning();
		a.gotoxy(10, 10);
		cout << endl;
		cout << "1. 다음 단어\n";
		cout << "2. 북마크 변경\n";
		cout << "3. 종료\n";
		
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			i++;
			break;
		case '2':
			wordlist->changeBookmark(i);
			system("cls");
			a.gotoxy(10, 10);
			if (wordlist->getWord(i).getBookmark())
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
		case '3':
			return;	
		default:
			cout << "올바른 메뉴를 선택해주세요";
			system("pause>null");
			break;
		}
		if (i == wordlist->getSize())
		{
			system("cls");
			a.gotoxy(10, 10);
			cout << "모든 단어를 학습하셨습니다. 아무 키나 누르면 메뉴로 돌아갑니다.";
			system("pause>null");
		}
	}
}

