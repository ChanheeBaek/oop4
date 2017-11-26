#include "member.h"
#include "menu.h"

/* 나중에 시간남으면 추가 해보는게 어떨까?
1. 비밀번호 입력받을때 안보이게 ******이런 식으로 표시되게
2. 비밀번호 조건을 특수문자 하나이상 포함과 같이 조건부여하기
3. 비밀번호 여러번 틀리면 자동종료
*/

void Member::signup() {
	string ID[4];//ID[0] = 입력받은ID, ID[1] = .txt ID[2] = 패스워드 ID[3] = 패스워드확인
	ID[1] = ".txt";
	system("cls");
	getline(cin, ID[0]);
	while (1) {
		cout << "ID(8글자이내) : ";
		getline(cin, ID[0]);
		while (ID[0].length() == 0 || ID[0].length() > 8) {
			cout << "아이디는 반드시 입력해야하고 최대 8자 입력해야합니다\n";
			cout << "ID(8글자이내) : ";
			getline(cin, ID[0]);
		}
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);//같은 아이디가 이미있는지 확인하기 위해 일단 ifstream으로 파일열음
		if (myfile.is_open()) {
			cout << "이미 등록되어있는 ID입니다. 다른 아이디를 입력해주세요" << endl;
			myfile.close();
		}
		else {
			myfile.close();//ifstream으로 열었으므로 파일을 일단 닫는다(같은아이디가 없다는것 확인)
			while (1) {
				cout << "Password(12글자이내) : ";
				getline(cin, ID[2]);
				while (ID[2].length() == 0 || ID[2].length() > 12) {
					cout << "패스워드는 반드시 입력해야하고 최대 12자 입력해야합니다\n";
					cout << "Password(12글자이내) : ";
					getline(cin, ID[2]);
				}
				cout << "Password 재확인: ";
				getline(cin, ID[3]);
				ofstream myfile(ID[0]);//만들 이름에 파일을 ofstream으로 열음
				if (ID[2] == ID[3]) {
					myfile << ID[2] << "\n";
					break;
				}
				else {
					cout << " 패스워드가 일치하지 않습니다. 재입력바랍니다." << endl;
				}
			}
			break;
		}
	}
}


bool Member::login() {
	string ID[4];//ID[0] = 입력받은ID, ID[1] = .txt ID[2] = 패스워드 ID[3] = 패스워드확인
	ID[1] = ".txt";
	system("cls");
	getline(cin, ID[0]);
	while (1) {
		cout << "ID : ";
		getline(cin, ID[0]);
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);
		if (myfile.is_open()) {
			getline(myfile, ID[3]);//파일이름이 있으면 패스워드 확인하기 위해 미리 저장
			while (1) {
				cout << "Password : ";
				getline(cin, ID[2]);
				if (ID[2] == ID[3]) {
					/*만약ID[0]가 admin이면 admin메뉴 실행이부분은 return false로 다음 ID로그인창안뜨게설정*/
					if (ID[0] == "admin.txt") {
						adminlogin();
						return false;
					}
					//여기서부터 파일 읽어오는 부분 한줄씩 읽어서 '/' 기준으로 자른 뒤 wordlist에 저장
					string str[3];//3개항목저장할곳
					string line;//파일에서 단어 한줄씩 읽어서 저장하는곳
					string cutter = "/";//자르는기준
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
					cout << " 패스워드가 일치하지 않습니다. 재입력바랍니다." << endl;
				}
			}
		}
		else {
			cout << "등록되어있지 않은 ID입니다. 회원가입 하시겠습니까? 1.YES 2.NO  ";
			int a;
			cin >> a;
			while (1) {
				if (a == 1) {
					signup();//회원가입할껀지 안할껀지 결정하도록 만듬
					return false;//회원가입완료후 자동으로 메뉴로 빠져나가도록
				}
				else if (a == 2) {
					return false;//no일경우 다시 메뉴로 나가도록 유도
				}
				else
					cout << "잘못된 값을 입력하셨습니다.재확인 바랍니다. 1.YES 2.NO  ";
				cin >> a;
			}
		}
	}
}

bool Member::adminlogin() {
	system("cls");
	cout << "1.ID" << endl;
	cout << "2.전체퀴즈결과" << endl;
	cout << "3.종료" << endl;
	int a;
	cin >> a;
	while (1) {
		if (a == 1) {
			string ID[2];//ID[0] = 입력받은ID, ID[1] = .txt
			ID[1] = ".txt";
			system("cls");
			getline(cin, ID[0]);
			while (1) {
				cout << "ID : ";
				getline(cin, ID[0]);
				ID[0] = ID[0] + ID[1];
				ifstream myfile(ID[0]);
				if (myfile.is_open()) {
					string str[3];//3개항목저장할곳
					string line;//파일에서 단어 한줄씩 읽어서 저장하는곳
					string cutter = "/";//자르는기준
					int index;
					getline(myfile, line);//처음은 비번이라 한번 읽은뒤 다음줄부터실행
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
					return true;//adminlogin빠져나가기
				}
				else {
					cout << "등록되어있지 않은 ID입니다. 메뉴를 종료 하시겠습니까? 1.YES 2.NO  ";
					int b;
					cin >> b;
					while (1) {
						if (b == 1) {
							return false;//메뉴종료해서 빠져나가도록
						}
						else if (b == 2) {
							break;//no일경우 다시 메뉴로 나가 ID다시입력받도록함
						}
						else
							cout << "잘못된 값을 입력하셨습니다.재확인 바랍니다. 1.YES 2.NO  ";
						cin >> b;
					}
				}
				break;
			}
			continue;
		}//ID
		else if (a == 2) {
			return false;
		}//전체퀴즈
		else if (a == 3) {
			return false;
		}//메인메뉴로 돌아가게
		cout << "잘못된 값을 입력하셨습니다.재확인 바랍니다. 1.YES 2.NO  ";
		cin >> a;
	}
}

string Member::getID() {
	return readID;
}
string Member::getPassword() {
	return password;
}



