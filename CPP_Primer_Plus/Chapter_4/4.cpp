
/* Write a program that asks the user to enter his or her first name and then last
 * name, and that then constructs, stores, and displays a third string consisting of the
 * user’s last name followed by a comma, a space, and first name. Use string objects
 * and methods from the string header file.A sample run could look like this:
 * Enter your first name: Flip
 * Enter your last name: Fleming
 * Here’s the information in a single string: Fleming, Flip */

#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string	first_name;
	string	last_name;
	string	full_name;

	cout	<< "Enter your first name: " << endl;
	getline(cin, first_name);
	cout	<< "Enter your last name: ";
	getline(cin, last_name);

	full_name = last_name + ", " + first_name;

	cout	<< "Here's the information in a single string: "
		<< full_name
		<< endl;
	return (0);
}
