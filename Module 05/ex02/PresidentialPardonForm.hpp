#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	public:
		void execute(Bureaucrat const & executor) const;
};