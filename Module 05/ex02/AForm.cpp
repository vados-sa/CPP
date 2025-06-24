#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: name("Default"), isSigned(false), gradeSign(1), gradeExec(1) {
	std::cout << "Default Constructor." << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int gradeSign, int gradeExec)
	: name(name), isSigned(isSigned), gradeSign(gradeSign), gradeExec(gradeExec) {
	std::cout << "Constructor for " << name << "." << std::endl;
	try
	{
		if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
		if (gradeSign > 150 || gradeSign > 150)
		throw AForm::GradeTooLowException();
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	//this->isSigned = false;
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {
	std::cout << "Copy Constructor." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy Assigment Operator." << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
		// name, gradeSign, and gradeExec are const and cannot be assigned
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "Destructor." << std::endl;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSign() const {
	return isSigned;
}

int AForm::getGradeSign() const {
	return gradeSign;
}

int AForm::getGradeExec() const {
	return gradeExec;
}

void AForm::beSigned(Bureaucrat Bureaucrat) {
	if (Bureaucrat.getGrade() <= gradeSign)
			isSigned = true;
	else 
		throw AForm::GradeTooLowException(); // get's propagated to signAForm()
}

const char* AForm::GradeTooHighException::what() const  throw()
{
	return "Grade too high error";
}

const char* AForm::GradeTooLowException::what() const  throw()
{
	return "Grade too low error" ;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "Name: " << obj.getName() << std::endl << "Is it signed: " 
	<< obj.getSign() << std::endl << "Grade to sign it: " << obj.getGradeSign()
	<< std::endl << "Grade to execute it: " << obj.getGradeExec() << std::endl;

	return out;
}

