#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

//HumanB may not always have a weapon
class HumanB {

	private:
		std::string name;
		Weapon* weapon; // Pointer to Weapon

	public:
		HumanB(std::string name);
		void attack(); // displays: <name> attacks with their <weapon type>
		void setWeapon(Weapon& weapon);
};

#endif