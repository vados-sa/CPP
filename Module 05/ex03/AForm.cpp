#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: name("Default"), isSigned(false), gradeToSign(1), gradeToExec(1) {
	std::cout << "Abstarct Default Constructor called." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "Abstract Constructor called." << std::endl;

		if (gradeToSign < 1 || gradeToExec < 1) throw AForm::GradeTooHighException();
		if (gradeToSign > 150 || gradeToSign > 150) throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
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
	std::cout << "Abstract Destructor called." << std::endl;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSignBool() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExec() const {
	return gradeToExec;
}

void AForm::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > gradeToSign) throw AForm::GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (AForm::getSignBool() == false)
			throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
			throw Bureaucrat::GradeTooLowException();
	else
		this->action();
}

const char* AForm::GradeTooHighException::what() const  throw() {
	return "Grade too high error";
}

const char* AForm::GradeTooLowException::what() const  throw() {
	return "Grade too low error" ;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	out << "Name: " << obj.getName() << std::endl << "Is it signed: " 
	<< obj.getSignBool() << std::endl << "Grade to sign it: " << obj.getGradeToSign()
	<< std::endl << "Grade to execute it: " << obj.getGradeToExec() << std::endl;

	return out;
}

