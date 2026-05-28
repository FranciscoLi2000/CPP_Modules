#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: Form(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		Form::operator=(other);
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	file((_target + "_shrubbery").c_str());

	file << "   ccee88oo\n";
	file << " C8O8O8Q8PoOb o8oo\n";
	file << "dOB69QO8PdUOpugoO9bD\n";
	file << "CgggbU8OU qOp qOdoUOdcb\n";
	file << "    6OuU  /p u gcoUodpP\n";
	file << "      \\\\//  /douUP\n";
	file << "        \\\\////\n";
	file << "         ||||\n";
	file << "         ||||\n";
}
