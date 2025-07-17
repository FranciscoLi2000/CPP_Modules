
/* The CandyBar structure contains three members, as described in Programming
 * Exercise 5.Write a program that creates an array of three CandyBar structures, ini-
 * tializes them to values of your choice, and then displays the contents of each struc-
 * ture. */

#include <iostream>

using namespace std;

struct CandyBar
{
	char	brand_name[35];
	float	weight;
	unsigned int	calories;
};

int     main(void)
{
	CandyBar	snack[3] = {{"Mocha Munch", 2.3, 350}, {"Lolipop", 3.4, 150}, {"Binbao", 1.9, 220}};
	int	i;

	i = 0;
	while (i < 3)
	{
		cout	<< "Brand: " << snack[i].brand_name << endl;
		cout	<< "Weight: " << snack[i].weight << endl;
		cout	<< "Calories: " << snack[i].calories << endl;
		cout	<< endl;
		i++;
	}
	return (0);
}
