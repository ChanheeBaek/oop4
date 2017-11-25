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

void Vocabulary::del(string w)
{
	vocabulary.erase(vocabulary.begin() + search(w));
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
	vector<Word>::reverse_iterator it;
	
	for (it = vocabulary.rbegin(); it!=vocabulary.rend(); it++)
		printf("\t%-15s  %s\n", it->getWord().c_str(), it->getMeaning().c_str());

}

void Vocabulary::showBookmark()
{
	vector<Word>::reverse_iterator it;

	for (it = vocabulary.rbegin(); it!=vocabulary.rend(); it++)
	{
		if (it->getBookmark())
			printf("\t%-15s  %s\n", it->getWord().c_str(), it->getMeaning().c_str());
	}
}

Word Vocabulary::getWord(int i)
{
	return vocabulary[i];
}

void Vocabulary::changeBookmark(int i)
{
	vocabulary[i].changeBookmark();
}
