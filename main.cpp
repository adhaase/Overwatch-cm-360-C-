#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdlib>

#include "menu.h"

int main() {
	
	header();
	int choice = callMenu();
	getUserChoice(choice);

	system("pause");
	return 0;
}