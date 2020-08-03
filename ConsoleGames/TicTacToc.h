#pragma once
#include <vector>

using std::vector;
char chooseSide();
int selectPosition(vector<char> field);
char takeWinner(vector<char> field);
char takeComputerSide(char playerSide);
int takeComputerPosition(vector<char> field, char computerSide);
bool isFieldFilled(vector<char> field);