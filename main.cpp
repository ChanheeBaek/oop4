#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include "menu.h"
#include "member.h"

using namespace std;

void main() {
	
	while (1) {
		MainMenu select;
		Member* member = new Member;
		select = ShowMenu();
		switch (select)
		{
		case M_login:
			if (member->login()) {
				LoginMenu loginmenu;
				loginmenu = ShowLoginMenu(member);
			}
			break;
		case M_signup:
			member->signup();
			break;
		case M_exit:
			//myfile.close();
			exit(0);
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return;

}

