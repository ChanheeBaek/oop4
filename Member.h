#ifndef Member_H
#define Member_H

#include <iostream>
#include <string> 
#include <fstream>
#include "Vocabulary.h"
#include "Quizresult.h"
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
	void writequizresult(string);//퀴즈보고나면 그 결과를 quizresult.txt 파일에 자동으로저장하게만듬 
};





#endif