#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called." << std::endl;
	
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other)
	: AAnimal(other)
{
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other); // Copy base class attributes
        delete brain;             // Free existing Brain
        brain = new Brain(*other.brain); // Deep copy of Brain
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called." << std::endl;

	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}