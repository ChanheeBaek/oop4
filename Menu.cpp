#include <iostream>
#include "Menu.h"
#include "Member.h"
#include "Study.h"

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
		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			WordbookMenu wordbookmenu;
			wordbookmenu = ShowWordbookMenu(member);
			return L_wordbook;
		case '2':		
			StudyMenu studymenu;
			studymenu = ShowStudyMenu(member);			
			return L_memorize;
		case '3':
			return L_quiz;
		case '4':
			return L_exit;
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return L_exit;
}

WordbookMenu ShowWordbookMenu(Member* member) {
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
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return W_add;//�ܾ��߰�
		case '2':
			return W_search;//�ܾ�ã��
		case '3':
			return W_delete;//�ܾ����
		case '4':
			return W_exit;//����
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return W_exit;
}

AdminMenu ShowAdminMenu(Member* member)
{
   //�޴��� ����� �Է¹��� ������ �ݺ�
   while (1)
   {
      //ȭ�� �ʱ�ȭ
      system("cls");
      member->wordlist.showAll();
      cout << endl;//���ٶٰ�
      //�޴�
      cout << "1. �ܾ��߰�\n";
      cout << "2. �ܾ�ã��\n";
      cout << "3. �ܾ����\n";
      cout << "4. ����\n";
      //���ϴ� �޴� �Է¹ޱ�
      char select;
      cin >> select;

      switch (select)
      {
      case '1':
         return A_add;//�ܾ��߰�
      case '2':
         return A_search;//�ܾ�ã��
      case '3':
         return A_delete;//�ܾ����
      case '4':
         return A_exit;
      default:
         cout << "\n�ùٸ� �޴��� �������ּ���\n";
         break;
      }
   }
   return A_exit;
}

StudyMenu ShowStudyMenu(Member* member)
{
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		//ȭ�� �ʱ�ȭ
		system("cls");

		Study study(member->wordlist);//ȸ���� �ܾ��� study���߰�

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
			return  S_bookmark;//�ϸ�ũ����
		case '2':
			study.showMeaning();
			break;
			return  S_Meaning;//�ǹ̸�����
		case '3':
			return S_Word;//�ܾ����
		case '4':
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