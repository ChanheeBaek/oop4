#include "Vocabulary.h"

Vocabulary::Vocabulary()
{

}

int Vocabulary::getSize()
{
	return vocabulary.size();
}

void Vocabulary::add(Word w)
{
	vocabulary.push_back(w);
}

void Vocabulary::del(string w)
{
	vocabulary.erase(vocabulary.begin() + search(w));
}

int Vocabulary::search(string w)
{	
	for (int i = 0; i < getSize(); i++)
	{
		if (vocabulary[i].getWord() == w) //word�� ��ġ
			return i;
	}

	return -1; // ������ -1 
}

void Vocabulary::showAll()
{
	/* �̻ڰ� �ٸ���� */
}

void Vocabulary::showBookmark()
{
	/* �̻ڰ� �ٸ����*/
}