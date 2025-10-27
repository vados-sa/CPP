#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name("Default name"), grade(1) {
	std::cout << "Default Constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: name(name), grade(grade) {
	
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	
	std::cout << "Constructor called for " << name << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:name(other.name), grade(other.grade) {
	std::cout << "Copy constructor." << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
	std::cout << "Copy assignment operator." << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called for " << this->name << "." << std::endl;
}


const char* Bureaucrat::GradeTooHighException::what() const  throw() {
	return "Grade too high error. Highest grade possible: 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const  throw() {
	return "Grade too low error. Lowest grade possible: 150." ;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1) throw Bureaucrat::GradeTooHighException();
	grade--;	
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form& form) {
	try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
    }
	catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."; 
	return out;
}