#include "Form.hpp"

AForm::AForm() : _name("default"), _gradeToExecute(1), _gradeToSign(1), _isSigned(false)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(AForm &copy) : _name(copy.getName()), _gradeToExecute(copy.getGradeToExecute()), _gradeToSign(copy.getGradeToSign()), _isSigned(false)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int	gradeToSign, const unsigned int gradeToExecute) : _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _isSigned(false)
{
	std::cout << "Form " << this->_name << "Constructor called" << std::endl;
	_checkGrade(_gradeToSign, " (grade to sign)");
	_checkGrade(_gradeToExecute, " (grade to execute)");
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

const std::string	AForm::getName() const
{
	return _name;
}

bool				AForm::getIsSigned() const
{
	return _isSigned;
}

unsigned int	AForm::getGradeToSign() const
{
	return _gradeToSign;
}
unsigned int	AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	try{
		_setSigned(bureaucrat.getGrade());
	}
	catch(AForm::GradeTooLowException &e){
		std::cout << e.what() << " to sign"<< std::endl;
	}
}

void	AForm::_setSigned(const unsigned int grade)
{
	if(grade > _gradeToSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void	AForm::_checkGrade(int grade, std::string err)
{
	try{
		if(grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << e.what() << err << std::endl;
	}
}

AForm& AForm::operator=(AForm &rhs)
{
	this->_isSigned = rhs.getIsSigned();
	return(*this);
}

std::ostream& operator<<(std::ostream &lhs, AForm &rhs)
{
	std::string str("No");

	if (rhs.getIsSigned() == true)
		str = "Yes";
	lhs << "Form name : " << rhs.getName() << "\nGrade to sign : "
	<< rhs.getGradeToSign() << "\nGrade to execute : " << rhs.getGradeToExecute()
	<< "\nIs signed ? " << str;
	return lhs;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}
