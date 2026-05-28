#ifndef BRAIN_HPP
#define BRAIN_HPP

/*
 * Brain is the owned resource that makes copy semantics interesting.
 */

#include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain(void);

	void	setIdea(int index, const std::string &idea);
	std::string	getIdea(int index) const;

private:
	std::string	ideas[100];
};

#endif
