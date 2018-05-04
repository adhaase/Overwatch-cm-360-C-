#include <iostream>
#include <cstdlib>
#include <windows.h> // WinApi header

#include "menu.h"
#include "calculate.h"

void UI::header() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// pick the color attribute k you want
	SetConsoleTextAttribute(hConsole, 11);
	
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "|               OVERWATCH cm/360 converter | ver 1.0               |\n";
	std::cout << "|                                                                  |\n";
	std::cout << "|         * Will be reformatted with the Qt framework later        |\n";
	std::cout << "|                         by Alex Haase                            |\n";
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "\n";
}

int UI::callMenu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 23);
	std::cout << "------------------------------------------\n";
	std::cout << "| 1. Cm/360 converter application        |\n";
	std::cout << "| 2. Sensitivity equalizer application   |\n";
	std::cout << "| 3. FAQ                                 |\n";
	std::cout << "| 4. Exit                                |\n";
	std::cout << "------------------------------------------\n\n";
	SetConsoleTextAttribute(hConsole, 15);
	int menuChoice;
	std::cout << "Please choose a menu option (the corresponding intger, no punctuation): ";
	std::cin >> menuChoice;
	std::cout << "\n";
	return menuChoice;
}

void UI::getUserChoice(int menuChoice) {
	UI user;
	PlayerInfo pi;
	ConvertToCm360 cm;
	SensitivityEqualizer se;
	UserPrompt up;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (menuChoice) {
	case 1:
		// cm/360 converter
		SetConsoleTextAttribute(hConsole, 27);
		std::cout << "------------------------------------------\n";
		std::cout << "|      Cm/360 converter application      |\n";
		std::cout << "------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		cm.output(user, up, pi, cm);
		break;
	case 2:
		// sens equalizer
		SetConsoleTextAttribute(hConsole, 27);
		std::cout << "-----------------------------------------------------------\n";
		std::cout << "|      Sensitivity equalizer application application      |\n";
		std::cout << "-----------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		se.output(user, up, pi, cm);
		break;
	case 3:
		// FAQ
		break;
	case 4:
		exit(0);
		break;
	default: 
		std::cout << "ERROR: option not recognized\n";

		char choice;
		std::cout << "Do you want to return to the menu, or quit the application?\n";
		std::cout << "Menu = m  |  Quit = q\n";
		std::cout << "Enter choice: ";

		std::cin >> choice;
		if (choice == 'm') {
			int choiceNum = callMenu();
			getUserChoice(choiceNum);
		}
		else exit(0);
	}
}