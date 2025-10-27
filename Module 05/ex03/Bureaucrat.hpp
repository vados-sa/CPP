#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat {
	private:
			const std::string name;
			int			grade;
	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator = (const Bureaucrat& other);
			~Bureaucrat();

			const std::string& getName() const;
			int getGrade() const;
			void setGrade(int n);
			void incrementGrade();
			void decrementGrade();
			void executeForm(AForm const & form) const;

			class GradeTooHighException : public std::exception{
				public:
					virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception{
				public:
					virtual const char* what() const throw();
			};

			void signForm(AForm& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);