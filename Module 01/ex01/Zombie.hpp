#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
	private:
		std::string name;
	
	public:
		Zombie();
		~Zombie();
		void setName(std::string new_name);
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
std::string trim(const std::string& str);
unsigned int get_zombies_amount();

#endif