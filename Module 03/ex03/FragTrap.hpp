#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name); // constructor
	FragTrap(const FragTrap& other); // copy constructor
	FragTrap& operator = (const FragTrap& other); // copy assignment operator overload
	~FragTrap(); // destructor

	void  highFivesGuys();
};

#endif