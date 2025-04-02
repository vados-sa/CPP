#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_H
#define HUMANA_H

// HumanA will always be armed
class HumanA {

	private:
		std::string name;
		std::string weapon;

	public:
		HumanA(std::string name, Weapon type);
		void attack(); // displays: <name> attacks with their <weapon type>
};

#endif