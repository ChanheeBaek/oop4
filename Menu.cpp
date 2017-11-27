#include <iostream>
#include "Menu.h"
#include "Member.h"
#include "Study.h"
#include "Word.h"
#include "Quiz.h"

using namespace std;

//��ó�� �⺻ ���۸޴�
MainMenu ShowMenu()
{
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		//ȭ�� �ʱ�ȭ
		system("cls");
		//�޴�
		cout << "1. �α���\n";
		cout << "2. ȸ������\n";
		cout << "3. ����\n";
		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return M_login;//���⼭ �̰� ���ϴ� ��� ID,PW�Է��ϵ���
		case '2':
			return M_signup;//ȸ������
		case '3':
			return M_exit;
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return M_exit;
}

LoginMenu ShowLoginMenu(Member* member) {
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		//ȭ�� �ʱ�ȭ
		system("cls");
		//�޴�
		cout << "1. �ܾ���\n";
		cout << "2. �ϱ�\n";
		cout << "3. ����\n";
		cout << "4. ����\n";
		//�α��ν� �ٷ� ���Ͼ��� �ְ� �غ�
		ofstream writefile;
		int writei = 0;//writei�� �������� ����� ���Ͽ� ������� �ܾ��ۼ����� �ʿ�
		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			WordbookMenu wordbookmenu;
			wordbookmenu = ShowWordbookMenu(member);
			break;
			return L_wordbook;
		case '2':
			StudyMenu studymenu;
			studymenu = ShowStudyMenu(member);
			break;
			return L_memorize;
		case '3':
			QuizMenu quizmenu;
			quizmenu = ShowQuizMenu(member);
			break;
			return L_quiz;
		case '4':
			writefile.open(member->getID());
			writefile << member->getPassword() << endl;
			
			while (writei < member->wordlist.getSize())
			{//�������ٺϸ�ũ �Է��� �Է� while���� ����
				writefile << member->wordlist.getWord(writei).getWord() << "/" << member->wordlist.getWord(writei).getMeaning() << "/";
				if (member->wordlist.getWord(writei).getBookmark() == true) {//�ϸ�ũO�� O�Է�
					writefile << "O" << endl;
				}
				else {//�ϸ�ũx�� x�Է�
					writefile << "X" << endl;
				}
				writei++;
			}
			
			writefile.close();//�������� ���� ����
			return L_exit;
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return L_exit;
}


