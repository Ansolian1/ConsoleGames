#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void toFight(int *hp, int *damage, int *mobHp, int *mobDamage, int *gold, int currentLevel) {
	cout << "Выберите действие \n 1) Атаковать \n 2) Сбежать (" << 100 * currentLevel << " золота )" << endl;
	string choice = "";
	cin >> choice;
	if (choice == "1") {
		cout << "Вы бьете" << endl;
		*mobHp = *mobHp - *damage;
		if (*mobHp > 0) {
			*hp = *hp - *mobDamage;
		}
	}
	else if (choice == "2") {
		if (*gold >= (currentLevel * 100)) {
			cout << "Вы сбежали" << endl;
			*gold -= 100 * currentLevel;
			*mobHp = 0;
		}
		else {
			cout << "Нехватает золота для откупа" << endl;
		}
	}
	else {
		cout << "Введены некорректные данные" << endl;
		toFight(hp, damage, mobHp, mobDamage, gold, currentLevel);
	}
}

void winBounty(int *maxHp, int *damage, int *gold, int currentLevel) {
	srand(time(NULL));
	int bountyChance = rand() % 100;
	if (bountyChance < 10) {
		*damage += 10 * currentLevel;
	}
	else if (bountyChance < 40) {
		*maxHp += 10 * currentLevel;
	}
	else {
		*gold += 100 * currentLevel;
	}
}