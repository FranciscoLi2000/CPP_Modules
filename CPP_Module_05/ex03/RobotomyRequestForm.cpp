#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: Form(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		Form::operator=(other);
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed for " << _target << std::endl;
}
