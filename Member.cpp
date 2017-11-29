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
			readID = ID[0];//���������� �������� ID����
			password = ID[3];//����Ǿ��ִ� password�� ���� ����
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
					int index, sindex;
					while (!myfile.eof())
					{
						getline(myfile, line);
						index = line.find(cutter);
						if (index == -1)
							break;
						str[0] = line.substr(0, index);
						for (int k = 1; k<3; k++) {
							sindex = index + 1;
							index = line.find(cutter, sindex);
							str[k] = line.substr(sindex, index - sindex);
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
	while (1) {
		system("cls");
		string line;//���Ͽ��� �ܾ� ���پ� �о �����ϴ°�
		int index, sindex;
		cout << "1.ID" << endl;
		cout << "2.��ü������" << endl;
		cout << "3.����" << endl;
		int a;
		cin >> a;
		
		while (1) {
			if (a == 1) {
				string ID[3];//ID[0] = �Է¹���ID, ID[1] = .txt
				ID[1] = ".txt";
				system("cls");
				while (getchar() != '\n');
				while (1) {
					cout << "ID : ";
					getline(cin, ID[0]);
					ID[0] = ID[0] + ID[1];
					ifstream myfile(ID[0]);
					if (myfile.is_open()) {
						string str[3];//3���׸������Ұ�
						string cutter = "/";//�ڸ��±���
						getline(myfile, ID[2]);//ó���� ����̶� �ѹ� ������ �����ٺ��ͽ���
						while (!myfile.eof())
						{
							getline(myfile, line);
							index = line.find(cutter);
							if (index == -1)
								break;
							str[0] = line.substr(0, index);
							for (int k = 1; k<3; k++) {
								sindex = index + 1;
								index = line.find(cutter, sindex);
								str[k] = line.substr(sindex, index - sindex);
							}
							Word a(str);
							wordlist.add(a);
						}						
						readID = ID[0];
						password = ID[2];
						WordbookMenu wordbookmenu;
						wordbookmenu = ShowWordbookMenu(this);
						readID = "admin.txt";
						password = "1234567890";
						break;
					}
					else {
						cout << "��ϵǾ����� ���� ID�Դϴ�. �޴��� ���� �Ͻðڽ��ϱ�? 1.YES 2.NO  ";
						int b;
						cin >> b;
						while (getchar() != '\n');
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
				break;
			}//ID
			else if (a == 2) {
				system("cls");
				cout << "��ü ���� ���" << endl;
				ifstream quizresultfile("quizresult.txt");
				string cutter = ":";//�ڸ��±���
				int firstID = 0;//ó�������ƴ����Ǵ��ϱ��
				vector<Quizresult> sortquizresult;
				vector<Quizresult>::iterator p1;
				string str[2];//2���׸������Ұ�(���̵�,���ھ�)
				if (quizresultfile.is_open()) {
					while (!quizresultfile.eof())
					{
						getline(quizresultfile, line);//���پ� �о
						index = line.find(cutter);
						if (index == -1){ break; }
						str[0] = line.substr(0, index);//���̵�
						str[1] = line.substr(index + 1, line.length());//����
						if (firstID == 0) {//ó������quizresult �ٷ� �߰�
							sortquizresult.push_back(Quizresult(str[0]));
							firstID++;
						}
						bool sameID = false;
						for (p1 = sortquizresult.begin(); p1 != sortquizresult.end(); p1++)
						{
							if (p1->getID() == str[0]) {
								p1->add(str[1]);
								sameID = true;
								break;
							}
						}
						if (sameID == false) {
							sortquizresult.push_back(Quizresult(str[0]));//�����߰��� �ٽ�ã�Ƽ� �߰�
							for (p1 = sortquizresult.begin(); p1 != sortquizresult.end(); p1++)
							{
								if (p1->getID() == str[0]) {
									p1->add(str[1]);
									sameID = true;
									break;
								}
							}
						}
					}
					sort(sortquizresult.begin(), sortquizresult.end(), Quizresult::comp_Quizresult);
					for (p1 = sortquizresult.begin(); p1 != sortquizresult.end(); p1++)
					{
						vector<string>::iterator p3;
						int i = 0;
						p1->scoresort();
						cout << "-" << p1->getID() << "-" << endl;
						for (p3 = p1->score.begin(); p3 != p1->score.end(); p3++) {
							cout << p1->score[i] << endl;
							i++;
						}
					}
				}
				quizresultfile.close();
				system("pause>null");
				break;
			}//��ü����
			else if (a == 3) {
				return false;
			}//���θ޴��� ���ư���
		}
		//cout << "�߸��� ���� �Է��ϼ̽��ϴ�.��Ȯ�� �ٶ��ϴ�. 1.YES 2.NO  ";
		//cin >> a;
	}
	return false;
}

string Member::getID() {
	return readID;
}
string Member::getPassword() {
	return password;
}

void Member::writefile() {
	ofstream writefile;
	int writei = 0;//writei�� �������� ����� ���Ͽ� ������� �ܾ��ۼ����� �ʿ�
	writefile.open(getID());
	writefile << getPassword() << endl;

	while (writei < wordlist.getSize())
	{//�������ٺϸ�ũ �Է��� �Է� while���� ����
		writefile << wordlist.getWord(writei).getWord() << "/" << wordlist.getWord(writei).getMeaning() << "/";
		if (wordlist.getWord(writei).getBookmark() == true) {//�ϸ�ũO�� O�Է�
			writefile << "O" << endl;
		}
		else {//�ϸ�ũx�� x�Է�
			writefile << "X" << endl;
		}
		writei++;
	}
	writefile.close();//�������� ���� ����
}

void Member::writequizresult(string score) {
	if (score != "n") {
		ofstream writefile;
		writefile.open("quizresult.txt", ios::app);//quizresult��� �ܾ 10�����̹Ƿ� ���̵�� ��ĥ���� ����,ios::app���� ���������;������߰�
		string line;//���̵� .txt�� ������ �ǹǷ�(�����б�����) .txt�� �� ������ �Է½� ���̵�κ�
		line = readID.substr(0, readID.length() - 4);//txt�κ��߶�
		writefile << line << ":" << score << endl;//����� ID.txt:����/���� �̷������� ����
		writefile.close();//�������� ���� ����
	}
}