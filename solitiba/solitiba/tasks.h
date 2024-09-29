#pragma once

#ifndef TASKS_H
#define TASKS_H

#include "including.h"

class Tasks {

	private:

		std::string NameOverwrite;
		void SetNameOverwrite(std::string Name);
		std::string GetNameOverwrite();

		char CurrentGender;
		void SetCurrentGender(char Gender);
		char GetCurrentGender();

	public:

		Tasks(void);
		~Tasks(void);

		void SeekName(void);
		void InputNewName(void);
		void WriteNewName(void);

		void SeekGender(void);
		void WriteNewGender(void);

};

extern Tasks* Task;

#endif