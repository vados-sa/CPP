#include <iostream>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {
	private:
		std::string name; // data - name attribute
	
	public:
		Zombie(std::string new_name); // constructor declaration
		~Zombie(); // destructor
		void announce(void);
};

#endif

void randomChump( std::string name );
Zombie* newZombie( std::string name );