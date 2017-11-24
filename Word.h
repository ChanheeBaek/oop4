#ifndef __WORD_H_
#define __WORD_H_
#include <string>
using namespace std;
class Word
{
private:

	string word;			//단어
	string meaning;		    //단어 뜻
	bool bookmark;			//단어 즐겨찾기 설정	

public:
										   
	Word(string*);			//생성자로 문자열 배열을 받는다. 문자열 배열에 단어, 뜻, 즐겨찾기 설정(O,X) 가 들어있다.  (book,책,O) (ban,금지,x)
	string getWord();		//단어 getter
	string getMeaning();	//뜻 getter
	bool getBookmark();		//즐겨찾기 상태 getter
	void changeBookmark();	//즐겨찾기 상태 바꾸기	

};
#endif