WordbookMenu ShowWordbookMenu(Member* member) {
	
	string select;
	string s[3];
	while (getchar() != '\n'); //�Է¹��� �ʱ�ȭ
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		
		//ȭ�� �ʱ�ȭ
		system("cls");
		//���ܾ�
		member->wordlist.showAll();
		cout << endl;//���ٶٰ�
		//�޴�
		cout << "1. �ܾ��߰�\n";
		cout << "2. �ܾ�ã��\n";
		cout << "3. �ܾ����\n";
		cout << "4. ����\n";
		//���ϴ� �޴� �Է¹ޱ�
		
		getline(cin, select);
				
		if (select == "1")		//�ܾ� �߰�
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;

			cout << "�߰��� �ܾ �Է����ּ���> ";
			getline(cin, s[0]);
			
			if (member->wordlist.search(s[0]) != -1)
			{
				cout << "�̹� �����ϴ� �ܾ��Դϴ�. �����Ͻðڽ��ϱ�?> 1.YES 2.NO";
				string st; // �ӽ� string 
				
				while (1)
				{
					
					getline(cin, select);
					if (select == "1")
					{
						cout << "������ �ǹ̸� �Է����ּ���> ";
						getline(cin, st);
						member->wordlist.changeMeaning(member->wordlist.search(s[0]), st);						
						cout << "�ܾ ���������� �����Ǿ����ϴ�.";
						system("pause>null");

						break;
					}
					else if (select == "2")
					{
						break;
					}
					else
						cout << "��Ȯȯ �޴��� �Է����ּ��� 1.YES 2.NO ";
				}
			}
			else
			{
				cout << "���� �Է����ּ���> ";
				getline(cin, s[1]);
				s[2] = "X"; //�ʱⰪ �ϸ�ũ X
				Word a(s);
				member->wordlist.add(s);
				member->writefile();
				cout << "�ܾ ���������� �ԷµǾ����ϴ�.";
				system("pause>null");
			}
		}
		else if (select == "2")   //�ܾ� ã��
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;
			if (member->wordlist.getSize()) // �ܾ ������
			{
				cout << "ã����� �ܾ �Է����ּ���> ";
				getline(cin, s[0]);
				int index = member->wordlist.search(s[0]);
				if (index == -1)
				{
					cout << "�ش� �ܾ�� �������� �ʽ��ϴ�.";
					system("pause>null");
				}
				else
				{
					cout << endl << endl << "     " << member->wordlist.getWord(index).getWord() << endl << endl;
					cout << "     " << member->wordlist.getWord(index).getMeaning() << endl;
					system("pause>null");
				}
			}
			else
			{
				cout << "�ܾ����� ����ֽ��ϴ�.";
				system("pause>null");
			}

		}
		else if (select == "3")		//�ܾ� ����
		{
			system("cls");
			member->wordlist.showAll();
			cout << endl;
			if (member->wordlist.getSize()) // �ܾ ������
			{
				cout << "������ ���ϴ� �ܾ �Է����ּ���> ";
				getline(cin, s[0]);
				int index = member->wordlist.search(s[0]);
				if (index == -1)
				{
					cout << "�ش� �ܾ�� �������� �ʽ��ϴ�.";
					system("pause>null");
				}
				else
				{
					
					cout << "���� �����Ͻðڽ��ϱ�? 1.YES 2.NO ";
					while (1)
					{
						
						cin >> select;
						if (select == "1")
						{
							member->wordlist.del(index);
							member->writefile();
							cout << "�ܾ ���������� �����Ǿ����ϴ�.";
							system("pause>null");
							while (getchar() != '\n');
							break;
						}
						else if (select == "2")
						{
							break;
						}
						else
							cout << "��Ȯȯ �޴��� �Է����ּ��� 1.YES 2.NO ";
					}
				}

			}
			else
			{
				cout << "�ܾ����� ����ֽ��ϴ�.";
				system("pause>null");
			}
		}
		else if (select == "4")
			return W_exit;			
	
		else
		{
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			system("pause>null");
		}
		continue;
		return W_exit;

		/*
				case '4':
				return W_exit;//����
				default:
				cout << "\n�ùٸ� �޴��� �������ּ���\n";
				break;
				}
				}
				return W_exit; */
	}
}

StudyMenu ShowStudyMenu(Member* member)
{
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		//ȭ�� �ʱ�ȭ
		system("cls");

		Study study(&(member->wordlist));//ȸ���� �ܾ��� study���߰�

		cout << "1. �ϸ�ũ����\n";
		cout << "2. �ǹ̸�����\n";
		cout << "3. �ܾ����\n";
		cout << "4. �Բ�����\n";
		cout << "5. ����\n";
		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			study.showBookmark();
			break;
			return  S_bookmark;//�ϸ�ũ����
		case '2':
			study.showMeaning();
			break;
			return  S_Meaning;//�ǹ̸�����
		case '3':
			study.showWord();
			break;
			return S_Word;//�ܾ����
		case '4':
			study.showTogether();
			break;
			return S_Together;//�Բ�����
		case '5':
			return S_exit;//����
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return S_exit;
}

QuizMenu ShowQuizMenu(Member* member) {
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		Quiz q(&(member->wordlist));
		//ȭ�� �ʱ�ȭ
		system("cls");
		//�޴�
		cout << "1. �ܾ� ���� - �ϸ�ũ\n";
		cout << "2. �ܾ� ���� - ��ü\n";;
		cout << "3. ����\n";

		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			q.quizBookmark();  //bookmark quiz �� ��� string �޾ư����� ����������� "n"�� ������
			break;
			return Q_bookmarkquiz;
		case '2':
			q.quizAll();  //quiz �� ��� string �޾ư����� ����������� "n" �� ������
			break;
			return Q_meaningquiz;
		case '3':
			return Q_exit;
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return Q_exit;
}