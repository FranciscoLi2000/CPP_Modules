/* Write a program that reads keyboard input to the @ symbol and that echoes the
 * input except for digits, converting each uppercase character to lowercase, and vice
 * versa. (Don’t forget the cctype family.) */

#include <iostream>
#include <cctype>

using namespace std;

int	main(void)
{
	char	input;

	cout << "Enter a character: ";
	cin >> input;
	while (input != '@')
	{
		if (isdigit(input))
		{
			cin >> input;
			continue ;
		}
		else if (islower(input))
			input = toupper(input);
		else
			input = tolower(input);
		cout << input;
		cin >> input;
	}
	return (0);
}
