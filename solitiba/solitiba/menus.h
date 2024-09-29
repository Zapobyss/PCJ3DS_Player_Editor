#pragma once

#ifndef MENUS_H
#define MENUS_H

class Menus {

	public:

		Menus(void);
		~Menus(void);

		void Dialogue_Welcome(void);
		void Dialogue_Missing(void);
		unsigned int Dialogue_Edit(void);

};

extern Menus* Menu;

#endif