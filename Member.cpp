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
			readID = ID[0];//성공적으로 열었을시 ID저장
			password = ID[3];//저장되어있는 password에 따라 저장
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
	while (1) {
		system("cls");
		string line;//파일에서 단어 한줄씩 읽어서 저장하는곳
		int index, sindex;
		cout << "1.ID" << endl;
		cout << "2.전체퀴즈결과" << endl;
		cout << "3.종료" << endl;
		int a;
		cin >> a;
		
		while (1) {
			if (a == 1) {
				string ID[3];//ID[0] = 입력받은ID, ID[1] = .txt
				ID[1] = ".txt";
				system("cls");
				while (getchar() != '\n');
				while (1) {
					cout << "ID : ";
					getline(cin, ID[0]);
					ID[0] = ID[0] + ID[1];
					ifstream myfile(ID[0]);
					if (myfile.is_open()) {
						string str[3];//3개항목저장할곳
						string cutter = "/";//자르는기준
						getline(myfile, ID[2]);//처음은 비번이라 한번 읽은뒤 다음줄부터실행
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
						cout << "등록되어있지 않은 ID입니다. 메뉴를 종료 하시겠습니까? 1.YES 2.NO  ";
						int b;
						cin >> b;
						while (getchar() != '\n');
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
				break;
			}//ID
			else if (a == 2) {
				system("cls");
				cout << "전체 퀴즈 결과" << endl;
				ifstream quizresultfile("quizresult.txt");
				string cutter = ":";//자르는기준
				int firstID = 0;//처음인지아닌지판단하기용
				vector<Quizresult> sortquizresult;
				vector<Quizresult>::iterator p1;
				string str[2];//2개항목저장할곳(아이디,스코어)
				if (quizresultfile.is_open()) {
					while (!quizresultfile.eof())
					{
						getline(quizresultfile, line);//한줄씩 읽어서
						index = line.find(cutter);
						if (index == -1){ break; }
						str[0] = line.substr(0, index);//아이디
						str[1] = line.substr(index + 1, line.length());//점수
						if (firstID == 0) {//처음에는quizresult 바로 추가
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
							sortquizresult.push_back(Quizresult(str[0]));//새로추가후 다시찾아서 추가
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
			}//전체퀴즈
			else if (a == 3) {
				return false;
			}//메인메뉴로 돌아가게
		}
		//cout << "잘못된 값을 입력하셨습니다.재확인 바랍니다. 1.YES 2.NO  ";
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
	int writei = 0;//writei는 마지막에 종료시 파일에 순서대로 단어작성위해 필요
	writefile.open(getID());
	writefile << getPassword() << endl;

	while (writei < wordlist.getSize())
	{//마지막줄북마크 입력전 입력 while으로 돌림
		writefile << wordlist.getWord(writei).getWord() << "/" << wordlist.getWord(writei).getMeaning() << "/";
		if (wordlist.getWord(writei).getBookmark() == true) {//북마크O시 O입력
			writefile << "O" << endl;
		}
		else {//북마크x시 x입력
			writefile << "X" << endl;
		}
		writei++;
	}
	writefile.close();//마무리로 파일 닫음
}

void Member::writequizresult(string score) {
	if (score != "n") {
		ofstream writefile;
		writefile.open("quizresult.txt", ios::app);//quizresult라는 단어가 10글자이므로 아이디랑 겹칠일이 없음,ios::app으로 마지막부터쓰도록추가
		string line;//아이디가 .txt로 저장이 되므로(파일읽기위해) .txt를 뺀 나머지 입력시 아이디부분
		line = readID.substr(0, readID.length() - 4);//txt부분잘라냄
		writefile << line << ":" << score << endl;//저장시 ID.txt:점수/점수 이런식으로 저장
		writefile.close();//마무리로 파일 닫음
	}
}