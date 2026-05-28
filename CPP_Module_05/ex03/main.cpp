#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * The final exercise ties together factory creation, signing, and execution.
 */
int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern someRandomIntern;
	Form *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Form *shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
	Form *pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	Form *unknown = someRandomIntern.makeForm("pizza delivery", "Earth");

	Bureaucrat boss("Boss", 1);

	if (rrf != NULL)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}
	if (shrub != NULL)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}
	if (pardon != NULL)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
	delete unknown;

	return (0);
}
