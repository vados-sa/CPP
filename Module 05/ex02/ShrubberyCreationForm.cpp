#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Default Constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm(target, false, 145, 137) {
	std::cout << "Constructor called for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
: AForm(other.getName(), other.getSign(), other.getGradeSign(), other.getGradeExec()) {
	std::cout << "Copy Constructor called for ShrubberyCreationForm" << std::endl;
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy Assignment Operator called for ShrubberyCreationForm" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

/* Creates a file <target>_shrubbery in the working directory and writes ASCII trees
	inside it. */
void ShrubberyCreationForm::action() const {
	std::ofstream file;
	file.open(this->getName() + "_shrubbery");
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