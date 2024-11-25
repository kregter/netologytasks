

#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "rus");
    
    //task 1.5.1
    std::cout << "Задача 1.5.1:" << std::endl;
    const int size = 10;
    int arr[size] = { 10, 4, 2, 5, 40, 22, 56, 11, 33, 19 };
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            std::cout << arr[i] << ", ";
        }
        else
        {
            std::cout << arr[i] << std::endl;
        }
    }

    //task 1.5.2
    std::cout << std::endl << "Задача 1.5.2:" << std::endl;
    const int size1 = 10;
    int arr1[size1] = { 10, 4, 2, 5, 40, 22, 56, 11, 33, 19 };
    int max = arr1[0], min = arr1[0];
    for (int i = 1; i < size1; i++)
    {
        if (arr1[i] > max)
        {
            max = arr1[i];
        }
        else if (arr1[i] < min)
        {
            min = arr1[i];
        }
    }
    std::cout << "Массив: ";
    for (int num: arr1)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl << "Максимальный элемент: " << max << std::endl;
    std::cout << "Минимальный элемент: " << min << std::endl;
    

    //task 1.5.3
    std::cout << std::endl << "Задача 1.5.3:" << std::endl;
    const int sizei = 3, sizej = 6;
    int maxi = 0, maxj = 0, mini = 0, minj = 0;
    int arr2[sizei][sizej] =    { {10, 4, 66, 6, 40, 33},
                                {25, 3, 55, 34, 60, 7},
                                {22, 5, 56, 26, 67, 8}
     };

    std::cout << "Массив: " << std::endl;
    for (int i = 0; i < sizei; i++)
    {
        for (int j = 0; j < sizej; j++)
        {
            if (arr2[i][j] > arr2[maxi][maxj])
            {
                maxi = i;
                maxj = j;
            }
            else if (arr2[i][j] < arr2[mini][minj])
            {
                mini = i;
                minj = j;
            }
            
            std::cout << arr2[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Индекс минимального элемента: " << mini << " " << minj << std::endl;
    std::cout << "Индекс максимального элемента: " << maxi << " " << maxj << std::endl;
    

    //task 1.5.4
    std::cout << std::endl << "Задача 1.5.4:" << std::endl;
    const int size3 = 10;
    int arr3[size3] = {4, 2, 78, 56, 9, 77, 3, 56, 77, 20};

    std::cout << "Массив до сортировки: ";
    for (int i = 0; i < size3; i++)
    {
        std::cout << arr3[i] << " ";
    }

    for (int i = 0; i < size3; i++)
    {
        for (int j = size3 - 1; j > 0; j--)
        {
            if (arr3[j] < arr3[j - 1])
            {
                int a = arr3[j];
                arr3[j] = arr3[j - 1];
                arr3[j - 1] = a;
            }
        }
    }

    std::cout << std::endl << "Массив после сортировки: ";
    for (int i = 0; i < size3; i++)
    {
        std::cout << arr3[i] << " ";
    }

}


