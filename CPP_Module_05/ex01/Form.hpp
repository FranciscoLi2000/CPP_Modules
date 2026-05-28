#ifndef FORM_HPP
#define FORM_HPP

/*
 * Form introduces the first real bureaucracy workflow:
 * a form can be signed only by a strong enough bureaucrat.
 */

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string const &name, int signGrade, int executeGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
	virtual ~Form(void);

	std::string const &getName(void) const;
	bool	getSigned(void) const;
	int	getSignGrade(void) const;
	int	getExecuteGrade(void) const;
	void	beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_executeGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
