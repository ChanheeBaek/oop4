#ifndef __QUIZRESULT_H_
#define __QUIZRESULT_H_
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

class Quizresult {
private:
	string ID;
	vector<string> score;
public:
	Quizresult(string ID);
	string getID();
	void add(string);			//�������� ����߰�
	void scoresort();			// ������� ����
	static bool comp_Quizresult(const Quizresult& a, const Quizresult& b);
	friend class Member;
	
};
#endif