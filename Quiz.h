#ifndef __QUIZ_H_
#define __QUIZ_H_
#include <string>
#include "gotoxy.h"
#include "Vocabulary.h"

using namespace std;
class Quiz
{
private:

	Vocabulary* wordlist;
	
public:

	Quiz(Vocabulary* );
	string quizBookmark();	//bookmark�ܾ� ����
	string quizAll();			//��ü�ܾ� ���� 
			
};
#endif
