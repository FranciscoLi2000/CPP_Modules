/* Write a program that opens a text file, reads it character-by-character to the end of
 * the file, and reports the number of characters in the file. */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int	main(void)
{
	ifstream	inFile;
	string	filename;
	char	c;
	int	count;

	count = 0;
	cout	<< "Enter the file name: ";
	getline(cin, filename);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout	<< "Cannot open the file" << endl;
		exit(EXIT_FAILURE);
	}
	while (!inFile.eof())
	{
		inFile	>> c;
		count++;
	}
	cout	<< "The file " << filename
		<< " has " << count << " characters." << endl;
	inFile.close();
	return (0);
}
