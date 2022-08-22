//�������� ������ �� ��������� ���
//�� ���� "���� � �����"
//�������� ����� ��-2-18

#include <iostream> 
#include <iomanip>
#include <ctime>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include <conio.h>

using namespace std;

bool fl = 0;//���� ������ ����

//����� �������
class Menu;
class Winner;


class Player {
protected:
	string name;
	long score; //���-�� �����
	int vics;//���-�� �����

	static vector <Player*> rating;// ������ �������� (����������� ����, ������ ����������)

public:

	Player() { //����������� �� ���������
		name = "noname", score = 0; vics = 0;
	}
	void setPlayer(string n) {//����������� � ����������
		name = n;
	}
	void setPlayer() {
		string n;
		cout << "\n                             ������� ��� ������: ";
		cin >> n;
		name = n;
	}
	void setPlayer(Player *pl) {
		name = pl->name;
		score = pl->score;
		vics = pl->vics;
	}

	static void addToRating(Player *player) {// ���������� ������ � �������
		rating.push_back(player);
	}


	static void sortRating() {
		//����������� ���������� ��������
		Player* temp;
		for (size_t j = 0; j < rating.size() - 1; j++)
			for (size_t i = 0; i < rating.size() - 1; i++) {
				if (rating[i + 1]->vics > rating[i]->vics) {
					temp = rating[i + 1];
					rating[i + 1] = rating[i];
					rating[i] = temp;
				}
				if (rating[i + 1]->vics == rating[i]->vics && rating[i + 1]->score > rating[i]->score) {
					temp = rating[i + 1];
					rating[i + 1] = rating[i];
					rating[i] = temp;
				}
			}
	}

	static bool showPlayers() {
		if (rating.size() == 0) {
			cout << "                                                     ��� �������                                                       " << endl;			
			return 1;
		}
		else {
			sortRating();

			for (size_t i = 0; i < rating.size(); i++) {
				cout << "                                " << setw(10) << i + 1 << setw(15) << rating[i]->name << setw(10) << rating[i]->score << setw(10) << rating[i]->vics << endl;
			}
			return 0;
		}
	}

	static void showRating() {// ���������� � ����� ��������
		system("cls");
		cout << endl << endl ;
		cout  <<                "                                                   *   �������   *                                                     " << endl << endl;

		if (rating.size() == 0) 		cout << "                                                     ��� �������                                                       " << endl;

		else {
			sortRating();
			cout <<"                               "<<setw(12) << "�����" << setw(12) << "���" << setw(11) << "����" << setw(13) << "������" << endl;
			cout <<"                               " << "------------------------------------------------------" << endl;
			for (size_t i = 0; i < rating.size(); i++) {
				cout << "                              " << setw(10) << i + 1 << setw(15) << rating[i]->name << setw(10) << rating[i]->score << setw(10) << rating[i]->vics << endl;
			}
		}
		cout << endl << endl << "                                                ESC     �����      ESC                    " << endl;

	}

	static Player *findPlayer(int n) {
		for (size_t i = 0; i < rating.size(); i++) {
			if (i == n) {
				return rating[i];
			}
		}
		return new Player;
	}



	int addToScore(int s, Player *pl) { //������� ������ ������ (���������� ����� ������)

		score = score + s; 
		if (score - pl->score == 30 || score - pl->score == 50) {
			system("cls");
			cout << endl << endl<<endl<<endl<<endl ;
			cout << "                                                      /\\        /\\                                        " << endl;
			cout << "                                                     /  \\      /  \\                                       " << endl;
			cout << "                                                                                                            " << endl;
			cout << "                                                   / / /        / / /                                       " << endl;
			cout << "                                                                                                            " << endl;
			cout << "                                                        \\______/                                           " << endl << endl << endl;
			cout << "                                           �����������, " << name << ", �� ��������!                        " << endl;
			cout << "                                           ���� ����: " << score - pl->score<< endl;
			vics++;
			fl = 0;
			return 1;

		}
		else if (score - pl->score > 50) {
			system("cls");
			cout << endl << endl << endl << endl << endl<<endl;
			cout << "                                                     \\__/    \\__/                                     " << endl;
			cout << "                                                               |                                        " << endl;
			cout << "                                                        ______                                          " << endl;
			cout << "                                                       /      \\                                        " << endl<<endl<<endl;
			cout << "                                           ��������, " << name << ", �� ���������                       " << endl;
			cout << "                                           ���� ����: " << score - pl->score << endl ;

			fl = 0;
			return 2;

		}
		return 0;
	}

