#include "PresidentialPardonForm.hpp"
//#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "Default Constructor called for PresidentialPardonForm." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "Constructor called for " << getName() << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
	std::cout << "Copy Constructor called for " << getName() << "." << std::endl;
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy Assignment Operator called for " << getName() << "." << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

/* Informs that <target> has been pardoned by Zaphod Beeblebrox. */
void PresidentialPardonForm::action() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
