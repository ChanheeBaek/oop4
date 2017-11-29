#include "Quiz.h"
#include <iostream>

Gotoxy b;

Quiz::Quiz(Vocabulary* v)
{
	wordlist = v;	
}


string Quiz::quizBookmark()		// return "n" �ϸ� ������� X
{
	int i = 0, size;
	int correct = 0;//���� ����
	int count = 0; //Bookmark ����
	int length; //�ܾ� ����
	string hint; // hint
	string result = "";
	
	size = wordlist->getSize();
	if (size == 0)
	{
		system("cls");
		b.gotoxy(8, 3);
		cout << "�ܾ �������� �ʽ��ϴ�. �����޴��� ���ư��ϴ�.";
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
			cout << "������ �Է��ϼ���!.\n\n��ƮȮ��> 0\n����Ȯ��> 1  \n��������> 2";
			b.gotoxy(10, 3); // �ܾ� �Է��ϴ� ��		

			
			string select;
			cin >> select;
			while (getchar() != '\n'); //�Է¹��� �ʱ�ȭ
			if (select == wordlist->getWord(i).getWord())
			{
				correct++;
				system("cls");
				b.gotoxy(10, 3);
				cout << "�����Դϴ�. �������: " << correct << " / " << count << " �Դϴ�.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "0")
			{
				b.gotoxy(10, 3); // �ܾ� �Է��ϴ� ��
				cout << "                            "; // 0 �Է��Ѱ� ���������
				/* ���ڿ� ���� 3���� ����� �ݿø��� �� ���̸�ŭ ��Ʈ�� ���� */
				length = wordlist->getWord(i).getWord().length();				
				if (length % 3 == 2) //�ݿø� �ϴ� ���
				{
					length = length / 3;
					length++;
				}
				else
					length = length / 3;
				hint = wordlist->getWord(i).getWord().substr(0, length);
				b.gotoxy(25, 7);
				cout << "��Ʈ: " << hint;
			}
			else if (select == "1")
			{
				system("cls");
				b.gotoxy(3, 3);
				cout << "���� >";
				b.gotoxy(10, 3);
				cout << wordlist->getWord(i).getWord();
				b.gotoxy(10, 5);
				cout << wordlist->getWord(i).getMeaning();
				b.gotoxy(10, 8);
				cout << "�������: " << correct << " / " << count << " �Դϴ�.";
				b.gotoxy(10, 10);
				cout << "�ƹ� Ű�� �Է��ϸ� �������� �Ѿ�ϴ�.";
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
				cout << "Ʋ�Ƚ��ϴ�. ������ �Է����ּ���";
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
		cout << "��� �������ϴ�. �� ������: " << count << " ���� ����: " << correct <<" �Դϴ�.";
		system("pause>null");
		return result;
	}
	else
	{
		system("cls");
		b.gotoxy(8, 3);
		cout << "�ϸ�ũ�� �������� �ʽ��ϴ�. �����޴��� ���ư��ϴ�.";
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
		cout << "�ܾ �������� �ʽ��ϴ�. �����޴��� ���ư��ϴ�.";
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
			cout << "������ �Է��ϼ���!.\n\n��ƮȮ��> 0\n����Ȯ��> 1  \n��������> 2";
			b.gotoxy(10, 3); // �ܾ� �Է��ϴ� ��	
			
			string select;
			cin >> select;
			while (getchar() != '\n'); //�Է¹��� �ʱ�ȭ
			if (select == wordlist->getWord(i).getWord())
			{
				correct++;
				system("cls");
				b.gotoxy(10, 3);
				cout << "�����Դϴ�. �������: " << correct << " / " << i+1 << " �Դϴ�.";
				system("pause>null");
				i++;
				break;
			}
			else if (select == "0")
			{
				b.gotoxy(10, 3); // �ܾ� �Է��ϴ� ��
				cout << "                                    "; //0 �Է��Ѱ� ���������
				/* ���ڿ� ���� 3���� ����� �ݿø��� �� ���̸�ŭ ��Ʈ�� ���� */
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
				cout << "��Ʈ: " << hint;					
			} 
			else if (select == "1")
			{
				system("cls");
				b.gotoxy(3, 3);
				cout << "���� >";
				b.gotoxy(10, 3);
				cout << wordlist->getWord(i).getWord();
				b.gotoxy(10, 5);
				cout << wordlist->getWord(i).getMeaning();
				b.gotoxy(10, 8);
				cout << "�������: " << correct << " / " << i+1 << " �Դϴ�.";
				b.gotoxy(10, 10);
				cout << "�ƹ� Ű�� �Է��ϸ� �������� �Ѿ�ϴ�.";
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
				cout << "Ʋ�Ƚ��ϴ�. ������ �Է����ּ���";
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
		cout << "��� �������ϴ�. �� ������: " << i << " ���� ����: " << correct <<" �Դϴ�.";
		system("pause>null");
		return result;
	}
	
	return "n"; //error
}

