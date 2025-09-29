#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("Default"), isSigned(false), gradeToSign(1), gradeToExec(1) {
	std::cout << "Default Constructor." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "Constructor for " << name << "." << std::endl;

		if (gradeToSign < 1 || gradeToExec < 1) throw Form::GradeTooHighException();
		if (gradeToSign > 150 || gradeToSign > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
	std::cout << "Copy Constructor." << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy Assigment Operator." << std::endl;
	if (this != &other) {
		this->isSigned = other.isSigned;
		// name, gradeSign, and gradeExec are const and cannot be assigned
	}
	return *this;
}

Form::~Form() {
	std::cout << "Destructor called for " << getName() << "." << std::endl;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSignBool() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExec() const {
	return gradeToExec;
}

void Form::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > gradeToSign) throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const  throw()
{
	return "Grade too high error";
}

const char* Form::GradeTooLowException::what() const  throw()
{
	return "Grade too low error" ;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "Name: " << obj.getName() << std::endl << "Is it signed: " 
	<< obj.getSignBool() << std::endl << "Grade to sign it: " << obj.getGradeToSign()
	<< std::endl << "Grade to execute it: " << obj.getGradeToExec() << std::endl;

	return out;
}

