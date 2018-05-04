#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <windows.h> // WinApi header

#include "menu.h"
#include "calculate.h"

int PlayerInfo::getPlayerDPI() {
	std::cout << "Please enter your mouse DPI: ";
	int dpi = 0;
	std::cin >> dpi;
	return dpi;
}

double PlayerInfo::getPlayerSens() {
	std::cout << "Please enter your in-game sensitivity: ";
	double sens = 0;
	std::cin >> sens;
	return sens;
}

double ConvertToCm360::convert(int dpi, double sens) {
	double maximumValPer360 = 138545.455;
	double cm360Result = maximumValPer360 / sens / dpi;
	return cm360Result;
}

void UserPrompt::userChoices(UI& ui, UserPrompt& up, PlayerInfo& pi) {
	ConvertToCm360 cm;
	std::cout << "Try different values? (y/n) -OR- Return to the menu (m)";
	char choice;
	std::cin >> choice;
	switch (choice) {
	case 'y': // re-calculate
		cm.output(ui, up, pi, cm);
		break;
	case 'n': // close the application
		exit(0);
		break;
	case 'm': // return to menu
		ui.callMenu();
		break;
	}
}

void ConvertToCm360::output(UI& ui, UserPrompt& up, PlayerInfo& pi, ConvertToCm360& cm) {
	int dpi = pi.getPlayerDPI();
	double sens = pi.getPlayerSens();

	double conversionResult = convert(dpi, sens);
	
	std::cout << dpi << " DPI and " << sens << " sensitivity equates to: ";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << conversionResult << " cm/360 degrees\n\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	up.userChoices(ui, up, pi);
}