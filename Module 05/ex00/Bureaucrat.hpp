#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
	private:
			const std::string name;
			int			grade; // 1 (highest) - 150 (lowest) 
	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator = (const Bureaucrat& other);
			~Bureaucrat();

			const std::string& getName() const;
			int getGrade() const;
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);