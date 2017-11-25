#include "member.h"

/* 나중에 시간남으면 추가 해보는게 어떨까? 
	1. 비밀번호 입력받을때 안보이게 ******이런 식으로 표시되게 
	2. 비밀번호 조건을 특수문자 하나이상 포함과 같이 조건부여하기
	3. 비밀번호 여러번 틀리면 자동종료	
*/

void Member::signup() {
	string ID[4];//ID[0] = 입력받은ID, ID[1] = .txt ID[2] = 패스워드 ID[3] = 패스워드확인
	ID[1] = ".txt";
	system("cls");
	while (1) {
		cout << "ID(8글자이내) : ";
		cin.clear();	//입력버퍼 초기화		
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
	while (1) {
		cout << "ID : ";
		cin.clear();	//입력버퍼 초기화
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		getline(cin, ID[0]);
		ID[0] = ID[0] + ID[1];
		ifstream myfile(ID[0]);
		if (myfile.is_open()) {
			getline(myfile, ID[3]);//파일이름이 있으면 패스워드 확인하기 위해 미리 저장
			while (1) {
				cout << "Password : ";
				getline(cin, ID[2]);
				if (ID[2] == ID[3]) {
					/* 여기에 파일 입력으로 단어 읽어오자*/
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

