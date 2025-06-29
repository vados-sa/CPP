#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Default Constructor called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm(target, false, 72, 45) {
	std::cout << "Constructor called for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
: AForm(other.getName(), other.getSign(), other.getGradeSign(), other.getGradeExec()) {
	std::cout << "Copy Constructor called for RobotomyRequestForm" << std::endl;
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy Assignment Operator called for RobotomyRequestForm" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

/* Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed. */
void RobotomyRequestForm::action() const {
		std::cout << "* DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR *" << std::endl;
		std::cout << this->getName() << " has been robotomized successfully 50\% of the time." << std::endl;
}