	static void findInRanking(Player *pl) {//������ ������ � ��������
		sortRating();
		for (size_t i = 0; i < rating.size(); i++)
			if (rating[i]->name == pl->name)
		cout <<  "                                           ����� � ��������: " << i + 1 << "/" << rating.size() << endl;
	}

	void showPlayers(Player *pl1, Player *pl2, Player *pl1copy, Player *pl2copy) {
		system("cls");
		cout << endl << endl << endl ;

		cout << "                                   " << setw(16) << "����� �1" << setw(25) << "����� �2" << setw(30) << "(������� '-->')" << endl;
		cout << "                                   " << setw(15) << pl1->name << setw(25) << pl2->name << setw(31) << "(����������� 1)"<< endl;
		cout << "                                   " << setw(15) << "����: " << pl1->score - pl1copy->score<< setw(23) << "����: " << pl2->score - pl2copy->score << setw(30) << "(�������� ��� 2)" << endl;
	}
	void showName() {
		cout << endl  << "                             " << name << ": ";
	}
	

	~Player() {} //����������
};

vector <Player*> Player ::rating;// ����������� ���� � ���������� ������� (������ ���������� �� ��� Player)


class Winner :public Player {//������������ ������ Player ���������� ������������ public
public:

	void congratulate() {//����� ������������
		system("cls");
		cout <<  endl<<endl<<endl;
		cout << "                       /\\        /\\                         " << endl;
		cout << "                      /  \\      /  \\                        " << endl;

		cout << "                    / / /        / / /                        " << endl;
		cout << "                                                              " << endl;
		cout << "                         \\______/                            " << endl << endl<<endl;
		cout << "          �����������, " << name << ", �� ��������!             " << endl;
		cout << "          ���� ����: " << score << endl ;


	}

	~Winner() {}
};


class Dices {
	int dices[5];
public:

	Dices() {// ����������� �� ���������
		for (int i = 0; i < 5; i++)
			dices[i] = 1;
	}

	int Roll() {// "������" ������
		int finalScore;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < 5; i++)
			dices[i] = rand() % 6 + 1; // ������������� ������ ���������� ���������� �� 1 �� 6


		finalScore = calcScore();

		return finalScore;

	}

	int reRoll() {// "��������" ������

		int firstScore, finalScore; //���-�� ����� �� ��������� � ����� ��������������
		firstScore = calcScore();

		for (int i = 0; i < 5; i++) {
			if (dices[i] != 1 && dices[i] != 5)
				dices[i] = rand() % 6 + 1;
		}

		finalScore = calcScore() - firstScore;

		return finalScore;
	}

	void showDices() {//������� ������ ������
		cout << endl;
		cout << "                                 _______    " << " _______    " << " _______    " << " _______    " << " _______    " << endl;
		cout << "                                |       |   " << "|       |   " << "|       |   " << "|       |   " << "|       |   " << endl;

		for (int j = 1; j <= 3; j++) {
			for (int i = 0; i < 5; i++) {
				if (i == 0)cout << "                                ";
				switch (j) {
				case 1:
					switch (dices[i]) {
					case 1: empty(); break;
					case 2: right(); break;
					case 3: right(); break;
					case 4: pair(); break;
					case 5: pair(); break;
					case 6: pair(); break;
					} break;
				case 2:
					switch (dices[i]) {
					case 1: center(); break;
					case 2: empty(); break;
					case 3: center(); break;
					case 4: empty(); break;
					case 5: center(); break;
					case 6: pair(); break;
					} break;
				case 3:
					switch (dices[i]) {
					case 1: empty(); break;
					case 2: left(); break;
					case 3: left(); break;
					case 4: pair(); break;
					case 5: pair(); break;
					case 6: pair(); break;
					} break;
				}
				if (i == 4) cout << endl;
			}
		}

		cout <<"                                "<< "|_______|   " << "|_______|   " << "|_______|   " << "|_______|   " << "|_______|   " <<endl;
	}
	//��������������� ������� ��� ������ ������
	void empty() { cout << "|       |   "; }
	void right() { cout << "|    0  |   "; }
	void left() { cout << "|  0    |   "; }
	void center() { cout << "|   0   |   "; }
	void pair() { cout << "|  0 0  |   "; }


	int calcScore() {//������� �����
		int k = 0; //���-�� �����
		for (int i = 0; i < 5; i++) {
			if (dices[i] == 1) { k += 10; }
			else if (dices[i] == 5) { k += 5; }
		}
		return k;
	}

	~Dices() {}//����������


};


