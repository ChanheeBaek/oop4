#ifndef __STUDY_H_
#define __STUDY_H_
#include "Vocabulary.h"
using namespace std;
class Study
{
private:

	Vocabulary wordlist;

public:

	Study(Vocabulary&);		//�����ڷ� Vocabulary �޴´�.
	void showBookmark();	//bookmark �ܾ� �����ֱ�	
	void showMeaning();		//�ǹ̸� �����ְ� �ܾ���߱�
	void showWord();		//�ܾ �����ְ� �ǹ̸��߱�
	void showTogether();	//�ǹ�&�ܾ� �����ֱ�
};
#endif