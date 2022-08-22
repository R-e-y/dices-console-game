//Курсовая работа по дсциплине ООП
//На тему "Игра в кости"
//Артышова Жанна ПИ-2-18

#include <iostream> 
#include <iomanip>
#include <ctime>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
#include <conio.h>

using namespace std;

bool fl = 0;//флаг начала игры

//Анонс классов
class Menu;
class Winner;


class Player {
protected:
	string name;
	long score; //кол-во очков
	int vics;//кол-во побед

	static vector <Player*> rating;// список рейтинга (статическое поле, вектор указателей)

public:

	Player() { //конструктор по умолчанию
		name = "noname", score = 0; vics = 0;
	}
	void setPlayer(string n) {//конструктор с аргмуентом
		name = n;
	}
	void setPlayer() {
		string n;
		cout << "\n                             Введите имя игрока: ";
		cin >> n;
		name = n;
	}
	void setPlayer(Player *pl) {
		name = pl->name;
		score = pl->score;
		vics = pl->vics;
	}

	static void addToRating(Player *player) {// добавление игрока в рейтинг
		rating.push_back(player);
	}


	static void sortRating() {
		//пузырьковая сортировка рейтинга
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
			cout << "                                                     НЕТ ИГРОКОВ                                                       " << endl;			
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

	static void showRating() {// сортировка и вывод рейтинга
		system("cls");
		cout << endl << endl ;
		cout  <<                "                                                   *   РЕЙТИНГ   *                                                     " << endl << endl;

		if (rating.size() == 0) 		cout << "                                                     НЕТ ИГРОКОВ                                                       " << endl;

		else {
			sortRating();
			cout <<"                               "<<setw(12) << "МЕСТО" << setw(12) << "ИМЯ" << setw(11) << "ОЧКИ" << setw(13) << "ПОБЕДЫ" << endl;
			cout <<"                               " << "------------------------------------------------------" << endl;
			for (size_t i = 0; i < rating.size(); i++) {
				cout << "                              " << setw(10) << i + 1 << setw(15) << rating[i]->name << setw(10) << rating[i]->score << setw(10) << rating[i]->vics << endl;
			}
		}
		cout << endl << endl << "                                                ESC     НАЗАД      ESC                    " << endl;

	}

	static Player *findPlayer(int n) {
		for (size_t i = 0; i < rating.size(); i++) {
			if (i == n) {
				return rating[i];
			}
		}
		return new Player;
	}



	int addToScore(int s, Player *pl) { //функция броска костей (добавление очков игроку)

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
			cout << "                                           ПОЗДРАВЛЯЕМ, " << name << ", ВЫ ВЫИГРАЛИ!                        " << endl;
			cout << "                                           ВАШИ ОЧКИ: " << score - pl->score<< endl;
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
			cout << "                                           ИЗВИНИТЕ, " << name << ", ВЫ ПРОИГРАЛИ                       " << endl;
			cout << "                                           ВАШИ ОЧКИ: " << score - pl->score << endl ;

			fl = 0;
			return 2;

		}
		return 0;
	}

	static void findInRanking(Player *pl) {//посиск игрока в рейтинге
		sortRating();
		for (size_t i = 0; i < rating.size(); i++)
			if (rating[i]->name == pl->name)
		cout <<  "                                           МЕСТО В РЕЙТИНГЕ: " << i + 1 << "/" << rating.size() << endl;
	}

	void showPlayers(Player *pl1, Player *pl2, Player *pl1copy, Player *pl2copy) {
		system("cls");
		cout << endl << endl << endl ;

		cout << "                                   " << setw(16) << "ИГРОК №1" << setw(25) << "ИГРОК №2" << setw(30) << "(бросить '-->')" << endl;
		cout << "                                   " << setw(15) << pl1->name << setw(25) << pl2->name << setw(31) << "(перебросить 1)"<< endl;
		cout << "                                   " << setw(15) << "очки: " << pl1->score - pl1copy->score<< setw(23) << "очки: " << pl2->score - pl2copy->score << setw(30) << "(передать ход 2)" << endl;
	}
	void showName() {
		cout << endl  << "                             " << name << ": ";
	}
	