class Menu {
public:
	void showMenu() {// ����� ���� 
		system("cls");
		int n;// ����� ������
		cout << endl<<endl;
		cout << "                                          ________    ________  ___________              " << endl;
		cout << "                             |*|    /*/  |*|    |*|  |*|            |*|      |*|    /*|*|" << endl;
		cout << "                             |*|  /*/    |*|    |*|  |*|            |*|      |*|   /*/|*|" << endl;
		cout << "                             |*|/*/      |*|    |*|  |*|            |*|      |*|  /*/ |*|" << endl;
		cout << "                             |*|\\*\\      |*|    |*|  |*|            |*|      |*| /*/  |*|" << endl;
		cout << "                             |*|  \\*\\    |*|    |*|  |*|            |*|      |*|/*/   |*|" << endl;
		cout << "                             |*|    \\*\\  |*|____|*|  |*|______      |*|      |*|*/    |*|" << endl;
		cout << "                                                                                         " << endl;
		cout << "                                                 1   ������ ����    1                    " << endl;
		cout << "                                                 2 �������� ������� 2                    " << endl;
		cout << "                                                 3   ������� ����   3                    " << endl;
		cout << "                                                 4      �����       4                    " << endl;
		cout << "                                                                                         " << endl;
		cout << "                                                          " ;

		cin >> n;
		switch (n) {
		case 1: startGame();
			if (_getch() == 27)//������� �� esc
			{
				showMenu();
			}
			break;
		case 2: Player::showRating(); //������������� ������ ������� ������ ������ Player
			if (_getch() == 27)//������� �� esc
			{
				showMenu();
			}
			break;
		case 3: showRules(); break;
		case 4: exit(0);
		}
	}


