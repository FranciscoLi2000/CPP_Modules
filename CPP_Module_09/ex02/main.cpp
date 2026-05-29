/*
** The entry point is intentionally tiny.
** It only converts any exception into the generic Error output requested by
** the subject and leaves the real work to the class.
*/

#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
try
{
PmergeMe::run(argc, argv);
}
catch (const std::exception&)
{
std::cout << "Error" << std::endl;
return (1);
}
return (0);
}
