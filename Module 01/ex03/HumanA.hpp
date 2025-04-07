#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

// HumanA will always be armed
class HumanA {

	private:
		std::string name;
		Weapon& weapon; // reference to Weapon

	public:
		HumanA(std::string name, Weapon& type);
		void attack();
};

#endif