#include <iostream>
#include "Menu.h"
#include "Member.h"
#include "Study.h"
#include "Word.h"
#include "Quiz.h"

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
		ofstream writefile;
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
			QuizMenu quizmenu;
			quizmenu = ShowQuizMenu(member);
			break;
			return L_quiz;
		case '4':
			writefile.open(member->getID());
			writefile << member->getPassword() << endl;
			
			while (writei < member->wordlist.getSize())
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
	
	string select;
	string s[3];
	while (getchar() != '\n'); //입력버퍼 초기화
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
		
		getline(cin, select);
				
		if (select == "1")		//단어 추가
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;

			cout << "추가할 단어를 입력해주세요> ";
			getline(cin, s[0]);
			
			if (member->wordlist.search(s[0]) != -1)
			{
				cout << "이미 존재하는 단어입니다. 수정하시겠습니까?> 1.YES 2.NO";
				string st; // 임시 string 
				
				while (1)
				{
					
					getline(cin, select);
					if (select == "1")
					{
						cout << "수정할 의미를 입력해주세요> ";
						getline(cin, st);
						member->wordlist.changeMeaning(member->wordlist.search(s[0]), st);						
						cout << "단어가 정상적으로 수정되었습니다.";
						system("pause>null");

						break;
					}
					else if (select == "2")
					{
						break;
					}
					else
						cout << "정확환 메뉴를 입력해주세요 1.YES 2.NO ";
				}
			}
			else
			{
				cout << "뜻을 입력해주세요> ";
				getline(cin, s[1]);
				s[2] = "X"; //초기값 북마크 X
				Word a(s);
				member->wordlist.add(s);
				member->writefile();
				cout << "단어가 정상적으로 입력되었습니다.";
				system("pause>null");
			}
		}
		else if (select == "2")   //단어 찾기
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;
			if (member->wordlist.getSize()) // 단어가 있으면
			{
				cout << "찾고싶은 단어를 입력해주세요> ";
				getline(cin, s[0]);
				int index = member->wordlist.search(s[0]);
				if (index == -1)
				{
					cout << "해당 단어는 존재하지 않습니다.";
					system("pause>null");
				}
				else
				{
					cout << endl << endl << "     " << member->wordlist.getWord(index).getWord() << endl << endl;
					cout << "     " << member->wordlist.getWord(index).getMeaning() << endl;
					system("pause>null");
				}
			}
			else
			{
				cout << "단어장이 비어있습니다.";
				system("pause>null");
			}

		}
		else if (select == "3")		//단어 삭제
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;
			if (member->wordlist.getSize()) // 단어가 있으면
			{
				cout << "삭제를 원하는 단어를 입력해주세요> ";
				getline(cin, s[0]);
				int index = member->wordlist.search(s[0]);
				if (index == -1)
				{
					cout << "해당 단어는 존재하지 않습니다.";
					system("pause>null");
				}
				else
				{
					
					cout << "정말 삭제하시겠습니까? 1.YES 2.NO ";
					while (1)
					{
						
						cin >> select;
						if (select == "1")
						{
							member->wordlist.del(index);
							member->writefile();
							cout << "단어가 정상적으로 삭제되었습니다.";
							system("pause>null");
							while (getchar() != '\n');
							break;
						}
						else if (select == "2")
						{
							break;
						}
						else
							cout << "정확환 메뉴를 입력해주세요 1.YES 2.NO ";
					}
				}

			}
			else
			{
				cout << "단어장이 비어있습니다.";
				system("pause>null");
			}
		}
		else if (select == "4")
			return W_exit;			
	
		else
		{
			cout << "\n올바른 메뉴를 선택해주세요\n";
			system("pause>null");
		}
		continue;
		return W_exit;

		/*
				case '4':
				return W_exit;//종료
				default:
				cout << "\n올바른 메뉴를 선택해주세요\n";
				break;
				}
				}
				return W_exit; */
	}
}

StudyMenu ShowStudyMenu(Member* member)
{
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		//화면 초기화
		system("cls");

		Study study(&(member->wordlist));//회원에 단어장 study에추가

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
			study.showBookmark();
			break;
			return  S_bookmark;//북마크보기
		case '2':
			study.showMeaning();
			break;
			return  S_Meaning;//의미만보기
		case '3':
			study.showWord();
			break;
			return S_Word;//단어만보기
		case '4':
			study.showTogether();
			break;
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

QuizMenu ShowQuizMenu(Member* member) {
	//메뉴를 제대로 입력받을 때까지 반복
	while (1)
	{
		Quiz q(&(member->wordlist));
		//화면 초기화
		system("cls");
		//메뉴
		cout << "1. 단어 퀴즈 - 북마크\n";
		cout << "2. 단어 퀴즈 - 전체\n";;
		cout << "3. 종료\n";

		//원하는 메뉴 입력받기
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			q.quizBookmark();  //bookmark quiz 한 결과 string 받아가지고 파일출력해줘 "n"은 무시해
			break;
			return Q_bookmarkquiz;
		case '2':
			q.quizAll();  //quiz 한 결과 string 받아가지고 파일출력해줘 "n" 은 무시해
			break;
			return Q_meaningquiz;
		case '3':
			return Q_exit;
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return Q_exit;
}