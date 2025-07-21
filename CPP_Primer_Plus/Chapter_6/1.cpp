/* Write a program that reads keyboard input to the @ symbol and that echoes the
 * input except for digits, converting each uppercase character to lowercase, and vice
 * versa. (Don’t forget the cctype family.) */

#include <iostream>
#include <cctype>

using namespace std;

int	main(void)
{
	char	ch;

	while (cin.get(ch) != '@')
	{
		if (isalpha(ch))
		{
			if (isupper(ch))
				cout << tolower(ch);
			else if (islower(ch))
				cout << toupper(ch);
		}
		else if (isdigit(ch))
			continue ;
	}
	return (0);
}
