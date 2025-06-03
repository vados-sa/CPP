#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:name("Default name"), grade(1)
{
	std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Constructor called for " << name << "." << std::endl;

	this->name = name;
	this->grade = grade;

	try
	{
		if (grade < 1)
		throw std::out_of_range(GradeTooHighException());
		if (grade > 150)
		throw std::out_of_range(GradeTooLowException());
	}
	catch(const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for " << this->name << std::endl;
}

std::string Bureaucrat::GradeTooHighException()
{
	//std::cout << "Highest grade possible: 1." << std::endl;
	setGrade(1);
	return "Highest grade possible: 1.";
}

std::string Bureaucrat::GradeTooLowException()
{
	//std::cout << "Lowest grade possible: 150." << std::endl;
	setGrade(150);
	return "Lowest grade possible: 150.";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::setGrade(int n)
{
	grade = n;
}

void Bureaucrat::incrementGrade()
{
	grade--;

	try
	{
		if (grade < 1)
		throw std::out_of_range(GradeTooHighException());
	}
	catch(const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void Bureaucrat::decrementGrade()
{
	grade++;

	try
	{
		if (grade > 150)
		throw std::out_of_range(GradeTooLowException());
	}
	catch(const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << " bureaucrat grade " << obj.getGrade() << "." << std::endl; 
	return out; // return the stream
}