#include <iostream>
#include "menu.h"
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

LoginMenu ShowLoginMenu() {
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
			wordbookmenu = ShowWordbookMenu();
			return L_wordbook;
		case '2':
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

WordbookMenu ShowWordbookMenu() {
	//�޴��� ����� �Է¹��� ������ �ݺ�
	while (1)
	{
		//ȭ�� �ʱ�ȭ
		system("cls");
		//�޴�
		cout << "1. �ܾ��\n";
		cout << "2. �ܾ��߰�\n";
		cout << "3. �ܾ�ã��\n";
		cout << "4. ����\n";
		//���ϴ� �޴� �Է¹ޱ�
		char select;
		cin >> select;
		switch (select)
		{
		case '1':
			return W_all;//�ܾ��
		case '2':
			return W_add;//�ܾ��߰�
		case '3':
			return W_search;//�ܾ�ã��
		case '4':
			return W_exit;//����
		default:
			cout << "\n�ùٸ� �޴��� �������ּ���\n";
			break;
		}
	}
	return W_exit;
}