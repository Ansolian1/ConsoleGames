#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

char takeComputerSide(char playerSide) {
	if (playerSide == 'X')
		return 'O';
	else
		return 'X';
}
bool isFieldFilled(vector<char> field) {
	bool isFull = true;
	for (size_t i = 0; i < field.size(); i++)
	{
		if (field[i] == ' ') {
			isFull = false;
			break;
		}
	}
	return isFull;
}
char takeWinner(vector<char> field) {
	if (field[0] == field[1] && field[1] == field[2])
		return field[0];
	if (field[3] == field[4] && field[4] == field[5])
		return field[3];
	if (field[6] == field[7] && field[7] == field[8])
		return field[6];
	if (field[0] == field[3] && field[3] == field[6])
		return field[0];
	if (field[1] == field[4] && field[4] == field[7])
		return field[1];
	if (field[2] == field[5] && field[5] == field[8])
		return field[2];
	if (field[0] == field[4] && field[4] == field[8])
		return field[0];
	if (field[2] == field[4] && field[4] == field[6])
		return field[2];
	return ' ';
}

char chooseSide() {
	char side = ' ';
	while (true) {		
		cout << "Выберите сторону, за которую будете играть (X ходит первым, 0 - вторым)" << endl;
		cout << "1)Х" << endl;
		cout << "2)0" << endl;
		std::string numSide = "";
		cin >> numSide;
		if (numSide == "1")
			return 'X';
		if (numSide == "2")
			return 'O';
	}
}

int takeComputerPosition(vector<char> field, char computerSide) {
	for (size_t i = 0; i < field.size(); i++)
	{
		vector<char> buffField = field;
		buffField[i] = computerSide;
		if (takeWinner(buffField) == computerSide && field[i]==' ')
			return i;
	}
	char playerSide = takeComputerSide(computerSide);
	for (size_t i = 0; i < field.size(); i++)
	{
		vector<char> buffField = field;
		buffField[i] = playerSide;
		if (takeWinner(buffField) == playerSide && field[i] == ' ')
			return i;
	}
	if (field[4] == ' ')
		return 4;
	for (size_t i = 0; i < field.size(); i++)
	{
		if (field[i] % 2 != 0 && field[i] == ' ')
			return i;
	}
	for (size_t i = 0; i < field.size(); i++)
	{
		if (field[i] % 2 == 0 && field[i] == ' ')
			return i;
	}

}

int selectPosition(vector<char> field) {
	int position = 0;
	while (true) {
		cout << "Выберите позицию для ходьбы" << endl;
		cout << "1 2 3" << endl;
		cout << "4 5 6" << endl;
		cout << "7 8 9" << endl;
		std::string numPos = "";
		cin >> numPos;
		if (numPos == "1")
			position = 0;
		else if (numPos == "2")
			position = 1;
		else if (numPos == "3")
			position = 2;
		else if (numPos == "4")
			position = 3;
		else if (numPos == "5")
			position = 4;
		else if (numPos == "6")
			position = 5;
		else if (numPos == "7")
			position = 6;
		else if (numPos == "8")
			position = 7;
		else if (numPos == "9")
			position = 8;
		else
			cout << "Неверный ввод" << endl;
		if (field[position] != ' ')
			cout << "Позиция занята" << endl;
		else
			return position;
	}
}

