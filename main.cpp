#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <windows.h> // WinApi header

#include "menu.h"
#include "calculate.h"

int main() {
	
	UI user;
	user.header();
	int choice = user.callMenu();
	user.getUserChoice(choice);

	PlayerInfo pi;
	ConvertToCm360 cm;
	UserPrompt up;

	return 0;
}