#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called." << std::endl;
	
	for(int i = 0; i < 100; i++)
		ideas[i] = "Default idea";
}

Brain::Brain(const Brain& other)
{
	for(int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}