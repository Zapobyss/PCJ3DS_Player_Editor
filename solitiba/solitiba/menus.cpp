#include "including.h"

#define BUILD_DATE __DATE__ " " __TIME__

Menus::Menus(void) {
}

Menus::~Menus(void) {
}

Menus* Menu;

void Menus::Dialogue_Welcome(void) {
	std::cout << "Pocket Card Jockey Player Editor\n/!\\ This software does not have an implicit warranty!\nBuild date: " << BUILD_DATE << "\n\n";
}

void Menus::Dialogue_Missing(void) {
	std::cout << "Save file not found.\n\n";
}

unsigned int Menus::Dialogue_Edit(void) {
	std::cout << "\n\nWhat do you wish to change?\n\n� 1 = Player name\n� 2 = Gender\n� 3 = Both\n� Any key = Nothing\n\nChoose one: ";

	unsigned int choice;
	std::cin >> choice;
	system("cls");
	return choice;
}
