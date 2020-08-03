// ConsoleGames.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <String>
#include <ctime>

#include "TicTacToc.h"
#include "DDD.h"

using std::vector;
using std::cout; 
using std::cin; 
using std::endl;
using std::string;

void showGamesList();
void selectGame();
void showSquareField(vector<char> field);
void playTTT();
void playDDD();


vector<char> tttField(9, ' ');
//vector<char> seaFightField(100, '*');
bool isEndGame = false;

//TTT vareables
char playerSide = ' ';
char computerSide = ' ';

//DDD vareables
string monsterCharacteristic[] = { "Огненный ", "Безумный ", "Зеленый ", "Толстый ", "Злой ", "Скользкий ", "Ледяной ", "Синий " };
string monsterNames[] = {"бармагон", "василиск", "домовой", "леший", "барабашка", "телевизор", "змей", "элементаль"};
bool isFightOver = false;
int currentLevel = 0;
int name = 0;
int character = 0;
int currentHp = 100;
int maxHp = 100;
int gold = 0;
int damage = 10;
int mobHp = 0;
int mobDamage = 0;

int *pcurrentHp = &currentHp;
int *pmaxHp = &maxHp;
int *pgold = &gold;
int *pdamage = &damage;
int *pmobHp = &mobHp;
int *pmobDamage = &mobDamage;


int main()
{
	setlocale(LC_ALL, "Russian");
	showGamesList();
}

void showGamesList() {
	cout << "Выберите игру из списка:" << endl;
	cout << "1) Крестики - нолики" << endl;
	cout << "2) D&D&D" << endl;
	selectGame();
}

void selectGame() {
	string choice = "";
	cin >> choice;
	if (choice == "1") {
		cout << "Вы выбрали крестики нолики" << endl;
		playTTT();
	}
	else if (choice == "2") {
		cout << "Выбрали D&D&D" << endl;
		playDDD();
	}
	else {
		cout << "Введены некорректные данные" << endl;
		showGamesList();
	}
}

void playTTT() {
	playerSide = chooseSide();
	computerSide = takeComputerSide(playerSide);
	while (!isEndGame)
	{
		int numPos = 0;
		int computerNumPos = 0;
		if (playerSide == 'X') {
			numPos = selectPosition(tttField);
			tttField[numPos] = playerSide;
			if (isFieldFilled(tttField))
				isEndGame = true;
			if (!isEndGame) {
				computerNumPos = takeComputerPosition(tttField, computerSide);
				tttField[computerNumPos] = computerSide;
			}
			showSquareField(tttField);
		}
		else {
			computerNumPos = takeComputerPosition(tttField, computerSide);
			tttField[computerNumPos] = computerSide;
			showSquareField(tttField);
			if (isFieldFilled(tttField))
				isEndGame = true;
			if (!isEndGame) {
				numPos = selectPosition(tttField);
				tttField[numPos] = playerSide;
			}			
			showSquareField(tttField);
		}
		if (takeWinner(tttField) == playerSide || takeWinner(tttField) == computerSide)
			isEndGame = true;
		if(isFieldFilled(tttField))
			isEndGame = true;

	}
	if(takeWinner(tttField) == playerSide)
		cout << "Вы победили" << endl;
	if (takeWinner(tttField) == computerSide)
		cout << "Вы проиграли" << endl;
	if (takeWinner(tttField) == ' ')
		cout << "Ничья" << endl;
}

void playDDD() {
	while (!isEndGame)
	{
		srand(time(NULL));
		name = rand() % 8;
		character = rand() % 8;
		currentLevel++;
		cout << "Ваше здоровье - " << currentHp << ", урон - " << damage << ", золото - " << gold << endl;
		cout << "На вашем пути " << monsterCharacteristic[character] << monsterNames[name] << endl;
		//следующие 2 строки балансить
		mobHp = (rand() % 10 + 1) * currentLevel;
		mobDamage = (rand() % 10 + 1) * currentLevel;
		cout << "У него " << mobHp << " очков здоровья" << endl;
		while (!isFightOver) {
			toFight(pcurrentHp, pdamage, pmobHp, pmobDamage, pgold, currentLevel);
			if (mobHp > 0) {
				cout << "Ваше здоровье - " << currentHp << ", урон - " << damage << ", золото - " << gold << endl;
				cout << "На вашем пути " << monsterCharacteristic[character] << monsterNames[name] << endl;
				cout << "У него " << mobHp << " очков здоровья" << endl;
			}			
			if (currentHp <= 0) {
				isFightOver = true;
				isEndGame = true;
				cout << "Вы проиграли, ваше золото - " << gold << endl;
			}
			else if(mobHp <= 0) {
				isFightOver = true;
				currentHp = maxHp;
				winBounty(pmaxHp, pdamage, pgold, currentLevel);
				currentHp = maxHp;
			}
		}
		isFightOver = false;
	}
}

void showSquareField(vector<char> field) {
	int length = sqrt(field.size());
	for (size_t i = 0; i < length*2+1; i++)
	{
		cout << " -";
	}
	cout << endl;
	for (size_t i = 0; i < field.size(); i++)
	{
		cout << " | " << field[i] ;
		if ((i + 1) % (length) == 0) {
			cout << " |" << endl;
			if(i!=field.size()-1)
				cout << endl;
		}			
	}
	for (size_t i = 0; i < length*2+1; i++)
	{
		cout << " -";
	}
	cout << endl;
}