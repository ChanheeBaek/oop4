#ifndef __VOCABULARY_H_
#define __VOCABULARY_H_
#include "Word.h"
#include <vector>

using namespace std;
class Vocabulary
{
private:

	vector<Word> vocabulary;		//단어장	

public:
	
	Vocabulary();			//생성자 
	int getSize();			//단어장 단어수
	void add(Word);			//단어장에 단어추가
	void del(string s);		//단어장에 단어삭제
	int search(string s);	//단어를 입력받아 해당 index 검색 존재하지 않으면 -1 	
	void showAll();			//단어장에 있는 모든 단어 출력
	void showBookmark();	//단어장에 있는 즐겨찾기 단어 출력

};
#endif