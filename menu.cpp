#include <iostream>
#include <cstdlib>
#include <windows.h> // WinApi header

#include "menu.h"

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
	std::cout << "| 1. Display Menu                        |\n";
	std::cout << "| 2. Cm/360 converter application        |\n";
	std::cout << "| 3. Sensitivity equalizer application   |\n";
	std::cout << "| 4. FAQ                                 |\n";
	std::cout << "| 5. Exit                                |\n";
	std::cout << "------------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 15);
	int menuChoice;
	std::cout << "Please choose a menu option (the corresponding intger, no punctuation): ";
	std::cin >> menuChoice;
	return menuChoice;
}

void UI::getUserChoice(int menuChoice) {
	switch (menuChoice) {
	case 1: 
		//menu
		callMenu();
		break;
	case 2:
		// cm/360 converter
		break;
	case 3:
		// sens equalizer
		std::cout << "coming soon!\n";
		break;
	case 4:
		// FAQ
		break;
	case 5:
		exit(0);
		break;
	default: 
		std::cout << "ERROR: option not recognized\n";

		char choice;
		std::cout << "Do you want to return to the menu, or quit the application?\n";
		std::cout << "Menu = m  |  Quit = q\n";
		std::cout << "Enter choice: ";

		std::cin >> choice;
		if (choice == 'm') callMenu();
		else exit(0);
	}
}