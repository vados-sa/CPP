#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	std::cout << "Diamond Trap Constructor called for " << name << "." << std::endl;
	hit_points = FragTrap::hit_points; // 100 (from FragTrap) 
	energy_points = ScavTrap::energy_points; // 50 (from ScavTrap)
	attack_damage = FragTrap::attack_damage; // 30 (from FragTrap)
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond Trap Destructor called on " << name << "." << std::endl; 
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiomondTrap's name: " << name << "." << std::endl;
	std::cout << "ClapTrap's name: " << ClapTrap::name << "." << std::endl;
}