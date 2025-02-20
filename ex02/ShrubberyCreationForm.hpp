#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{

	public:

		ShrubberyCreationForm(std::string	target);
		ShrubberyCreationForm(ShrubberyCreationForm	&copy);
		~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const &executor);
		//ShrubberyCreationForm& operator=(ShrubberyCreationForm &rhs);

	private:

		std::string	_target;

};

//std::ostream& operator<<(std::ostream &lhs, AForm &rhs);

#endif
