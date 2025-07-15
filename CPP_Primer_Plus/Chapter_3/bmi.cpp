
/* Write a short program that asks for your height in feet and inches and your weight in pounds.
 *
 * (Use three variables to store the information.)
 *
 * Have the program report your body mass index (BMI).
 * 
 * To calculate the BMI, first convert your height in feet and inches to your height in inches (1 foot = 12 inches).
 *
 * Then convert your height in inches to your height in meters by multiplying by 0.0254.
 *
 * Then convert your weight in pounds into your mass in kilograms by dividing by 2.2.
 *
 * Finally, compute your BMI by dividing your mass in kilograms by the square of your height in meters.
 *
 * Use symbolic constants to represent the various conversion factors. */

#include <iostream>
using namespace std;

const int	FOOT_TO_INCH = 12;
const float	INCH_TO_METER = 0.0254;
const double	KILLOGRAM_TO_POUND = 2.2;

int	main(void)
{
	int	height_foot;
	int	height_inch;
	double	height;
	double	weight;
	double	weight_pound;
	double	bmi;

	cout	<< "Enter your height in feet: ";
	cin	>> height_foot;
	cout	<< "Enter your height in inch: ";
	cin	>> height_inch;
	cout	<< "Enter your weight in pound: ";
	cin	>> weight_pound;
	height = (height_foot * FOOT_TO_INCH + height_inch) * INCH_TO_METER;
	weight = weight_pound / KILLOGRAM_TO_POUND;
	bmi = weight / (height * height);
	cout	<< "Your BMI rate is "
		<< bmi
		<< endl;
	return (0);
}
