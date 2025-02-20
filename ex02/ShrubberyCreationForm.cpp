#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
/* ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	return(*this);
} */
/* std::ostream& operator<<(std::ostream &lhs, AForm &rhs)
{

} */

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	try {
		this->isExecutable(executor);
		std::string path(this->getName());
		path = "./" + path;
		path = path + "_shrubbery.txt";
		std::ofstream file(path);
		file << "          .     .  .      +     .      .          ." << std::endl;
		file << "     .       .      .     #       .           ." << std::endl;
		file << "        .      .         ###            .      .      ." << std::endl;
		file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
		file << "          .      . \"####\"###\"####\"  ." << std::endl;
		file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
		file << "  .             \"#########\"#########\"        .        ." << std::endl;
		file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
		file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
		file << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
		file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
		file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
		file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
		file << "            .     \"      000      \"    .     ." << std::endl;
		file << "       .         .   .   000     .        .       ." << std::endl;
		file << ".. .. ..................O000O........................ ...... ..." << std::endl;
	} catch (std::exception &e) {
		std::cout << executor.getName() << " can't execute " << this->getName() << " because "<< e.what() << std::endl;
	}
}
