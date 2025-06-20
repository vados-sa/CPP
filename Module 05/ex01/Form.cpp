#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("Default"), isSigned(false), gradeSign(1), gradeExec(1) {
	std::cout << "Default Constructor." << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeSign, int gradeExec)
	: name(name), isSigned(isSigned), gradeSign(gradeSign), gradeExec(gradeExec) {
	std::cout << "Constructor for " << name << "." << std::endl;
	try
	{
		if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
		if (gradeSign > 150 || gradeSign > 150)
		throw Form::GradeTooLowException();
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	//this->isSigned = false;
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {
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
	std::cout << "Destructor." << std::endl;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSign() const {
	return isSigned;
}

int Form::getGradeSign() const {
	return gradeSign;
}

int Form::getGradeExec() const {
	return gradeExec;
}

void Form::beSigned(Bureaucrat Bureaucrat) {
	if (Bureaucrat.getGrade() <= gradeSign)
			isSigned = true;
	else 
		throw Form::GradeTooLowException(); // get's propagated to signForm()
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
	<< obj.getSign() << std::endl << "Grade to sign it: " << obj.getGradeSign()
	<< std::endl << "Grade to execute it: " << obj.getGradeExec() << std::endl;

	return out;
}

