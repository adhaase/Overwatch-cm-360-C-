#include <iostream>
#include <string>
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
	std::cout << "Please choose a menu option (the corresponding integer, no punctuation): ";
	std::cin >> menuChoice;
	std::cout << "\n";
	return menuChoice;
}

void UI::printCmHeader() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 27);
	std::cout << "------------------------------------------\n";
	std::cout << "|      Cm/360 converter application      |\n";
	std::cout << "------------------------------------------\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void UI::printSensHeader() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 27);
	std::cout << "-----------------------------------------------------------\n";
	std::cout << "|      Sensitivity equalizer application application      |\n";
	std::cout << "-----------------------------------------------------------\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void UI::printFAQHeader() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 27);
	std::cout << "------------------------------------\n";
	std::cout << "|               F A Q              |\n";
	std::cout << "------------------------------------\n\n";
	SetConsoleTextAttribute(hConsole, 15);
}

void UI::menuOrQuit() {
	char choice;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Do you want to return to the menu, or quit the application?\n";
	std::cout << "Menu = m  |  Quit = q\n";
	std::cout << "Enter choice: ";
	SetConsoleTextAttribute(hConsole, 15);

	std::cin >> choice;
	if (choice == 'm') {
		int choiceNum = callMenu();
		getUserChoice(choiceNum);
	}
	else exit(0);
}

void UI::getUserChoice(int menuChoice) {
	UI user;
	PlayerInfo pi;
	ConvertToCm360 cm;
	SensitivityEqualizer se;
	UserPrompt up;
	FAQ faq;
	switch (menuChoice) {
	case 1:
		// cm/360 converter
		user.printCmHeader();
		cm.output(user, up, pi, cm);
		break;
	case 2:
		// sens equalizer
		user.printSensHeader();
		se.output(user, up, pi, cm);
		break;
	case 3:
		// FAQ
		user.printFAQHeader();
		faq.printFAQ();
		user.menuOrQuit();
		break;
	case 4:
		exit(0);
		break;
	default:
		std::cout << "ERROR: option not recognized\n";
		user.menuOrQuit();
	}
}

void FAQ::printFAQ() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "USES FOR THE APPLICATION\n";
	std::cout << "------------------------\n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "Like many FPS games, Overwatch uses its own native sensitivity settings along with a users mouse DPI to allow a character to produce movement. Sensitivity varies heavily based on the game, so it is necessary to standardize an input method to achieve some form of normality. This can be accomplished by understanding how many centimeters of mouse movement it takes to move your character in one 360 degree rotation.\n\n";
	
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "UNDERSTANDING YOUR CM/360 RESULT\n";
	std::cout << "--------------------------------\n";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "A valid way to interpret your own cm/360 result from this program is to compare it to the settings from professional Overwatch players. As the cm/360 is universal, the output can be understood despite varying hardware / software setups, and is a valid way to interpret sensitivity settings with other players.Personally, I play on 1000 DPI with 6.5 in - game sens, which equates to 21.31 cm/360. This means that I have to move my mouse 21.31 cm for my in - game character to achieve one full 360 degree rotation. These settings are very similar to Saebyolbe's (professional player for team New York Excelsior), even though he plays at 810 DPI and 7.93 in-game sens! For reference, this is a very high sensitivity, most players are around the mid 30s range.\n\n";
}