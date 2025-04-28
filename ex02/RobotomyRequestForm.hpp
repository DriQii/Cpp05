#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public AForm{

	public:

		RobotomyRequestForm(std::string	target);
		RobotomyRequestForm(RobotomyRequestForm	&copy);
		~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const &executor);

	private:

		std::string	_target;

};

#endif
