#include <iostream>
#include <fstream>
#include <thread>


struct Field
{
	bool** arr1;
	bool** arr2;
	int rows;
	int cols;
};

struct EndGame
{
	bool stagnation;
	bool noMoreLivCells;
};

bool** create_two_dim_array(int rows, int cols)
{
	bool** arr = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new bool[cols]();
	}
	return arr;
}

void copy_array(Field& curField)
{
	for (int i = 0; i < curField.rows; i++)
	{
		for (int j = 0; j < curField.cols; j++)
		{
			curField.arr2[i][j] = curField.arr1[i][j];
		}
	}
}

void print_two_dim_array(Field& curField, int generation, int numOfAliveCells)
{
	for (int i = 0; i < curField.rows; i++)
	{
		for (int j = 0; j < curField.cols; j++)
		{
			if (curField.arr1[i][j] == 1)
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Generation: " << generation << ". Alive cells: " << numOfAliveCells << std::endl;

}

void delete_two_dim_array(bool** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}



int count_of_neighbours(Field& curField, int i, int j)
{
	int numOfNeigh = 0;
	if (i == 0 && j == 0)
	{
		numOfNeigh = curField.arr2[i][j + 1] + curField.arr2[i + 1][j] + curField.arr2[i + 1][j + 1];
	}
	else if (i == curField.rows - 1 && j == 0)
	{
		numOfNeigh = curField.arr2[i - 1][j] + curField.arr2[i - 1][j + 1] + curField.arr2[i][j + 1];
	}
	else if (i == 0 && j == curField.cols - 1)
	{
		numOfNeigh = curField.arr2[i][j - 1] + curField.arr2[i + 1][j - 1] + curField.arr2[i + 1][j];
	}
	else if (i == curField.rows - 1 && j == curField.cols - 1)
	{
		numOfNeigh = curField.arr2[i - 1][j - 1] + curField.arr2[i - 1][j] + curField.arr2[i][j - 1];
	}
	else if (i == 0)
	{
		numOfNeigh = curField.arr2[i][j - 1] + curField.arr2[i][j + 1] + curField.arr2[i + 1][j - 1] 
			+ curField.arr2[i + 1][j] + curField.arr2[i + 1][j + 1];
	}
	else if (j == 0)
	{
		numOfNeigh = curField.arr2[i - 1][j] + curField.arr2[i - 1][j + 1] + curField.arr2[i][j + 1] 
			+ curField.arr2[i + 1][j] + curField.arr2[i + 1][j + 1];
	}
	else if (i == curField.rows - 1)
	{
		numOfNeigh = curField.arr2[i - 1][j - 1] + curField.arr2[i - 1][j] + curField.arr2[i - 1][j + 1] 
			+ curField.arr2[i][j - 1] + curField.arr2[i][j + 1];
	}
	else if (j == curField.cols - 1)
	{
		numOfNeigh = curField.arr2[i - 1][j - 1] + curField.arr2[i - 1][j] + curField.arr2[i][j - 1] 
			+ curField.arr2[i + 1][j - 1] + curField.arr2[i + 1][j];
	}
	else
	{
		numOfNeigh = curField.arr2[i - 1][j - 1] + curField.arr2[i - 1][j] + curField.arr2[i - 1][j + 1] + curField.arr2[i][j - 1] 
			+ curField.arr2[i][j + 1] + curField.arr2[i + 1][j - 1] + curField.arr2[i + 1][j] + curField.arr2[i + 1][j + 1];
	}
	return numOfNeigh;
}

void cell_dustribution(Field& curField, int i, int j)
{
	int numOfNeigh = count_of_neighbours(curField, i, j);
	if (numOfNeigh == 3)
	{
		curField.arr1[i][j] = 1;
	}
	else if (curField.arr2[i][j] == 1 && numOfNeigh == 2)
	{
		curField.arr1[i][j] = 1;
	}
	else
	{
		curField.arr1[i][j] = 0;
	}
}

int count_of_alive_cells(Field& curField)
{
	int numOfAliveCells = 0;
	for (int i = 0; i < curField.rows; i++)
	{
		for (int j = 0; j < curField.cols; j++)
		{
			numOfAliveCells += curField.arr1[i][j];
		}
	}
	return numOfAliveCells;
}

bool is_stagnation(Field& curField)
{
	for (int i = 0; i < curField.rows; i++)
	{
		for (int j = 0; j < curField.cols; j++)
		{
			if (curField.arr1[i][j] != curField.arr2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void live_session(Field& curField, EndGame& errors, int &generation, int numOfAliveCells)
{
	if (count_of_alive_cells(curField) == 0)
	{
		errors.noMoreLivCells = 1;
		return;
	}

	for (int i = 0; i < curField.rows; i++)
	{
		for (int j = 0; j < curField.cols; j++)
		{
			cell_dustribution(curField, i, j);
		}
	}

	if (is_stagnation(curField) == 1)
	{
		errors.stagnation = 1;
		generation++;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::system("cls");
		print_two_dim_array(curField, generation, numOfAliveCells);
	}
}

int main()
{
	// Write the first state of universe from file
	int rows, cols;
	std::ifstream fin("in.txt");
	fin >> rows >> cols;
	bool** curState = create_two_dim_array(rows, cols);
	bool** prevState = create_two_dim_array(rows, cols);
	while (!fin.eof())
	{
		int i, j;
		fin >> i >> j;
		curState[i][j] = 1;
	}
	fin.close();

	Field curField = { curState, prevState, rows, cols };

	bool stagnation = 0, noMoreLivCells = 0;
	EndGame errors = { stagnation, noMoreLivCells };
	
	int generation = 1;
	
	while (errors.stagnation == 0 && errors.noMoreLivCells == 0)
	{
		std::system("cls");
		int numOfAliveCells = count_of_alive_cells(curField);
		print_two_dim_array(curField, generation, numOfAliveCells);
		copy_array(curField);
		live_session(curField, errors, generation, numOfAliveCells);
		generation++;

		if (errors.stagnation == 1)
		{
			std::cout << "The world has stagnated. Game over" << std::endl;
		}
		else if (errors.noMoreLivCells == 1)
		{
			std::cout << "All cells are dead. Game over" << std::endl;
		}
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} 

	delete_two_dim_array(curState, rows);
	delete_two_dim_array(prevState, rows);

	return 0;
}
