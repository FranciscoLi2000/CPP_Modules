/*
** CPP09 ex01 - Reverse Polish Notation
**
** A stack is the natural container here because RPN always combines the two
** most recent values before continuing with the next token.
*/

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
static intevaluate(const std::string& expression);

private:
static boolisOperator(const std::string& token);
};

#endif
