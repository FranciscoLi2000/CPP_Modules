/* When you join the Benevolent Order of Programmers, you can be known at BOP
 * meetings by your real name, your job title, or your secret BOP name.Write a pro-
 * gram that can list members by real name, by job title, by secret name, or by a mem-
 * ber’s preference. Base the program on the following structure:
 * Benevolent Order of Programmers name structure */

const int strsize = 40;
const int usersize = 4;

struct bop
{
	char	fullname[strsize];
	char	title[strsize];
	char	bopname[strsize];
	int	preference; /* 0 = fullname, 1 = title, 2 = bopname */
};

bop	user[usersize] = {
	{"Rick", "level A", "RR", 0},
	{"Jack", "level B", "JJ", 1},
	{"Michael", "level C", "MM", 2},
	{"Rose", "level D", "RR", 0},
};

/* In the program, create a small array of such structures and initialize it to suitable values.
 * Have the program run a loop that lets the user select from different alternatives:
 * a. display by name		b. display by title
 * c. display by bopname	d. display by preference
 * q. quit */

#include <iostream>

using namespace std;

void	print_by_fullname(void)
{
	for (int i = 0; i < usersize; i++)
		cout	<< user[i].fullname << endl;
}

void	print_by_title(void)
{
	for (int i = 0; i < usersize; i++)
		cout	<< user[i].title << endl;
}

void	print_by_bopname(void)
{
	for (int i = 0; i < usersize; i++)
		cout	<< user[i].bopname << endl;
}

void	print_by_preference(void)
{
	for (int i = 0; i < usersize; i++)
	{
		switch (user[i].preference)
		{
			case 0: cout	<< user[i].fullname << endl; break ;
			case 1: cout	<< user[i].title << endl; break ;
			case 2: cout	<< user[i].bopname << endl; break ;
		}
	}
}

int	main(void)
{
	char	input;

	cout	<< "Enter the option character: " << endl;
	cout	<< "a. display by name\tb.display by title\n"
		<< "c. display by bopname\td. display by preference\n"
		<< "q. quit" << endl;
	cin.get(input);
	while (input != 'q')
	{
		switch (input)
		{
			case 'a': print_by_fullname(); break ;
			case 'b': print_by_title(); break ;
			case 'c': print_by_bopname(); break ;
			case 'd': print_by_preference(); break ;
			default: cout << "Please enter character a, b, c, d or q:" << endl;
		}
		cin.get();
		cout << "Next input: ";
		cin.get(input);
	}
	cout	<< "Bye!" << endl;
	return (0);
}
