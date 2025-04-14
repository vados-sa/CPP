#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string name; // data - name attribute
	
	public:
		Zombie(std::string new_name); // constructor declaration
		~Zombie(); // destructor
		void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
std::string trim(const std::string& str);

#endif
