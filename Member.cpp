#include "member.h"
#include "menu.h"

/* ���߿� �ð������� �߰� �غ��°� ���?
1. ��й�ȣ �Է¹����� �Ⱥ��̰� ******�̷� ������ ǥ�õǰ�
2. ��й�ȣ ������ Ư������ �ϳ��̻� ���԰� ���� ���Ǻο��ϱ�
3. ��й�ȣ ������ Ʋ���� �ڵ�����
*/

void Member::signup() {
	string ID[4];//ID[0] = �Է¹���ID, ID[1] = .txt ID[2] = �н����� ID[3] = �н�����Ȯ��
	ID[1] = ".txt";
	system("cls");
	getline(cin, ID[0]);
	while (1) {
		cout << "ID(8�����̳�) : ";
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
	getline(cin, ID[0]);
	while (1) {
		cout << "ID : ";
		getline(cin, ID[0]);
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);
		if (myfile.is_open()) {
			getline(myfile, ID[3]);//�����̸��� ������ �н����� Ȯ���ϱ� ���� �̸� ����
			while (1) {
				cout << "Password : ";
				getline(cin, ID[2]);
				if (ID[2] == ID[3]) {
					/*����ID[0]�� admin�̸� admin�޴� �����̺κ��� return false�� ���� ID�α���â�ȶ߰Լ���*/
					if (ID[0] == "admin.txt") {
						adminlogin();
						return false;
					}
					//���⼭���� ���� �о���� �κ� ���پ� �о '/' �������� �ڸ� �� wordlist�� ����
					string str[3];//3���׸������Ұ�
					string line;//���Ͽ��� �ܾ� ���پ� �о �����ϴ°�
					string cutter = "/";//�ڸ��±���
					int index;
					while (!myfile.eof())
					{
						getline(myfile, line);
						for (int k = 0; k<3; k++) {
							index = line.find(cutter);
							str[k] = line.substr(0, index);
							line = line.substr(index + 1, line.length());
						}
						Word a(str);
						wordlist.add(a);
					}
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

bool Member::adminlogin() {
	system("cls");
	cout << "1.ID" << endl;
	cout << "2.��ü������" << endl;
	cout << "3.����" << endl;
	int a;
	cin >> a;
	while (1) {
		if (a == 1) {
			string ID[2];//ID[0] = �Է¹���ID, ID[1] = .txt
			ID[1] = ".txt";
			system("cls");
			getline(cin, ID[0]);
			while (1) {
				cout << "ID : ";
				getline(cin, ID[0]);
				ID[0] = ID[0] + ID[1];
				ifstream myfile(ID[0]);
				if (myfile.is_open()) {
					string str[3];//3���׸������Ұ�
					string line;//���Ͽ��� �ܾ� ���پ� �о �����ϴ°�
					string cutter = "/";//�ڸ��±���
					int index;
					getline(myfile, line);//ó���� ����̶� �ѹ� ������ �����ٺ��ͽ���
					while (!myfile.eof())
					{
						getline(myfile, line);
						for (int k = 0; k<3; k++) {
							index = line.find(cutter);
							str[k] = line.substr(0, index);
							line = line.substr(index + 1, line.length());
						}
						Word a(str);
						wordlist.add(a);
					}
					AdminMenu adminmenu;
					adminmenu = ShowAdminMenu(this);
					return true;//adminlogin����������
				}
				else {
					cout << "��ϵǾ����� ���� ID�Դϴ�. �޴��� ���� �Ͻðڽ��ϱ�? 1.YES 2.NO  ";
					int b;
					cin >> b;
					while (1) {
						if (b == 1) {
							return false;//�޴������ؼ� ������������
						}
						else if (b == 2) {
							break;//no�ϰ�� �ٽ� �޴��� ���� ID�ٽ��Է¹޵�����
						}
						else
							cout << "�߸��� ���� �Է��ϼ̽��ϴ�.��Ȯ�� �ٶ��ϴ�. 1.YES 2.NO  ";
						cin >> b;
					}
				}
				break;
			}
			continue;
		}//ID
		else if (a == 2) {
			return false;
		}//��ü����
		else if (a == 3) {
			return false;
		}//���θ޴��� ���ư���
		cout << "�߸��� ���� �Է��ϼ̽��ϴ�.��Ȯ�� �ٶ��ϴ�. 1.YES 2.NO  ";
		cin >> a;
	}
}

string Member::getID() {
	return readID;
}
string Member::getPassword() {
	return password;
}