	~Player() {} //деструктор
};

vector <Player*> Player ::rating;// определение поля в глобальной области (вектор указателей на тип Player)


class Winner :public Player {//наследование класса Player механизмом наследования public
public:

	void congratulate() {//вывод поздравления
		system("cls");
		cout <<  endl<<endl<<endl;
		cout << "                       /\\        /\\                         " << endl;
		cout << "                      /  \\      /  \\                        " << endl;

		cout << "                    / / /        / / /                        " << endl;
		cout << "                                                              " << endl;
		cout << "                         \\______/                            " << endl << endl<<endl;
		cout << "          ПОЗДРАВЛЯЕМ, " << name << ", ВЫ ВЫИГРАЛИ!             " << endl;
		cout << "          ВАШИ ОЧКИ: " << score << endl ;


	}

	~Winner() {}
};


class Dices {
	int dices[5];
public:

	Dices() {// конструктор по умолчанию
		for (int i = 0; i < 5; i++)
			dices[i] = 1;
	}

	int Roll() {// "бросок" костей
		int finalScore;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < 5; i++)
			dices[i] = rand() % 6 + 1; // инициализация костей рандомными значениями от 1 до 6


		finalScore = calcScore();

		return finalScore;

	}

	int reRoll() {// "переброс" костей

		int firstScore, finalScore; //кол-во очков до переброса и после соответственно
		firstScore = calcScore();

		for (int i = 0; i < 5; i++) {
			if (dices[i] != 1 && dices[i] != 5)
				dices[i] = rand() % 6 + 1;
		}

		finalScore = calcScore() - firstScore;

		return finalScore;
	}

	void showDices() {//функция вывода костей
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
	//вспомогательные функции для вывода костей
	void empty() { cout << "|       |   "; }
	void right() { cout << "|    0  |   "; }
	void left() { cout << "|  0    |   "; }
	void center() { cout << "|   0   |   "; }
	void pair() { cout << "|  0 0  |   "; }


	int calcScore() {//подсчет очков
		int k = 0; //кол-во очков
		for (int i = 0; i < 5; i++) {
			if (dices[i] == 1) { k += 10; }
			else if (dices[i] == 5) { k += 5; }
		}
		return k;
	}

	~Dices() {}//деструктор


};


class Menu {
public:
	void showMenu() {// вывод Меню 
		system("cls");
		int n;// выбор игрока
		cout << endl<<endl;
		cout << "                                          ________    ________  ___________              " << endl;
		cout << "                             |*|    /*/  |*|    |*|  |*|            |*|      |*|    /*|*|" << endl;
		cout << "                             |*|  /*/    |*|    |*|  |*|            |*|      |*|   /*/|*|" << endl;
		cout << "                             |*|/*/      |*|    |*|  |*|            |*|      |*|  /*/ |*|" << endl;
		cout << "                             |*|\\*\\      |*|    |*|  |*|            |*|      |*| /*/  |*|" << endl;
		cout << "                             |*|  \\*\\    |*|    |*|  |*|            |*|      |*|/*/   |*|" << endl;
		cout << "                             |*|    \\*\\  |*|____|*|  |*|______      |*|      |*|*/    |*|" << endl;
		cout << "                                                                                         " << endl;
		cout << "                                                 1   НАЧАТЬ ИГРУ    1                    " << endl;
		cout << "                                                 2 ПОКАЗАТЬ РЕЙТИНГ 2                    " << endl;
		cout << "                                                 3   ПРАВИЛА ИГРЫ   3                    " << endl;
		cout << "                                                 4      ВЫЙТИ       4                    " << endl;
		cout << "                                                                                         " << endl;
		cout << "                                                          " ;

		cin >> n;
		switch (n) {
		case 1: startGame();
			if (_getch() == 27)//нажатие на esc
			{
				showMenu();
			}
			break;
		case 2: Player::showRating(); //востановление уровня доступа членам класса Player
			if (_getch() == 27)//нажатие на esc
			{
				showMenu();
			}
			break;
		case 3: showRules(); break;
		case 4: exit(0);
		}
	}