	void startGame() {//������ ����
		system("cls");
		bool  rolled = 0,   noplayers;
		int s, turn = 1, b, wnr, num, opp, choice;
		int a;
		Player *pl1 = new Player;
		Player *pl2 = new Player;
		Player* pl1copy = new Player;
		Player* pl2copy = new Player;
		fl = 1;

		//�����������

		cout << endl <<endl<< "                                                 *   �����������   *                    " << endl <<endl;
		cout <<         "                                                       ����� �1                          " << endl;
		cout <<         "                                               1-������������   2-�����               | ";

		cin >> choice;
		if (choice==2) {
			pl1->setPlayer();
			pl1->addToRating(pl1);
		}
		else { 
			cout << endl;
			noplayers = pl1->showPlayers();
			if (noplayers) {
				pl1->setPlayer();
				pl1->addToRating(pl1);
			}
			else {
				cout << endl<<"                             ������� ����� ������: ";
				cin >> num;
				pl1 = pl1->findPlayer(num-1);
				pl1copy->setPlayer(pl1);
			
			}
		}
		cout << endl <<endl<< "                                                       ����� �2                          " << endl;
		cout <<               "                                      1-������������    2-�����    3-���������        | ";
		cin >> opp;
		
		if (opp==2) {
				pl2->setPlayer();
				pl2->addToRating(pl2);
		}
		else if (opp==1){
			cout << endl;
			noplayers = pl2->showPlayers();
			if (noplayers) {
				pl2->setPlayer();
				pl2->addToRating(pl2);
			}
			else {
				cout << endl << "                             ������� ����� ������: ";
				cin >> num;
				pl2 = pl2->findPlayer(num-1);
				pl2copy->setPlayer(pl2);
				
			}
			
		}
		else {
			pl2->setPlayer("COMPUTER");
		}
		pl1->showPlayers(pl1, pl2, pl1copy, pl2copy);



		//������� ����

		Dices dices;
		while (fl) {

			switch (turn) {


//��� ������� ������
			case 1:
				pl1->showName();
				a = _getch();
			
		
					switch (a) {

					case 77:
						s = dices.Roll();
						wnr = pl1->addToScore(s, pl1copy);
						if (wnr == 1) {

							pl1->findInRanking(pl1);
							if (_getch() == 27)
								showMenu();
							else showMenu();
							break;
						}
						else if (wnr == 2) {
					
							if (_getch() == 27)
								showMenu();
							else showMenu();
							break;
						}
						pl1->showPlayers(pl1, pl2, pl1copy, pl2copy);
						dices.showDices();
						pl1->showName(); cout << setw(5) << "+" << s << "        | "; 
						rolled = 1;


						cin >> b;
							if (b == 1) {
							Dices dices1(dices);
							int s1 = s;
							s = dices.reRoll();
							wnr = pl1->addToScore(s, pl1copy);
							if (wnr == 1) {

								pl1->findInRanking(pl1);
								if (_getch() == 27)
									showMenu();
								else showMenu();
								break;
							}
							else if (wnr == 2) {
							
								if (_getch() == 27)
									showMenu();
								else showMenu();
								break;
							}
							pl1->showPlayers(pl1, pl2, pl1copy, pl2copy);
							dices1.showDices();//����� ������ ��� ������ ������
							dices.showDices();//����� ������ ��� ���������
							pl1->showName(); cout << setw(5) << "+" << s1 << setw(15) << " |�����������" << setw(6) << "+" << s << endl;
							rolled = 0;
							turn = 2;
						}
						else if (b == 2) {//�������� ���� 
							rolled = 0;
							turn = 2;
						
						}

						break;

					case 75:
						if (!rolled)  cout << "!!! ������ ���������� ������� !!!";
						break;


					case 80:

						rolled = 0;
						turn = 2;
						break;

					default: cout << "!!! �������� ������� !!!" ;

						break;
					}
				
				break;

//��� ������� ������
			case 2:
				pl2->showName();
				if (opp != 3)
					a = _getch();
				else
					a = 77;
		
					switch (a) {
					case 77:

						s = dices.Roll();
						wnr = pl2->addToScore(s, pl2copy);
						if (wnr == 1) {

							pl2->findInRanking(pl2);
							if (_getch() == 27)
								showMenu();
							else showMenu();
							break;
						}
						else if (wnr == 2) {
					
							if (_getch() == 27)
								showMenu();
							else showMenu();
							break;
						}
						pl2->showPlayers(pl1, pl2, pl1copy, pl2copy);
						dices.showDices();
						if (opp != 3) { pl2->showName(); cout << setw(5) << "+" << s << "        | "; }
						else { pl2->showName(); cout << " (�������)" << setw(5) << "+" << s << "        | "; }
						rolled = 1;


						if (opp!=3)
							cin >> b;
						else {
							b = rand() % 2 + 1;
							cout << b << endl;
						}
						if (b==1){
							Dices dices1(dices);
							int s1 = s;
							s = dices.reRoll();
							wnr = pl2->addToScore(s, pl2copy);
							if (wnr == 1) {
								pl1->findInRanking(pl1);
								if (_getch() == 27) 
									showMenu();
								else showMenu();
								break;
							}
							else if (wnr == 2) {
								
								if (_getch() == 27)
									showMenu();
								else showMenu();
								break;
							}
							pl2->showPlayers(pl1, pl2, pl1copy, pl2copy);
							dices1.showDices();//����� ������ ��� ������ ������
							dices.showDices();//����� ������ ��� ���������
							pl2->showName(); cout << setw(5) << "+" << s1 << setw(15) << " |�����������" << setw(6) << "+" << s << endl;
							rolled = 0;
							turn = 1;
						}
						else if (b == 2) {//�������� ���� 
							rolled = 0;
							turn = 1;
						
						}
						break;

					case 75:
						if (!rolled)  cout << "!!! ������ ���������� ������� !!!";
						break;


					case 80:
						rolled = 0;
						turn = 1;
						break;

					default: cout << "!!! �������� ������� !!!" ;

						break;

					}
				
				break;

			}
		}
	}

	void showRules() {//����� ������
		char text[]{ "                        ����� �������� ���� ������, �������� ������� �������� ��������� �������.\n                �����, �������� ������� ������� �� 1 � 5 ����� ������������ (������������ ����� ������ 1 ���).\n                        ������� ����� : �1� � 10 �����, �5� � 5 �����. ������ ������ �� �������.\n                 ���� ������� ����� 300 ��� 500 �����. ��������� �����, ������ ��������� ����� ����� �����." };
		system("cls");
		cout << endl <<endl<< "                                                  *   ������� ����   *                    " << endl << endl;

		cout << text << endl << endl;
		cout << setw(40) << "�������" << setw(6) << "-->" << endl;//(������� ������)
		cout << setw(40) << "�����������" << setw(5) << "1" << endl;
		cout << setw(40) << "�������� ���" << setw(5) << "2" << endl ; 
		cout << setw(40) << "�����" << setw(6) << "ESC" << endl << endl;

		cout << "                                                 ESC     �����      ESC                    " << endl;
		if (_getch() == 27)//������� �� esc
		{
			showMenu();
		}

	}
};


int main() {
	setlocale(LC_ALL, "rus");
	Menu menu;

	menu.showMenu();

	system("pause");
	return 0;

}