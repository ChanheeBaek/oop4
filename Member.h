#ifndef Member_H
#define Member_H

#include <iostream>
#include <string> 
#include <iostream>
#include <fstream>
#include "Vocabulary.h"
using namespace std;

class Member {
private:
	string readID;//login������ ID�����̰ų����߰�
	string password;//login�� �н����������̰ų����߰�
	bool adminlogin();//adminlogin�� ������ ����X
public:
	Vocabulary wordlist;//ȸ���� �ܾ���
	void signup();
	bool login();
	string getID();
	string getPassword();
	void writefile();
};





#endif