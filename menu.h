#pragma once

struct UI {
	void header(); // placeholder text header
	int callMenu();
	void getUserChoice(int menuChoice);
	void printCmHeader();
	void printSensHeader();
	void printFAQHeader();
	void menuOrQuit(); // prompts the user to return to the menu or gives the option to quit the application
};

struct FAQ {
	void printFAQ();
};