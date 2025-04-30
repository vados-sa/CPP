#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap // maybe it should be private
{
private:
	std::string name;
public:
	DiamondTrap(std::string name); // constructor
	DiamondTrap(const DiamondTrap& other); // copy constructor
	DiamondTrap& operator = (const DiamondTrap& other); // copy assignment operator overload
	~DiamondTrap(); // destructor

	void whoAmI();
};

#endif