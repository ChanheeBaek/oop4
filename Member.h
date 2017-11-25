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
	bool adminlogin();//adminlogin은 공개된 것은X
public:
	Vocabulary wordlist;//회원에 단어장
	void signup();
	bool login();
};





#endif