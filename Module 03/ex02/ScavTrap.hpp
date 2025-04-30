#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap // maybe it should be private
{
//private:
public:
	ScavTrap(std::string name); // constructor
	ScavTrap(const ScavTrap& other); // copy constructor
	ScavTrap& operator = (const ScavTrap& other); // copy assignment operator overload
	~ScavTrap(); // destructor

	void attack(const std::string& target); // override attack()
	void guardGate();
};

#endif