	void startGame() {//начало игры
		system("cls");
		bool  rolled = 0,   noplayers;
		int s, turn = 1, b, wnr, num, opp, choice;
		int a;
		Player *pl1 = new Player;
		Player *pl2 = new Player;
		Player* pl1copy = new Player;
		Player* pl2copy = new Player;
		fl = 1;

		//Авторизация

		cout << endl <<endl<< "                                                 *   АВТОРИЗАЦИЯ   *                    " << endl <<endl;
		cout <<         "                                                       ИГРОК №1                          " << endl;
		cout <<         "                                               1-существующий   2-новый               | ";

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
				cout << endl<<"                             Введите номер игрока: ";
				cin >> num;
				pl1 = pl1->findPlayer(num-1);
				pl1copy->setPlayer(pl1);
			
			}
		}
		cout << endl <<endl<< "                                                       ИГРОК №2                          " << endl;
		cout <<               "                                      1-существующий    2-новый    3-компьютер        | ";
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
				cout << endl << "                             Введите номер игрока: ";
				cin >> num;
				pl2 = pl2->findPlayer(num-1);
				pl2copy->setPlayer(pl2);
				
			}
			
		}
		else {
			pl2->setPlayer("COMPUTER");
		}
		pl1->showPlayers(pl1, pl2, pl1copy, pl2copy);



		//процесс игры

		Dices dices;
		while (fl) {

			switch (turn) {


//ход первого игрока
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
							dices1.showDices();//вывод костей при первом броске
							dices.showDices();//вывод костей при перебросе
							pl1->showName(); cout << setw(5) << "+" << s1 << setw(15) << " |переброшено" << setw(6) << "+" << s << endl;
							rolled = 0;
							turn = 2;
						}
						else if (b == 2) {//передача хода 
							rolled = 0;
							turn = 2;
						
						}

						break;

					case 75:
						if (!rolled)  cout << "!!! Сперва необходимо бросить !!!";
						break;


					case 80:

						rolled = 0;
						turn = 2;
						break;

					default: cout << "!!! Неверное нажатие !!!" ;

						break;
					}
				
				break;

//ход второго игрока
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
						else { pl2->showName(); cout << " (брошено)" << setw(5) << "+" << s << "        | "; }
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
							dices1.showDices();//вывод костей при первом броске
							dices.showDices();//вывод костей при перебросе
							pl2->showName(); cout << setw(5) << "+" << s1 << setw(15) << " |переброшено" << setw(6) << "+" << s << endl;
							rolled = 0;
							turn = 1;
						}
						else if (b == 2) {//передача хода 
							rolled = 0;
							turn = 1;
						
						}
						break;

					case 75:
						if (!rolled)  cout << "!!! Сперва необходимо бросить !!!";
						break;


					case 80:
						rolled = 0;
						turn = 1;
						break;

					default: cout << "!!! Неверное нажатие !!!" ;

						break;

					}
				
				break;

			}
		}
	}

	void showRules() {//вывод правил
		char text[]{ "                        Игрок «бросает» пять костей, значения которых выпадают случайным образом.\n                Кости, значения которых отличны от 1 и 5 можно «перекинуть» (перекидывать можно только 1 раз).\n                        Подсчет очков : «1» – 10 очков, «5» – 5 очков. Игроки играют по очереди.\n                 Цель набрать ровно 300 или 500 очков. Побеждает игрок, первый набравший такую сумму очков." };
		system("cls");
		cout << endl <<endl<< "                                                  *   ПРАВИЛА ИГРЫ   *                    " << endl << endl;

		cout << text << endl << endl;
		cout << setw(40) << "БРОСИТЬ" << setw(6) << "-->" << endl;//(стрелка вправо)
		cout << setw(40) << "ПЕРЕБРОСИТЬ" << setw(5) << "1" << endl;
		cout << setw(40) << "ПЕРЕДАТЬ ХОД" << setw(5) << "2" << endl ; 
		cout << setw(40) << "НАЗАД" << setw(6) << "ESC" << endl << endl;

		cout << "                                                 ESC     НАЗАД      ESC                    " << endl;
		if (_getch() == 27)//нажатие на esc
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