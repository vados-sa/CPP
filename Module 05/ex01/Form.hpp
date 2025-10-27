#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeToSign;
		const int	gradeToExec;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		
		const std::string& getName() const;
		bool getSignBool() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(Bureaucrat& Bureaucrat);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);
