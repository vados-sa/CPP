#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
{
	this->name = name;
	std::cout << "Diamond Trap Constructor called for " << name << "." << std::endl; 
	
	// ClapTrap instamce of Diamond Trap will be created only once
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond Trap Destructor called on " << name << "." << std::endl; 
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiomondTrap name: " << name << "." << std::endl;
	std::cout << "ClapTrap name: " << std::endl; // find out how to do this
}