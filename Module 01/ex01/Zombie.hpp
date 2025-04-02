#include <stdio.h>
#include <iostream>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {
	private: // can oly be accessed or modified by methods of the Zombie class.
		std::string name; // data - name attribute
	
	public:
		Zombie();
		~Zombie(); // destructor
		void setName(std::string new_name);
		void announce(void); // behavior - announce method
};

#endif

Zombie* zombieHorde( int N, std::string name );