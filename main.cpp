#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include "menu.h"
#include "member.h"
#include "Vocabulary.h"


using namespace std;

void main() {

	//ifstream myfile(argv[1]);
	/*if (myfile.is_open()) {
	while (!myfile.eof())
	}*/
	while (1) {
		MainMenu select;
		select = ShowMenu();
		switch (select)
		{
		case M_login:
			Member member;
			if (member.login()) {
				LoginMenu loginmenu;
				loginmenu = ShowLoginMenu();
				/*	while (1) {
				switch (loginmenu)
				{
				case L_wordbook:
				WordbookMenu wordbookmenu;
				wordbookmenu = ShowWordbookMenu();
				break;
				case L_memorize:
				break;
				case L_quiz:
				break;
				case L_exit:
				break;
				default:
				break;
				}
				}*/
			}
			break;
		case M_signup:
			member.signup();
			break;
		case M_exit:
			//myfile.close();
			exit(0);
		default:
			cout << "\n올바른 메뉴를 선택해주세요\n";
			break;
		}
	}
	return;

}