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
		if (vocabulary[i].getWord() == w) //word가 일치
			return i;
	}

	return -1; // 없을시 -1 
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
	if (count) // 단어 수가 0이 아니면
	{
		printf("\n\n\t  단어 수: %d\n", count);	
	}
	else
		printf("\n\n\t\t 단어장에 존재하는 단어가 없습니다.\n\t\t 단어를 추가해주세요.\n\n");		
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
	if (count) // 북마크 수가 0이 아니면
	{
		printf("\n\n\t  단어 수: %d\n", count);
	}
	else
		printf("\n\n\t\t 북마크한 단어가 없습니다.\n\n");	
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