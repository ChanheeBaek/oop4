#ifndef __QUIZ_H_
#define __QUIZ_H_
#include "Vocabulary.h"
using namespace std;
class Quiz
{
private:

	Vocabulary wordlist;

public:

	Quiz(Vocabulary&);		//�����ڷ� Vocabulary �޴´�.
	void showBookmark();	//bookmark �ܾ� �����ֱ�	
	void showMeaning();		//�ǹ̸� �����ְ� �ܾ���߱�
	void showWord();		//�ܾ �����ְ� �ǹ̸��߱�
	void showTogether();	//�ǹ�&�ܾ� �����ֱ�
};
#endif