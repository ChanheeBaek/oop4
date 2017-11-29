#include "Quiz.h"
#include <iostream>

Gotoxy b;

Quiz::Quiz(Vocabulary* v)
{
	wordlist = v;	
}


string Quiz::quizBookmark()		// return "n" 하면 파일출력 X
{
	int i = 0, size;
	int correct = 0;//정답 숫자
	int count = 0; //Bookmark 숫자
	int length; //단어 길이
	string hint; // hint
	string result = "";
	
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		b.gotoxy(8, 3);
		cout << "단어가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
		return "n";
	}
	while (i < size)
	{
		if (!(wordlist->getWord(i).getBookmark()))
		{
			i++;
			continue;
		}
		count++;
		system("cls");
		
		while (1){			
			b.gotoxy(8, 3);
			cout << ">";
			b.gotoxy(10, 5);
			cout << wordlist->getWord(i).getMeaning();
			b.gotoxy(10, 7);
			cout << endl;
			cout << "정답을 입력하세요!.\n\n힌트확인> 0\n정답확인> 1  \n퀴즈종료> 2";
			b.gotoxy(10, 3); // 단어 입력하는 곳		

			
			string select;
			cin >> select;
			while (getchar() != '\n'); //입력버퍼 초기화
			if (select == wordlist->getWord(i).getWord())
			{
				correct++;
				system("cls");
				b.gotoxy(10, 3);
				cout << "정답입니다. 현재까지: " << correct << " / " << count << " 입니다.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "0")
			{
				b.gotoxy(10, 3); // 단어 입력하는 곳
				cout << "                            "; // 0 입력한거 지우기위해
				/* 문자열 길이 3으로 나누어서 반올림한 그 길이만큼 힌트로 제공 */
				length = wordlist->getWord(i).getWord().length();				
				if (length % 3 == 2) //반올림 하는 경우
				{
					length = length / 3;
					length++;
				}
				else
					length = length / 3;
				hint = wordlist->getWord(i).getWord().substr(0, length);
				b.gotoxy(25, 7);
				cout << "힌트: " << hint;
			}
			else if (select == "1")
			{
				system("cls");
				b.gotoxy(3, 3);
				cout << "정답 >";
				b.gotoxy(10, 3);
				cout << wordlist->getWord(i).getWord();
				b.gotoxy(10, 5);
				cout << wordlist->getWord(i).getMeaning();
				b.gotoxy(10, 8);
				cout << "현재까지: " << correct << " / " << count << " 입니다.";
				b.gotoxy(10, 10);
				cout << "아무 키나 입력하면 다음으로 넘어갑니다.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "2")
			{
				return "n";
			}
			else
			{
				system("cls");
				b.gotoxy(10, 2);
				cout << "틀렸습니다. 정답을 입력해주세요";
			}
		}			
	}
	if (i == wordlist->getSize() && count!=0)
	{
		result.append(to_string(correct));
		result.append("/");
		result.append(to_string(count));
		system("cls");
		b.gotoxy(10, 3);
		cout << "퀴즈가 끝났습니다. 총 문제수: " << count << " 맞힌 문제: " << correct <<" 입니다.";
		system("pause>null");
		return result;
	}
	else
	{
		system("cls");
		b.gotoxy(8, 3);
		cout << "북마크가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
		return "n"; //quiz error
	}
		
}

string Quiz::quizAll()
{
	int i = 0, size, correct = 0;	
	int length;
	string hint;
	string result = "";
	
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		b.gotoxy(8, 3);
		cout << "단어가 존재하지 않습니다. 이전메뉴로 돌아갑니다.";
		system("pause>null");
		return "n";
	}
	while (i < size)
	{
		
		
		system("cls");
		
		while (1){			
			b.gotoxy(8, 3);
			cout << ">";
			b.gotoxy(10, 5);
			cout << wordlist->getWord(i).getMeaning();
			b.gotoxy(10, 7);
			cout << endl;
			cout << "정답을 입력하세요!.\n\n힌트확인> 0\n정답확인> 1  \n퀴즈종료> 2";
			b.gotoxy(10, 3); // 단어 입력하는 곳	
			
			string select;
			cin >> select;
			while (getchar() != '\n'); //입력버퍼 초기화
			if (select == wordlist->getWord(i).getWord())
			{
				correct++;
				system("cls");
				b.gotoxy(10, 3);
				cout << "정답입니다. 현재까지: " << correct << " / " << i+1 << " 입니다.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "0")
			{
				b.gotoxy(10, 3); // 단어 입력하는 곳
				cout << "                                    "; //0 입력한거 지우기위해
				/* 문자열 길이 3으로 나누어서 반올림한 그 길이만큼 힌트로 제공 */
				length = wordlist->getWord(i).getWord().length();
				if (length % 3 == 2)
				{
					length = length / 3;
					length++;
				}
				else
					length = length / 3;
				hint = wordlist->getWord(i).getWord().substr(0, length);
				b.gotoxy(25, 7);
				cout << "힌트: " << hint;					
			} 
			else if (select == "1")
			{
				system("cls");
				b.gotoxy(3, 3);
				cout << "정답 >";
				b.gotoxy(10, 3);
				cout << wordlist->getWord(i).getWord();
				b.gotoxy(10, 5);
				cout << wordlist->getWord(i).getMeaning();
				b.gotoxy(10, 8);
				cout << "현재까지: " << correct << " / " << i+1 << " 입니다.";
				b.gotoxy(10, 10);
				cout << "아무 키나 입력하면 다음으로 넘어갑니다.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "2")
			{
				return "n";
			}
			else
			{
				system("cls");
				b.gotoxy(10, 2);
				cout << "틀렸습니다. 정답을 입력해주세요";
			}
		}			
	}
	if (i == wordlist->getSize())
	{
		result.append(to_string(correct));
		result.append("/");
		result.append(to_string(i));
		system("cls");
		b.gotoxy(10, 3);
		cout << "퀴즈가 끝났습니다. 총 문제수: " << i << " 맞힌 문제: " << correct <<" 입니다.";
		system("pause>null");
		return result;
	}
	
	return "n"; //error
}

