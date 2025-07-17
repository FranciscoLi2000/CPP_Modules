
/* Rewrite Listing 4.4, using the C++ string class instead of char arrays. */

#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string		name;
	string		dessert;

	cout	<< "Enter your name:\n";
	getline(cin, name);
	cout	<< "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return (0);
}
