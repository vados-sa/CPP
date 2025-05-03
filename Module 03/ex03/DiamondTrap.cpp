#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Deafult constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	std::cout << "DiamondTrap Constructor called for " << name << "." << std::endl;
	hit_points = FragTrap::hit_points; // 100 (from FragTrap) 
	energy_points = ScavTrap::energy_points; // 50 (from ScavTrap)
	attack_damage = FragTrap::attack_damage; // 30 (from FragTrap)
}

DiamondTrap::DiamondTrap (const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy Constructor called for " << other.name << "." << std::endl;
	this->name = other.name;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy Assignment Operator called for " << other.name << "." << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
	}

	return *this;
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
