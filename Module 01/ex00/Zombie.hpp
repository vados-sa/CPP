#include <iostream>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {
	private: // can oly be accessed or modified by methods of the Zombie class.
		std::string name; // data - name attribute
	
	public:
		Zombie(std::string new_name); // constructor declaration
		~Zombie(); // destructor
		void announce(void); // behavior - announce method
};

#endif



void randomChump( std::string name );
Zombie* newZombie( std::string name );