#include <iostream>

#ifndef WEAPON_H
#define WAEPON_H

#include <string>

class Weapon {

	private:
		std::string type; 

	public:
		Weapon(std::string weapon_type);
		const std::string& getType(); // returns a constant reference to type.
		void setType(std::string new_value); // sets type using the new value passed as a parameter

};

#endif

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
		HumanA(std::string name, Weapon type);
		void attack();
};

#endif

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
		void setWeapon(Weapon type);
};

#endif

Weapon::Weapon(std::string weapon_type)
{
	type = weapon_type;
}
const std::string& Weapon::getType()
{
	std::string& const type_ref = type;
	return type_ref;
}

void Weapon::setType(std::string new_value)
{
	type = new_value;
}

void HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon << std::endl;
}

HumanA::HumanA(std::string name, Weapon type)
{
	name = name;
	weapon = type.getType();
}

void HumanB::setWeapon(Weapon type)
{
	std::string *wb_type = type.getType();
	weapon = type.setType(wb_type); 
}


void HumanB::attack()
{
	if (weapon.empty())
		std::cout << "HumanB has no weapon." << std::endl;
	else
		std::cout << name << " attacks with their " << weapon << std::endl;
}

HumanB::HumanB(std::string name)
{
	name = name;
	weapon = nullptr;
}

/*In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.*/
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); // set wapon using reference? it's always there.
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club); // change using pointer - doesn't exits at first.
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
