#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class Bureaucrat;

class AForm {

public :

	AForm();
	AForm(AForm &copy);
	AForm(const std::string name, const unsigned int	gradeToSign, const unsigned int gradeToExecute, const std::string _type);
	~AForm();

	const std::string	getName() const;
	bool				getIsSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExecute() const;
	const std::string	getType() const;

	virtual void	execute(Bureaucrat const &executor) = 0;

	AForm& operator=(AForm &rhs);

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	class	NotSignedException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
	void	isExecutable(Bureaucrat const &bureaucrat);
	void	beSigned(Bureaucrat &bureaucrat);

private :

	const std::string	_name;
	const unsigned int	_gradeToExecute;
	const unsigned int	_gradeToSign;
	bool				_isSigned;
	const std::string	_type;
	void				_setSigned(const unsigned int grade);
	void				_checkGrade(int grade, std::string err);

};

std::ostream& operator<<(std::ostream &lhs, AForm &rhs);

#endif
