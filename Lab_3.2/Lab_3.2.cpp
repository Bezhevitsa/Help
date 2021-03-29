#include <iostream>
/*
1. Ввод массива
2. Вывод массива в консоль
3. Сортировка по сумме цифр, стоящих на четных местах
4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних
цифр - по убыванию.
5. выход
*/


void input_mas(int** mas, int* size)
{
	std::cout << "Введите длину массива:";
	std::cin >> *size;
	*mas = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		std::cout << "[" << i + 1 << "]" << ": ";

		std::cin >> (*mas)[i]; // Ввод с клавиатуры значение ячейки массива
	};
}


void print_mas(int* mas, int size)
{
	for (int i = 0; i < size; i++)  //начало цикла
	{
		std::cout << "[" << i + 1 << "]: " << mas[i] << "\n";
	}
}


bool SortByValue(int a, int b) {
	return a > b;
}

// Сортировка по сумме цифр, стоящих на четных местах.
bool SortBySum(int a, int b) {
	int sum1 = 0, sum2 = 0;
	int num1 = a, num2 = b;

	num1 /= 10;
	num2 /= 10;
	while (num1 != 0 || num2 != 0) {
		sum1 += num1 % 10;
		sum2 += num2 % 10;

		num1 /= 100;
		num2 /= 100;
	}

	return sum1 > sum2;
}

// Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию.
bool SortByLastAndNotLast(int a, int b) {
	if (a % 10 > b % 10) {
		return true;
	}

	if (a % 10 == b % 10) {
		return SortByValue(a, b);
	}

	return false;
}

void puzir(int* mas, int size, bool (*isFirstGreather)(int, int))	//пузырьковая сортировка
{
	int b;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (isFirstGreather(mas[j], mas[j + 1])) {
				b = mas[j];
				mas[j] = mas[j + 1]; // меняем местами
				mas[j + 1] = b; // значения элементов
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	bool isArrayExists = false;
	int grade;
	int* mas = nullptr;
	int size;

	do
	{
		std::cout << "Введите то, что вы хотите сделать: \n";
		std::cout << " 1 - Ввести массив \n";
		std::cout << " 2 - Вывести массив \n";
		std::cout << " 3 - Сортировка по сумме цифр, стоящих на четных местах \n";
		std::cout << " 4 - Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию \n";
		std::cout << " 5 - Выйти \n";
		std::cin >> grade;
		switch (grade)
		{
		case 1:
			input_mas(&mas, &size);
			isArrayExists = true;
			break;
		case 2:
			if (!isArrayExists)
			{
				std::cout << "Массив не введен! \n";
			}
			else
			{
				print_mas(mas, size);
			}
			break;
		case 3:
			if (!isArrayExists)
			{
				std::cout << "Массив не введен! \n";
			}
			else
			{
				puzir(mas, size, &SortBySum);
			}
			break;
		case 4:
			if (!isArrayExists)
			{
				std::cout << "Массив не введен! \n";
			}
			else
			{
				puzir(mas, size, &SortByLastAndNotLast);
			}
			break;
		case 5:
			std::cout << "Выходим!\n"; //выход
			break;
		default:
			std::cout << "Упс! Следует выбирать только из численного диапазона 1-4.\n"; //ошибка
			break;
		}
	} while (grade != 5);
}
