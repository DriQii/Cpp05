#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat{

public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const int grade);
	Bureaucrat(const std::string name);
	Bureaucrat(Bureaucrat &copy);
	~Bureaucrat();

	const std::string		getName() const;
	unsigned int	getGrade() const;

	Bureaucrat &operator=(Bureaucrat &rhs);

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

	void increment();
	void decrement();

private:

	const std::string	_name;
	unsigned int		_grade;
	void				setGrade(int grade);

};

std::ostream&	operator<<(std::ostream &lhs, Bureaucrat &rhs);

#endif
