#include "Quizresult.h"

Quizresult::Quizresult(string ID) {
	this->ID = ID;
}

string Quizresult::getID()
{
	return ID;
}

void Quizresult::add(string w)
{
	score.push_back(w);
}

void Quizresult::scoresort()
{
	sort(score.begin(), score.end());
}

bool Quizresult::comp_Quizresult(const Quizresult& a, const Quizresult& b)
{
	return (a.ID < b.ID);
}//quizresult를 비교하기 위해서 정렬방식을 지정