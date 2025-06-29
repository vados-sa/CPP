#pragma once

#include "AForm.hpp"
//class Bureaucrat;
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		void action() const;
};