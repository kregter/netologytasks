

#include <iostream>
#include <iomanip>

int sum(int a, int b)
{
	return a + b;
}

int diff(int a, int b)
{
	return a - b;
}

int multiplication(int a, int b)
{
	return a * b;
}

double division(int a, int b)
{
	return static_cast<double>(a) / static_cast<double>(b);
}

void printPowerOfNumber(int value, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= value;
	}

	std::cout << value << " в степени " << power << " = " << result << std::endl;
}

int fibonacci(int number)
{
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;

	return fibonacci(number - 2) + fibonacci(number - 1);
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.6.1
	std::cout << "Задача 1.6.1" << std::endl;
	int a = 5, b = 10;

	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	std::cout << a << " + " << b << " = " << s << std::endl;
	std::cout << a << " - " << b << " = " << dif << std::endl;
	std::cout << a << " * " << b << " = " << mult << std::endl;
	std::cout << a << " / " << b << " = " << div << std::endl;

	//task 1.6.2
	std::cout << std::endl << "Задача 1.6.2" << std::endl;
	int value = 5, power = 2;
	printPowerOfNumber(value, power);

	value = 3; power = 3;
	printPowerOfNumber(value, power);

	value = 4; power = 4;
	printPowerOfNumber(value, power);

	//task 1.6.3
	std::cout << std::endl << "Задача 1.6.3" << std::endl;
	int fibonnachi_number;
	std::cout << "Введите число: " << std::endl;
	std::cin >> fibonnachi_number;

	std::cout << "Числа Фибоначчи:";
	for (int i = 0; i < fibonnachi_number; i++)
	{
		std::cout << " " << fibonacci(i);
	}
}


