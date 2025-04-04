#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_H
#define HUMANB_H

//HumanB may not always have a weapon
class HumanB {

	private:
		std::string name;
		std::string weapon;

	public:
		HumanB(std::string name);
		void attack(); // displays: <name> attacks with their <weapon type>
};

#endif