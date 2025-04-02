#include "Zombie.hpp"

/* This global function creates a zombie, names it, and returns 
it so you can use it outside of the function scope. */
Zombie* newZombie( std::string name )
{
	Zombie *new_zombie = new Zombie(name);
	return new_zombie;
}