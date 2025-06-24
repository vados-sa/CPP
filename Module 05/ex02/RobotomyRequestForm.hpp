#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		void execute(Bureaucrat const & executor) const;
};