#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat {
	private:
			std::string name;
			int			grade;
	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator = (const Bureaucrat& other);
			~Bureaucrat();

			std::string getName() const;
			int getGrade() const;
			void setGrade(int n);
			void incrementGrade();
			void decrementGrade();

			class GradeTooHighException : public std::exception{
				public:
					virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception{
				public:
					virtual const char* what() const throw();
			};

			void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);