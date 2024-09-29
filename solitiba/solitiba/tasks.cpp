#include "including.h"

Tasks::Tasks(void) {
	SetNameOverwrite("");
	SetCurrentGender(0);
}

Tasks::~Tasks(void) {
}

Tasks* Task;

// __________________________________________________
// Mutators and acessors for the entered name
// ——————————————————————————————————————————————————

void Tasks::SetNameOverwrite(std::string Name) {
	NameOverwrite = Name;
}



std::string Tasks::GetNameOverwrite() {
	return NameOverwrite;
}

// __________________________________________________
// Player name methods
// ——————————————————————————————————————————————————

// Get the player's name from the save file
void Tasks::SeekName(void) {

	char NameBuffer[20];

	savefile.seekg(o_Name_Start, ios::beg);

	savefile.read(NameBuffer, 19);
	NameBuffer[19] = '\0'; // null terminator

	cout << "Player name: ";

	for (unsigned int a = 0; a < 19; a++) {
		cout << dec << NameBuffer[a];
	}

}


// Input a new name
void Tasks::InputNewName(void) {

	string NameInput;

	cout << "Enter a new name for the player: ";
	getline(cin, NameInput);
	cin >> NameInput;

	if (NameInput.length() > 10) {
		cout << "The name you've entered contains more than 10 characters.\nOnly the first 10 will be used.\n\n";
	}

	SetNameOverwrite(NameInput.substr(0, 10));

}


// Write the new name to the save file
void Tasks::WriteNewName(void) {

	int CurOffset = o_Name_Start;
	unsigned int Length = GetNameOverwrite().length();

	if (Length == 0) {
		cout << "You did not input anything at all.\nNo changes were made.\n\n";
	} else {
		// Open in binary mode
		ofstream savefile("gamedata", ios::binary | ios::in | ios::out);

		// Seek to the player's name offset and write the data
		for (unsigned int CurChar = 0; CurChar < 10; CurChar++) {
			savefile.seekp(CurOffset, ios::beg);

			// NULL is appended to the rest of the characters
			if (CurChar > Length) {
				savefile.put(0x0);
			}
			else {
				savefile.put(GetNameOverwrite()[CurChar]);
			}
			CurOffset += 0x2;
		}

		savefile.flush();
		savefile.close();

		cout << "The name has been successfully changed!\n";
	}

}

// __________________________________________________
// Mutators and acessors for the current gender
// ——————————————————————————————————————————————————

void Tasks::SetCurrentGender(char Gender) {
	CurrentGender = Gender;
}

char Tasks::GetCurrentGender() {
	return CurrentGender;
}

// __________________________________________________
// Player gender methods
// ——————————————————————————————————————————————————

// Get the player's gender from the save file
void Tasks::SeekGender(void) {

	char GenderBuffer;

	savefile.seekg(o_Gender, ios::beg);
	savefile.get(GenderBuffer);
	SetCurrentGender(GenderBuffer);

	cout << "\nPlayer's gender: ";

	switch (GetCurrentGender()) {
	case 0:
		cout << "Male";
		// Set new gender to Female
		SetCurrentGender(1);
		break;

	case 1:
		cout << "Female";
		// Set new gender to Male
		SetCurrentGender(0);
		break;

	default:
		cout << "The player's gender is either unreadable or corrupted.";
		break;
	}

}


// Write the new gender to the save file depending on the current one
void Tasks::WriteNewGender(void) {

	ofstream savefile("gamedata", ios::binary | ios::in | ios::out);
	savefile.seekp(o_Gender, ios::beg);

	savefile.put(GetCurrentGender());

	savefile.flush();
	savefile.close();

	cout << "The gender has been successfully changed!\n";

}