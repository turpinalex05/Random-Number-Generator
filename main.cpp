/*
	Random-Number-Generator.cpp

	randomly generates 9 numbers between 1-100
*/

#include <iostream>
#include <cstdlib>

int random(int num)
{
	num = rand() % 100;
	return num;
}

int main()
{
	srand(time(0));
	int number = 0;
	int output = 0;
	for (int i = 0; i < 9; i++) {
		output = random(number);
		std::cout << output << std::endl;
	}

	return 0;
}
