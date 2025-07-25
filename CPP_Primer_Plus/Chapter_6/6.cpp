/* Put together a program that keeps track of monetary contributions to the Society for the Preservation of Rightful Influence.
 * 
 * It should ask the user to enter the number of contributors and then solicit the user to enter the name and contribution of
 * each contributor.
 * 
 * The information should be stored in a dynamically allocated array of structures.
 * 
 * Each structure should have two members: a character array (or else a string object) to store the name and a double member to hold the amount of the contribution.
 * 
 * After reading all the data, the program should display the names and amounts donated for all donors who contributed $10,000 or more.
 * 
 * This list should be headed by the label Grand Patrons.
 * 
 * After that, the program should list the remaining donors.
 * 
 * That list should be headed Patrons.
 * 
 * If there are no donors in one of the categories, the program should print the word “none.”
 * 
 * Aside from displaying two categories, the program need do no sorting. */

#include <iostream>
#include <string>

using namespace std;

struct	Patron
{
	string	name;
	double	donation;
};

int	main(void)
{
	int	num;

	cout	<< "Enter the number of donors: ";
	cin	>> num;
	cin.ignore(); /* Clear the newline left by cin >> */

	Patron	*donors = new Patron[num];

	for (int i = 0; i < num; i++)
	{
		cout	<< "\nDonor #" << i + 1 << ":" << endl;
		cout	<< "Enter the name of the donor: ";
		getline(cin, donors[i].name);
		cout	<< "Enter the donation amount: ";
		cin	>> donors[i].donation;
		cin.ignore();
	}
	cout	<< "\nGrand Patrons:" << endl;
	bool	hasGrandPatrons = false;
	for (int i = 0; i < num; i++)
	{
		if (donors[i].donation >= 10000)
		{
			cout	<< donors[i].name << ": $" << donors[i].donation << endl;
			hasGrandPatrons = true;
		}
	}
	if (!hasGrandPatrons)
		cout	<< "none" << endl;
	cout	<< "\nPatrons:" << endl;
	bool	hasPatrons = false;
	for (int i = 0; i < num; i++)
	{
		if (donors[i].donation < 10000)
		{
			cout	<< donors[i].name << ": $" << donors[i].donation << endl;
			hasPatrons = true;
		}
	}
	if (!hasPatrons)
		cout	<< "none" << endl;
	delete[] donors; 
	return (0);
}
