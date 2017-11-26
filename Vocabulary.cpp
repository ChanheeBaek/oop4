#include "Vocabulary.h"
#include <iostream>


int Vocabulary::getSize()
{
	return vocabulary.size();
}

void Vocabulary::add(Word w)
{
	vocabulary.push_back(w);
}

void Vocabulary::del(int i)
{
	vocabulary.erase(vocabulary.begin() + i);
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
	int count = 0;
	vector<Word>::reverse_iterator it;
	cout << endl;
	for (it = vocabulary.rbegin(); it != vocabulary.rend(); it++)
	{
		printf("\t%-15s  %s\n", it->getWord().c_str(), it->getMeaning().c_str());
		count++;
	}
	if (count) // �ܾ� ���� 0�� �ƴϸ�
	{
		printf("\n\n\t  �ܾ� ��: %d\n", count);	
	}
	else
		printf("\n\n\t\t �ܾ��忡 �����ϴ� �ܾ �����ϴ�.\n\t\t �ܾ �߰����ּ���.\n\n");		
}

void Vocabulary::showBookmark()
{	
	int count = 0;
	vector<Word>::reverse_iterator it;	
	cout << endl;
	for (it = vocabulary.rbegin(); it != vocabulary.rend(); it++)
	{
		if (it->getBookmark())
		{
			printf("\t%-15s  %s\n", it->getWord().c_str(), it->getMeaning().c_str());
			count++;
		}		
	}
	if (count) // �ϸ�ũ ���� 0�� �ƴϸ�
	{
		printf("\n\n\t  �ܾ� ��: %d\n", count);
	}
	else
		printf("\n\n\t\t �ϸ�ũ�� �ܾ �����ϴ�.\n\n");	
}

Word Vocabulary::getWord(int i)
{
	return vocabulary[i];
}

void Vocabulary::changeBookmark(int i)
{
	vocabulary[i].changeBookmark();
}

void Vocabulary::changeMeaning(int i, string s)
{
	vocabulary[i].changeMeaning(s);
}