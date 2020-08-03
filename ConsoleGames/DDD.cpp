#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void toFight(int *hp, int *damage, int *mobHp, int *mobDamage, int *gold, int currentLevel) {
	cout << "�������� �������� \n 1) ��������� \n 2) ������� (" << 100 * currentLevel << " ������ )" << endl;
	string choice = "";
	cin >> choice;
	if (choice == "1") {
		cout << "�� �����" << endl;
		*mobHp = *mobHp - *damage;
		if (*mobHp > 0) {
			*hp = *hp - *mobDamage;
		}
	}
	else if (choice == "2") {
		if (*gold >= (currentLevel * 100)) {
			cout << "�� �������" << endl;
			*gold -= 100 * currentLevel;
			*mobHp = 0;
		}
		else {
			cout << "��������� ������ ��� ������" << endl;
		}
	}
	else {
		cout << "������� ������������ ������" << endl;
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