#include <iostream>
#include <iomanip>


void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void reverse(int *arr, int size)
{
	for (int i = 0; i < (size/2); i++)
	{
		swap(&arr[i], &arr[(size-1)-i]);
	}
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.9.1
	std::cout << "Задача 1.9.1" << std::endl;
	const int size1 = 9;
	int arr1[size1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(arr1, size1);
	const int size2 = 4;
	int arr2[size2] = { 6, 5, 4, 8};
	print(arr2, size2);
	const int size3 = 5;
	int arr3[size3] = { 1, 4, 3, 7, 5};
	print(arr3, size3);


	//task 1.9.2
	std::cout << std::endl << "Задача 1.9.2" << std::endl;
	int a = 5, b = 8;
	std::cout << "a = " << a << ", " << "b = " << b << std::endl;
	swap(&a, &b);
	std::cout << "a = " << a << ", " << "b = " << b << std::endl;


	//task 1.9.3
	std::cout << std::endl << "Задача 1.9.3" << std::endl;
	std::cout << "До функции reverse: ";
	print(arr1, size1);
	std::cout << std::endl << "После функции reverse: ";
	reverse(arr1, size1);
	print(arr1, size1);

	return 0;
	
}


