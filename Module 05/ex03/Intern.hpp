#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);

		class UnknownFile : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};