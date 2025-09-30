#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Default Constructor called for RobotomyRequestForm." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "Constructor called for " << getName() << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
	std::cout << "Copy Constructor called for " << getName() << "." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy Assignment Operator called for " << getName() << "." << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

/* Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed. */
void RobotomyRequestForm::action() const {
	static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }

    std::cout << "* DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR *" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}
