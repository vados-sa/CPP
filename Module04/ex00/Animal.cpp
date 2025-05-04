#include "Animal.hpp"

Animal::Animal()
	: type(NULL)
{
	std::cout << "Animal Default constructor called." << std::endl;
}

Animal::Animal(const Animal& other)
	: type(other.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	delete this;
	std::cout << "Animal Destructor called." << std::endl;
}

void Animal::makeSound()
{
	// I think the concept to learn will be here
}