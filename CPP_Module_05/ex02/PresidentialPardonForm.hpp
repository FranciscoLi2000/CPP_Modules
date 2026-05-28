#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm(void);

	std::string const &getTarget(void) const;

protected:
	virtual void	executeAction(void) const;

private:
	const std::string	_target;
};

#endif
