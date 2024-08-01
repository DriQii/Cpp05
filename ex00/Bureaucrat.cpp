#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat " << this->_name << " Default constructor called, name set to default and grade to 150" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	std::cout << "Bureaucrat " << this->_name << " Constructor with all argument called" << std::endl;
	try{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << "\nGrade set to 150" <<std::endl;
		_grade = 150;
	}
	catch(Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << "\nGrade set to 150" <<std::endl;
		_grade = 150;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " Default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const int grade) : _name("default")
{
	std::cout << "Bureaucrat " << this->_name << " constructor with only grade called, name set to default" << std::endl;
	try{
		setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << "\nGrade set to 150" <<std::endl;
		_grade = 150;
	}
	catch(Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << "\nGrade set to 150" <<std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat " << this->_name << " constructor with only name called, grade set to 150" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy.getName() + "_copy"), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

const std::string	Bureaucrat::getName() const
{
	return(_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return(_grade);
}

void	Bureaucrat::setGrade(int grade)
{

	if(grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;

}
void	Bureaucrat::increment()
{
	try{
		setGrade(_grade - 1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
void	Bureaucrat::decrement()
{
	try {
		setGrade(_grade + 1);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs)
{
	this->_grade = rhs.getGrade();
	return(*this);
}
std::ostream&	operator<<(std::ostream &lhs, Bureaucrat &rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (lhs);
}

