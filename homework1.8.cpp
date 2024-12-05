#include <iostream>
#include <iomanip>

void counting_function()
{
	static int runCounter = 0;
	runCounter++;
	std::cout << "Количество вызовов функции counting_function(): " << runCounter << std::endl;
}

namespace summ {
	int calc(int x, int y)
	{
		return x + y;
	}
}

namespace subtr {
	int calc(int x, int y)
	{
		return x - y;
	}
}

namespace mult {
	int calc(int x, int y)
	{
		return x * y;
	}
}

namespace divide {
	int calc(int x, int y)
	{
		return x / y;
	}
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.8.1
	std::cout << "Задача 1.8.1" << std::endl;
	
	for (int i = 0; i < 15; i++)
	{
		counting_function();
	}

	//task 1.8.2
	std::cout << std::endl << "Задача 1.8.2" << std::endl;
	
	int x = 6, y = 9;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "Сложение: " << summ::calc(x, y) << std::endl;
	std::cout << "Вычитание: " << subtr::calc(x, y) << std::endl;
	std::cout << "Умножение: " << mult::calc(x, y) << std::endl;
	std::cout << "Деление: " << divide::calc(x, y) << std::endl;

	return 0;
	
}


