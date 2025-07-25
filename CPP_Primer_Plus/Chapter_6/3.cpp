/* Write a precursor to a menu-driven program.
 * The program should display a menu offering four choices, each labeled with a letter.
 * If the user responds with a letter other than one of the four valid choices, the program should prompt the user to enter a valid response until the user complies.
 * Then the program should use a switch to select a simple action based on the user’s selection.
 * A program run could look something like this:
 * Please enter one of the following choices:
 * c) carnivore p) pianist
 * t) tree g) game
 * f
 * Please enter a c, p, t, or g: q
 * Please enter a c, p, t, or g: t
 * A maple is a tree. */

#include <iostream>

using namespace std;

int	main(void)
{
	char	input;

	cout	<< "Enter one of the following choices: " << endl;
	cout	<< "c) carnivore        p) pianist" << endl
		<< "t) tree             g) game" << endl;
	while (true)
	{
		cin >> input;
		if (input == 'c' || input == 'p' || input == 't' || input == 'g')
			break ;
		cout << "Please enter a c, p, t, or g: ";
	}
	switch (input)
	{
		case 'c':
			cout << "A lion is a carnivore." << endl;
			break ;
		case 'p':
			cout << "Mozart was a pianist." << endl;
			break ;
		case 't':
			cout << "A maple is a tree." << endl;
			break ;
		case 'g':
			cout << "Chess is a game." << endl;
			break ;
	}
	return (0);
}
