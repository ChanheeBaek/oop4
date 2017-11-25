#ifndef __STUDY_H_
#define __STUDY_H_
#include "Vocabulary.h"
using namespace std;
class Study
{
private:

	Vocabulary wordlist;

public:

	Study(Vocabulary&);		//생성자로 Vocabulary 받는다.
	void showBookmark();	//bookmark 단어 보여주기	
	void showMeaning();		//의미만 보여주고 단어맞추기
	void showWord();		//단어만 보여주고 의미맞추기
	void showTogether();	//의미&단어 보여주기
};
#endif