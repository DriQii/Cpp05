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

	private:

		std::string	_target;

};


#endif
