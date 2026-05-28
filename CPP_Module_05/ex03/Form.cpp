#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void) : _name("DefaultForm"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "Form assignment operator called" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

std::string const &Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeAction();
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("form not signed");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << ", sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade()
		<< ", signed: " << (form.getSigned() ? "yes" : "no");
	return (os);
}
