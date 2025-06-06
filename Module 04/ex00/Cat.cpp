#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	type = "Cat";
	std::cout << "Cat Default constructor called." << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	type = other.type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // Call base class assignment operator
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Mee-owww!" << std::endl;
}