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
	string readID;//login성공시 ID저장이거내용추가
	string password;//login시 패스워드저장이거내용추가
	bool adminlogin();//adminlogin은 공개된 것은X
public:
	Vocabulary wordlist;//회원에 단어장
	void signup();
	bool login();
	string getID();
	string getPassword();
	void writefile();
};





#endif