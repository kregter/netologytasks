#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>


void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void reverse(int* arr, int size)
{
	for (int i = 0; i < (size / 2); i++)
	{
		swap(&arr[i], &arr[(size - 1) - i]);
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

int** create_two_dim_array(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    //task 1.12.1
	std::cout << "Задача 1.12.1" << std::endl;
	std::string txtFromFile;
	std::ifstream fin("txt1.txt");
	while (!fin.eof())
	{
		fin >> txtFromFile;
		std::cout << txtFromFile << std::endl;
	}
	fin.close();

	//task 1.12.2
	std::cout << std::endl << "Задача 1.12.2" << std::endl;
	int size;
	std::ifstream fin2("txt2.txt");
	fin2 >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		fin2 >> arr[i];
	}

	reverse(arr, size);
	print_array(arr, size);
	fin2.close();

	//task 1.12.3
	std::cout << std::endl << "Задача 1.12.3" << std::endl;
	std::cout << "Введите размер массива: ";
	int size2;
	std::cin >> size2;
	int* arr2 = new int[size2];

	for (int i = 0; i < size2; i++)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr2[i];
	}

	reverse(arr2, size2);

	std::ofstream fout ("out.txt");
	fout << size2 << std::endl;
	for (int i = 0; i < size2; i++)
	{
		fout << arr2[i] << " ";
	}
	fout.close();

	//task 1.12.4
	std::cout << std::endl << "Задача 1.12.4" << std::endl;
	int rows, cols;
	std::ifstream fin3("in.txt");
	fin3 >> rows >> cols;
	int** array1 = create_two_dim_array(rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fin3 >> array1[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		reverse(array1[i], cols);
		print_array(array1[i], cols);
	}

	delete_two_dim_array(array1, rows);
	fin3.close();

	return 0;
	
}


