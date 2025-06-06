#include "Animal.hpp"

Animal::Animal()
	: type("Base Animal")
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
	std::cout << "Animal Destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "I'm just an Animal, so basic!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

/* void Animal::setType(std::string type)
{
	this->type = type;
} */