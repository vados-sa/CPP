#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeToSign;
		const int	gradeToExec;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
		
		std::string getName() const;
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

		class FormNotSignedException : public std::exception{ // check what this is for
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);
