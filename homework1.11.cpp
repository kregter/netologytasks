#include <iostream>
#include <iomanip>
#include <windows.h>



int main()
{
    setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    //task 1.11.1
	std::cout << "Задача 1.11.1" << std::endl;
	std::string fnameFromConsole, snameFromConsole, sumOfStr;
	std::cout << "Введите имя: ";
	std::cin >> fnameFromConsole;
	std::cout << "Введите фамилию: ";
	std::cin >> snameFromConsole;
	sumOfStr = fnameFromConsole + " " + snameFromConsole;
	std::cout << "Здравствуйте, " << sumOfStr << "!";

	//task 1.11.2
	std::cout << std::endl << "Задача 1.11.2" << std::endl;
	std::string hiddenWord = "пирог", wordFromConsole;
	std::cout << "Добро пожаловать в игру угадайте слово. Загадано слово из 5 букв, вам предстоит его угадать." << std::endl;
	std::cout << "Угадайте слово: ";
	std::cin >> wordFromConsole;

	while (hiddenWord != wordFromConsole) {
		if (wordFromConsole.size() != 5)
		{
			std::cout << "Ошибка! Введите слово из 5 букв!";
		}
		else
		{
			std::string guessedLetters = "";
			for (int i = 0; hiddenWord[i] != '\0'; i++)
			{
				for (int j = 0; wordFromConsole[j] != '\0'; j++)
				{
					if (hiddenWord[i] == wordFromConsole[j] && (guessedLetters.find(hiddenWord[i]) > guessedLetters.size()))
					{
						guessedLetters += wordFromConsole[j];
					}
				}
			}
			std::cout << "Угаданные вами буквы в слове: " << guessedLetters;
		}
		std::cout << std::endl << "Угадайте слово: ";
		std::cin >> wordFromConsole;
	}
	std::cout << "Правильно! Вы победили! Загадонное слово - " << hiddenWord;

	return 0;
	
}


