#include <iostream>
#include <iomanip>

void get_array_values(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}
}

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(3) << arr[i] << " ";
	}
	std::cout << std::endl;
}

double* create_array(int size)
{
	return new double[size]();
}

void print_darray(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(3) << arr[i] << " ";
	}
	std::cout << std::endl;
}

int** create_two_dim_array(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void fill_two_dim_array(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (i+1)*(j+1);
		}
	}
}

void print_two_dim_array(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		print_array(arr[i], cols);
	}
}

void delete_two_dim_array(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.10.1
	std::cout << "Задача 1.10.1" << std::endl;
	std::cout << "Введите размер массива: ";
	int size_array;
	std::cin >> size_array;
	int* arr_ptr = new int[size_array];
	get_array_values(arr_ptr, size_array);
	std::cout << "Ввёденный массив: ";
	print_array(arr_ptr, size_array);
	delete[] arr_ptr;

	//task 1.10.2
	std::cout << std::endl << "Задача 1.10.2" << std::endl;
	std::cout << "Введите размер массива: ";
	int size_array2;
	std::cin >> size_array2;
	double* external_arr = create_array(size_array2);
	std::cout << "Массив: ";
	print_darray(external_arr, size_array2);
	delete[] external_arr;
	

	//task 1.10.3
	std::cout << std::endl << "Задача 1.10.3" << std::endl;
	int rows, cols;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;
	std::cout << "Введите количество столбцов: ";
	std::cin >> cols;
	int** ext_arr = create_two_dim_array(rows, cols);
	fill_two_dim_array(ext_arr, rows, cols);
	std::cout << "Таблица умножения: " << std::endl;
	print_two_dim_array(ext_arr, rows, cols);
	delete_two_dim_array(ext_arr, rows);

	return 0;
	
}


