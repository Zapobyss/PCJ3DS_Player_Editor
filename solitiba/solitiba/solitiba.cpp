// solitiba.cpp : Defines the entry point for the console application.
//

#include "including.h"

int _tmain(int argc, _TCHAR* argv[]) {

	Menus* Menu = new Menus();
	Tasks* Task = new Tasks();

	Menu->Dialogue_Welcome();

	// Change encoding from 850 to Windows-1252 in order
	// to display special characters, such as '•'
	system("chcp 1252 > nul");

	cout << "Opening gamedata...\n";
	savefile.open("gamedata");

	// Save opens correctly
	if (savefile.fail() != true) {

		//system("cls");

		Task->SeekName();
		Task->SeekGender();

		savefile.close();

		// Data edit prompt
		switch (Menu->Dialogue_Edit()) {
		case 1:
			Task->InputNewName();
			Task->WriteNewName();
			break;

		case 2:
			Task->WriteNewGender();
			break;

		case 3:
			Task->InputNewName();
			Task->WriteNewName();
			Task->WriteNewGender();
			break;
		
		default:
			cout << "Closing the save editor.\n";
			break;
		}

	}
	else {

		cout << "";

		Menu->Dialogue_Missing();
		savefile.close();
	}

	system("pause");

	delete Menu;
	Menu = nullptr;

	delete Task;
	Task = nullptr;

	return 0;

}