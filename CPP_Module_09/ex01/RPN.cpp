/*
** The parser walks token by token.
** Numbers push values into the stack, operators pop two values, compute a
** result, and push the result back so the next token can reuse it.
*/

#include "RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>

bool RPN::isOperator(const std::string& token)
{
return (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int RPN::evaluate(const std::string& expression)
{
std::stack<int> values;
std::istringstream stream(expression);
std::string token;

while (stream >> token)
{
if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
{
values.push(token[0] - '0');
}
else if (isOperator(token))
{
int rhs;
int lhs;

if (values.size() < 2)
throw std::runtime_error("Error");
rhs = values.top();
values.pop();
lhs = values.top();
values.pop();
switch (token[0])
{
case '+': values.push(lhs + rhs); break;
case '-': values.push(lhs - rhs); break;
case '*': values.push(lhs * rhs); break;
case '/':
if (rhs == 0)
throw std::runtime_error("Error");
values.push(lhs / rhs);
break;
}
}
else
throw std::runtime_error("Error");
}
if (values.size() != 1)
throw std::runtime_error("Error");
return (values.top());
}
