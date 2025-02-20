#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public AForm{

	public:

		PresidentialPardonForm(std::string	target);
		PresidentialPardonForm(PresidentialPardonForm	&copy);
		~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const &executor);
		//PresidentialPardonForm& operator=(PresidentialPardonForm &rhs);

	private:

		std::string	_target;

};

//std::ostream& operator<<(std::ostream &lhs, AForm &rhs);

#endif
