#pragma once

#include <iostream>

class Brain
{
	private:
		std::string ideas[100]; // not sure yet if it is supposed to be private or public

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator = (const Brain& other);
		~Brain();
};