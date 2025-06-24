#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name("Default name"), grade(1) {
	std::cout << "Default Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	std::cout << "Constructor called for " << name << "." << std::endl;

	this->name = name;
	this->grade = grade;

	try
	{
		if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
		setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:name(other.name), grade(other.grade) {
	std::cout << "Copy constructor." << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
	std::cout << "Copy assignment operator." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called for " << this->name << "." << std::endl;
}


const char* Bureaucrat::GradeTooHighException::what() const  throw() {
	return "Grade too high error: Highest grade possible: 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const  throw() {
	return "Grade too low error: Lowest grade possible: 150." ;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::setGrade(int n) {
	grade = n;
}

void Bureaucrat::incrementGrade() {
	grade--;

	try
	{
		if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		setGrade(1);
	}	
}

void Bureaucrat::decrementGrade() {
	grade++;

	try
	{
		if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
		setGrade(150);
	}
}

void Bureaucrat::signForm(Form& form) {
	try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
	catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << " bureaucrat grade " << obj.getGrade() << "." << std::endl; 
	return out;
}