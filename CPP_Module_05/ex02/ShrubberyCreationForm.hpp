#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm(void);

	std::string const &getTarget(void) const;

protected:
	virtual void	executeAction(void) const;

private:
	const std::string	_target;
};

#endif
