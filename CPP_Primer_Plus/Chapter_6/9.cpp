/* Do Programming Exercise 6 but modify it to get information from a file.
 * The first item in the file should be the number of contributors, and the rest of the file should consist of pairs of lines, with the first line of each pair being a contributor’s name and the second line being a contribution.
 *
 * That is, the file should look like this:
 * 4
 * Sam Stone
 * 2000
 * Freida Flass
 * 100500
 * Tammy Tubbs
 * 5000
 * Rich Raptor
 * 55000 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct	Patron
{
	string	name;
	double	donation;
};

int	main(void)
{
	ifstream	inFile;
	string	filename;

	cout	<< "Enter the filename you want to open: ";
	cin	>> filename;
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cerr	<< "Error: Could not open the file!" << endl;
		return (1);
	}
	int	num;
	inFile	>> num;
	inFile.ignore();
	Patron *donors = new Patron[num];
	for (int i = 0; i < num; i++)
	{
		getline(inFile, donors[i].name);
		inFile	>> donors[i].donation;
		inFile.ignore();
	}
	inFile.close();
	cout	<< "Grand Patrons:" << endl;
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
		cout << "none" << endl;
	cout << "\nPatrons:" << endl;
	bool	hasPatrons = false;
	for (int i = 0; i < num; i++)
	{
		if (donors[i].donation < 10000)
		{
			cout << donors[i].name << ": $" << donors[i].donation << endl;
			hasPatrons = true;
		}
	}
	if (!hasPatrons)
		cout << "none" << endl;
	delete[] donors;
	return (0);
}
