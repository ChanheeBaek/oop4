#include "member.h"

/* ���߿� �ð������� �߰� �غ��°� ���? 
	1. ��й�ȣ �Է¹����� �Ⱥ��̰� ******�̷� ������ ǥ�õǰ� 
	2. ��й�ȣ ������ Ư������ �ϳ��̻� ���԰� ���� ���Ǻο��ϱ�
	3. ��й�ȣ ������ Ʋ���� �ڵ�����	
*/

void Member::signup() {
	string ID[4];//ID[0] = �Է¹���ID, ID[1] = .txt ID[2] = �н����� ID[3] = �н�����Ȯ��
	ID[1] = ".txt";
	system("cls");
	while (1) {
		cout << "ID(8�����̳�) : ";
		cin.clear();	//�Է¹��� �ʱ�ȭ		
		getline(cin, ID[0]);
		while (ID[0].length() == 0 || ID[0].length() > 8) {
			cout << "���̵�� �ݵ�� �Է��ؾ��ϰ� �ִ� 8�� �Է��ؾ��մϴ�\n";
			cout << "ID(8�����̳�) : ";
			getline(cin, ID[0]);
		}
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);//���� ���̵� �̹��ִ��� Ȯ���ϱ� ���� �ϴ� ifstream���� ���Ͽ���
		if (myfile.is_open()) {
			cout << "�̹� ��ϵǾ��ִ� ID�Դϴ�. �ٸ� ���̵� �Է����ּ���" << endl;
			myfile.close();
		}
		else {
			myfile.close();//ifstream���� �������Ƿ� ������ �ϴ� �ݴ´�(�������̵� ���ٴ°� Ȯ��)
			while (1) {
				cout << "Password(12�����̳�) : ";
				getline(cin, ID[2]);
				while (ID[2].length() == 0 || ID[2].length() > 12) {
					cout << "�н������ �ݵ�� �Է��ؾ��ϰ� �ִ� 12�� �Է��ؾ��մϴ�\n";
					cout << "Password(12�����̳�) : ";
					getline(cin, ID[2]);
				}
				cout << "Password ��Ȯ��: ";
				getline(cin, ID[3]);
				ofstream myfile(ID[0]);//���� �̸��� ������ ofstream���� ����
				if (ID[2] == ID[3]) {
					myfile << ID[2] << "\n";
					break;
				}
				else {
					cout << " �н����尡 ��ġ���� �ʽ��ϴ�. ���Է¹ٶ��ϴ�." << endl;
				}
			}
			break;
		}
	}
}


bool Member::login() {
	string ID[4];//ID[0] = �Է¹���ID, ID[1] = .txt ID[2] = �н����� ID[3] = �н�����Ȯ��
	ID[1] = ".txt";
	system("cls");
	while (1) {
		cout << "ID : ";
		cin.clear();	//�Է¹��� �ʱ�ȭ
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		getline(cin, ID[0]);
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);
		if (myfile.is_open()) {
			getline(myfile, ID[3]);//�����̸��� ������ �н����� Ȯ���ϱ� ���� �̸� ����
			while (1) {
				cout << "Password : ";
				getline(cin, ID[2]);
				if (ID[2] == ID[3]) {
					/* ���⿡ ���� �Է����� �ܾ� �о����*/
					return true;
				}
				else {
					cout << " �н����尡 ��ġ���� �ʽ��ϴ�. ���Է¹ٶ��ϴ�." << endl;
				}
			}
		}
		else {
			cout << "��ϵǾ����� ���� ID�Դϴ�. ȸ������ �Ͻðڽ��ϱ�? 1.YES 2.NO  ";
			int a;
			cin >> a;
			while (1) {
				if (a == 1) {
					signup();//ȸ�������Ҳ��� ���Ҳ��� �����ϵ��� ����
					return false;//ȸ�����ԿϷ��� �ڵ����� �޴��� ������������
				}
				else if (a == 2) {
					return false;//no�ϰ�� �ٽ� �޴��� �������� ����
				}
				else
					cout << "�߸��� ���� �Է��ϼ̽��ϴ�.��Ȯ�� �ٶ��ϴ�. 1.YES 2.NO  ";
				cin >> a;
			}
		}
	}
}

