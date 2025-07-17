
/* Do Programming Exercise 6, but instead of declaring an array of three CandyBar
 * structures, use new to allocate the array dynamically. */

#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char    brand_name[35];
	float   weight;
	unsigned int    calories;
};

int     main(void)
{
//	CandyBar        snack[3] = {{"Mocha Munch", 2.3, 350}, {"Lolipop", 3.4, 150}, {"Binbao", 1.9, 220}};
	CandyBar	*p_snack = new CandyBar[3];
	int     i;

	i = 0;
	strcpy(p_snack[0].brand_name, "Mocha Munch");
	strcpy(p_snack[1].brand_name, "Lolipop");
	strcpy(p_snack[2].brand_name, "Binbao");
	p_snack[0].weight = 2.3;
	p_snack[1].weight = 3.4;
	p_snack[2].weight = 1.9;
	p_snack[0].calories = 350;
	p_snack[1].calories = 150;
	p_snack[2].calories = 220;

	while (i < 3)
	{
		cout << "Brand: " << p_snack[i].brand_name << endl;
		cout << "Weight: " << p_snack[i].weight << endl;
		cout << "Calories: " << p_snack[i].calories << endl;
		if (i != 2)
			cout << "************************************" << endl;
		i++;
	}
	delete [] p_snack;
	return (0);
}
