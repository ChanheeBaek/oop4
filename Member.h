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
	bool adminlogin();//adminlogin�� ������ ����X
public:
	Vocabulary wordlist;//ȸ���� �ܾ���
	void signup();
	bool login();
};





#endif