#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "Default Constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm(target, false, 25, 5) {
	std::cout << "Constructor called for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
: AForm(other.getName(), other.getSign(), other.getGradeSign(), other.getGradeExec()) {
	std::cout << "Copy Constructor called for PresidentialPardonForm" << std::endl;
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy Assignment Operator called for PresidentialPardonForm" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

/* Informs that <target> has been pardoned by Zaphod Beeblebrox. */
void PresidentialPardonForm::action() const {
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

