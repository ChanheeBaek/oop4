#ifndef __WORD_H_
#define __WORD_H_
#include <string>
using namespace std;
class Word
{
private:

	string word;			//�ܾ�
	string meaning;		    //�ܾ� ��
	bool bookmark;			//�ܾ� ���ã�� ����	

public:
										   
	Word(string*);			//�����ڷ� ���ڿ� �迭�� �޴´�. ���ڿ� �迭�� �ܾ�, ��, ���ã�� ����(O,X) �� ����ִ�.  (book,å,O) (ban,����,x)
	string getWord();		//�ܾ� getter
	string getMeaning();	//�� getter
	bool getBookmark();		//���ã�� ���� getter
	void changeBookmark();	//���ã�� ���� �ٲٱ�	

};
#endif