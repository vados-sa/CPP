#include "ShrubberyCreationForm.hpp"
//#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Default Constructor called for ShrubberyCreationForm." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Constructor called for " << getName() << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()) {
	std::cout << "Copy Constructor called for " << getName() << "." << std::endl;
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy Assignment Operator called for " << getName() << "." << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

/* Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	inside it. */
void ShrubberyCreationForm::action() const {
	std::ofstream file;
	file.open((target + "_shrubbery").c_str());
	file << "      /\\" << std::endl;
	file << "     /**\\" << std::endl;
	file << "    /****\\" << std::endl;
	file << "     /**\\" << std::endl;
	file << "    /****\\" << std::endl;
	file << "   /******\\" << std::endl;
	file << "  /********\\" << std::endl;
	file << "      ||" << std::endl;
	file << "      ||" << std::endl;
	file.close();
}
