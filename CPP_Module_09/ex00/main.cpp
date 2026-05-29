/*
** Main is intentionally small: it only wires the subject rule into the class.
** The program name is btc and it always reads the historical data from
** data.csv, while the user supplies the input file to evaluate.
*/

#include "BitcoinExchange.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
BitcoinExchange exchange;

if (argc != 2)
{
std::cout << "Error: could not open file." << std::endl;
return (1);
}
try
{
exchange.loadDatabase("data.csv");
exchange.processInput(argv[1]);
}
catch (const std::exception& e)
{
std::cout << e.what() << std::endl;
return (1);
}
return (0);
}
