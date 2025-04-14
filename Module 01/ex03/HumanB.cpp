#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon; 
}


void HumanB::attack()
{
	if (!weapon)
		std::cout << name << " has no weapon." << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}