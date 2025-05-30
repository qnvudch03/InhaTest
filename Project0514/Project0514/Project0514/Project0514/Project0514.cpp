#include <iostream>
using namespace std;

int main(void)
{
	float f = 0.1f;
	double d = 0.1;

	float f4 = 123456789.1f;
	float f5 = 0.00000000234567891412345f;


	float TestSum = 0.0f;

	for (int i = 0; i < 10; i++)
	{
		TestSum += f;
	}

	//cout.precision(10);
	cout << TestSum <<'\n';
	cout << f * 10 << '\n';


	cout << f4 << '\n';
	cout << f5 << '\n';

	cout << (int)'A' << '\n';
	return 0;
}