#ifndef __VOCABULARY_H_
#define __VOCABULARY_H_
#include "Word.h"
#include <vector>

using namespace std;
class Vocabulary
{
private:

	vector<Word> vocabulary;		//�ܾ���	

public:
	int getSize();			//�ܾ��� �ܾ��
	void add(Word);			//�ܾ��忡 �ܾ��߰�
	void del(string s);		//�ܾ��忡 �ܾ����
	int search(string s);	//�ܾ �Է¹޾� �ش� index �˻� �������� ������ -1 	
	void showAll();			//�ܾ��忡 �ִ� ��� �ܾ� ���
	void showBookmark();	//�ܾ��忡 �ִ� ���ã�� �ܾ� ���
	Word getWord(int);		//�ܾ����
	void changeBookmark(int);//�ش� index �ܾ� �ϸ�ũ ����
};
#endif