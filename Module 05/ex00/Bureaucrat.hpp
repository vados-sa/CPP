#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
	private:
			std::string name;
			int			grade; // 1 (highest) <= grade <= 150 (lowest) 
	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator = (const Bureaucrat& other);
			~Bureaucrat();

			std::string GradeTooHighException(); // needs to be an exception class.
			std::string GradeTooLowException(); // needs to be an exception class.
			std::string getName() const;
			int getGrade() const;
			void setGrade(int n);
			void incrementGrade(); // incrementing a grade 3 should result in a grade 2 for the bureaucrat
			void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);