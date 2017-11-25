#include <iostream>
#include "menu.h"
#include "member.h"

using namespace std;

//맨처음 기본 시작메뉴
MainMenu ShowMenu()
{
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		//화면 초기화
		system("cls");
		//메뉴
		cout << "1. 로그인\n";
		cout << "2. 회원가입\n";
		cout << "3. 종료\n";
		//원하는 메뉴 입력받기
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return M_login;//여기서 이거 콜하는 경우 ID,PW입력하도록
		case '2':
			return M_signup;//회원가입
		case '3':
			return M_exit;
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return M_exit;
}

LoginMenu ShowLoginMenu(Member* member) {
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		//화면 초기화
		system("cls");
		//메뉴
		cout << "1. 단어장\n";
		cout << "2. 암기\n";
		cout << "3. 퀴즈\n";
		cout << "4. 종료\n";
		//원하는 메뉴 입력받기
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			WordbookMenu wordbookmenu;
			wordbookmenu = ShowWordbookMenu(member);
			return L_wordbook;
		case '2':
			return L_memorize;
		case '3':
			return L_quiz;
		case '4':
			return L_exit;
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return L_exit;
}

WordbookMenu ShowWordbookMenu(Member* member) {
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		//화면 초기화
		system("cls");
		//메뉴
		cout << "1. 단어보기\n";
		cout << "2. 단어추가\n";
		cout << "3. 단어찾기\n";
		cout << "4. 종료\n";
		//원하는 메뉴 입력받기
		char select;
		cin >> select;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

		switch (select)
		{
		case '1':
			member->wordlist.showAll();
			system("pause");
			return W_all;//단어보기
		case '2':
			return W_add;//단어추가
		case '3':
			return W_search;//단어찾기
		case '4':
			return W_exit;//종료
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return W_exit;
}

AdminMenu ShowAdminMenu(Member* member)
{
   //메뉴를 제대로 입력받을 때까지 반복
   while (1)
   {
      //화면 초기화
      system("cls");
      member->wordlist.showAll();
      cout << endl;//한줄뛰고
      //메뉴
      cout << "1. 단어추가\n";
      cout << "2. 단어찾기\n";
      cout << "3. 단어삭제\n";
      cout << "4. 종료\n";
      //원하는 메뉴 입력받기
      char select;
      cin >> select;

      switch (select)
      {
      case '1':
         return A_add;//단어추가
      case '2':
         return A_search;//단어찾기
      case '3':
         return A_delete;//단어삭제
      case '4':
         return A_exit;
      default:
         cout << "\n올바른 메뉴를 선택해주세요\n";
         break;
      }
   }
   return A_exit;
}