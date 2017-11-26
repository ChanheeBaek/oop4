#include <iostream>
#include "Menu.h"
#include "Member.h"
#include "Study.h"

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
		//로그인시 바로 파일쓸수 있게 준비
		ofstream writefile(member->getID());
		int writei = 0;//writei는 마지막에 종료시 파일에 순서대로 단어작성위해 필요
		//원하는 메뉴 입력받기
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			WordbookMenu wordbookmenu;
			wordbookmenu = ShowWordbookMenu(member);
			break;
			return L_wordbook;
		case '2':
			StudyMenu studymenu;
			studymenu = ShowStudyMenu(member);
			break;
			return L_memorize;
		case '3':
			return L_quiz;
		case '4':
			//첫줄먼저 password 입력 후 줄바꿈
			writefile << member->getPassword() << endl;
			while (writei < member->wordlist.getSize() - 1 )
			{//마지막줄북마크 입력전 입력 while으로 돌림
				writefile << member->wordlist.getWord(writei).getWord() << "/" << member->wordlist.getWord(writei).getMeaning() << "/";
				if (member->wordlist.getWord(writei).getBookmark() == true) {//북마크O시 O입력
					writefile << "O" << endl;
				}
				else {//북마크x시 x입력
					writefile << "X" << endl;
				}
				writei++;
			}
			
			writefile.close();//마무리로 파일 닫음
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
		//모든단어
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
			return W_add;//단어추가
		case '2':
			return W_search;//단어찾기
		case '3':
			return W_delete;//단어삭제
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

StudyMenu ShowStudyMenu(Member* member)
{
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		//화면 초기화
		system("cls");

		Study study(member->wordlist);//회원에 단어장 study에추가

		cout << "1. 북마크보기\n";
		cout << "2. 의미만보기\n";
		cout << "3. 단어만보기\n";
		cout << "4. 함께보기\n";
		cout << "5. 종료\n";
		//원하는 메뉴 입력받기
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return  S_bookmark;//북마크보기
		case '2':
			study.showMeaning();
			break;
			return  S_Meaning;//의미만보기
		case '3':
			return S_Word;//단어만보기
		case '4':
			return S_Together;//함께보기
		case '5':
			return S_exit;//종료
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return S_exit;
}