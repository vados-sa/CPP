#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called." << std::endl;
	
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other)
	: AAnimal(other)
{
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other); // Copy base class attributes
        delete brain;             // Free existing Brain
        brain = new Brain(*other.brain); // Deep copy of Brain
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;

	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Mee-owww!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}