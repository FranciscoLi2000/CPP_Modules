/* Write a program that matches the description of the program in Programming Exercise 8, but use a string class object instead of an array.
 * Include the string header file and use a relational operator to make the comparison test. */

#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string	words;
	int	count;

	count = 0;
	cout	<< "Enter words (to stop, type the word done)" << endl;
	do
	{
		cin	>> words;
		cin.get();
		count++;
	}
	while (words != "done");
	cout    << "You entered a total of "
		<< count - 1
		<< " words."
		<< endl;
	return (0);
}
