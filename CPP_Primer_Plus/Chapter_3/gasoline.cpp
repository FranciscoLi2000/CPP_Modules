
/* Write a program that asks how many miles you have driven and how many gallons
 * of gasoline you have used and then reports the miles per gallon your car has gotten.
 * Or, if you prefer, the program can request distance in kilometers and petrol in liters
 * and then report the result European style, in liters per 100 kilometers */

#include <iostream>
using namespace std;

int	main(void)
{
	double	mile;
	double	kilometer;
	double	gallon;
	double	litre;
	double	fuel_consume;

	cout	<< "How many miles you have driven?" << endl;
	cin	>> mile;
	cout	<< "How many gallons of gasoline you have used?" << endl;
	cin	>> gallon;
	fuel_consume = mile / gallon;
	cout	<< "The fuel consume is "
		<< fuel_consume
		<< " miles/gallon"
		<<endl;
	cout	<< "How many kilometers you have driven?" << endl;
	cin	>> kilometer;
	cout	<< "How many litres of gasoline you have used?" << endl;
	cin	>> litre;
	fuel_consume = (litre / kilometer) * 100;
	cout	<< "The fuel consume is "
		<< fuel_consume
		<< " L/100km"
		<< endl;
	return (0);
}
