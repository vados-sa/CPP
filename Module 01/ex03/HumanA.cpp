#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) // constructor initializer list
	: name(name), weapon(weapon) {}