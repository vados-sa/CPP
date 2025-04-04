#include "HumanB.hpp"

void HumanB::attack()
{
	if (HumanB::weapon) // Human B will not always have a weapon.
		std::cout << HumanB::name << " attacks with their " << HumanB::weapon << std::endl;
	else
		std::cout << "HumanB has no weapon." << std::endl;
}