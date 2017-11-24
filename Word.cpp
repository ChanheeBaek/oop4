#include "Word.h"


Word::Word(string w[])
{
	word = w[0];
	meaning = w[1];
	if (w[2] == "O")
		bookmark = true;
	else
		bookmark = false;
}

string Word::getWord()
{
	return word;
}

string Word::getMeaning()
{
	return meaning;
}

bool Word::getBookmark()
{
	return bookmark;
}

void Word::changeBookmark()
{
	bookmark = !bookmark;
}