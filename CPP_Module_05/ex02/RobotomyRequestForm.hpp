#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm(void);

	std::string const &getTarget(void) const;

protected:
	virtual void	executeAction(void) const;

private:
	const std::string	_target;
};

#endif
