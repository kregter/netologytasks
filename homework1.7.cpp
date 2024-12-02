

#include <iostream>
#include <iomanip>

void swap(int &a1, int &b1)
{
	int c = a1;
	a1 = b1;
	b1 = c;
}

void swap2(int &a2, int &b2)
{
	a2 += b2;
	b2 = a2 - b2;
	a2 -= b2;
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.7.1
	std::cout << "Задача 1.7.1" << std::endl;
	int a = 1;
	short b = 1;
	long c = 1;
	long long d = 1;
	float e = 1;
	double f = 1;
	long double g = 1;
	bool h = true;

	std::cout << "int: " << &a << " " << sizeof(a) << std::endl;
	std::cout << "short: " << &b << " " << sizeof(b) << std::endl;
	std::cout << "long: " << &c << " " << sizeof(c) << std::endl;
	std::cout << "long long: " << &d << " " << sizeof(d) << std::endl;
	std::cout << "float: " << &e << " " << sizeof(e) << std::endl;
	std::cout << "double: " << &f << " " << sizeof(f) << std::endl;
	std::cout << "long double: " << &g << " " << sizeof(g) << std::endl;
	std::cout << "bool: " << &h << " " << sizeof(h) << std::endl;

	//task 1.7.2
	std::cout << std::endl << "Задача 1.7.2" << std::endl;
	int a1 = 5, b1 = 8;

	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;

	swap(a1, b1);

	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;

	//task 1.7.2 extended
	std::cout << std::endl << "Задача 1.7.2 усложненная" << std::endl;
	int a2 = 5, b2 = 8;

	std::cout << "a = " << a2 << ", b = " << b2 << std::endl;

	swap2(a2, b2);

	std::cout << "a = " << a2 << ", b = " << b2 << std::endl;

	return 0;
	
}


