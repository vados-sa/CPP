#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>


class Zombie {
	private: // can oly be accessed or modified by methods of the Zombie class.
	std::string name; // data - name attribute
	
	public:
	Zombie(std::string new_name); // constructor declaration
	~Zombie(); // destructor
	void announce(void); // behavior - announce method
	//void destroy_zombie( std::string name );
};

#endif

Zombie::Zombie(std::string new_name) // constructor definition
{
	name = new_name;
}

Zombie::~Zombie() // destructors don't take arguments!
{
	std::cout << name << " destroyed." << std::endl;
}

//Zombies announce themselves as follows: <name>: BraiiiiiiinnnzzzZ...
//Do not print the angle brackets (< and >)

/*Zombies must be destroyed when you no longer need them. The destructor must print
a message with the name of the zombie for debugging purposes.*/

void Zombie::announce(void)
{
	std::cout << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

/* This function creates a zombie, names it, 
and returns it so you can use it outside of the 
function scope. */
Zombie* newZombie( std::string name ) // global function
{
	Zombie *new_zombie = new Zombie(name);
	return new_zombie;
}

/* This function creates a zombie, names it, 
and makes it announce itself. */
void randomChump( std::string name ) // global function
{
	Zombie zombie(name);
	zombie.announce(); // how do I make it anounce it's name?
}

int	main()
{
	std::string name;
	
	// randomChump
	std::cout << "Enter a name for your Zombie:\n";
	std::cin >> name;
	randomChump(name);
	
	// newZombie
	std::cout << "Enter a name for your Zombie:\n";
	std::cin >> name;
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;

	return 0;
}