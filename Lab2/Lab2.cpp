// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

//функция для решения задачи 1
void task1()
{
	int chislo = 0;
	int chislo1;
	cout << "Введите число, до которого будет треугольник...";
	cin >> chislo1;
	for (int i = 0; i <= chislo1; i++)
	{
		for (int j = 0; j <= chislo1; j++)
		{
			if (i >= j)
				cout << j;
			
		}
		cout << "\n";
	}
	cout << "\n";
	
}

void task2()
{
	int chislo;
	int fact;
	cout << "Введите число для биномиальных коэффицентов\n";
	cin >> chislo;
	fact = chislo;
	for (int i = 1; i <= chislo; i++)
	{
		cout << fact << "\n";
		fact *= (chislo - i);
		fact /= (i + 1);
	}
}

void sort_slin()
{
	int sum = 0;
	int chet = 0;
	string stop;
	string chisla;
	cout << "Введите слово, на котором хотите остановиться...";
	cin >> stop;
	cout << "Введите числа на прямой\n";
	while(true)
	{
		cin >> chisla;
		if (stop != chisla)
		{
			sum += stoi(chisla);
			chet++;
		}
		else
		{
			cout << "Среднее арифметическое: " << double(sum) / chet << "\n";
			break;
		}
	}
	
}

int main()
{   setlocale(LC_ALL, "Russian");
	int grade;
    do
	{
		std::cout << "Введите то, что вы хотите сделать, если \n 1 - числовой треугольник,\n 2 - Нахождение биномиальных коэффициентов,\n";
		cout << " 3 - Вычисление среднего арифметического введенных точек на прямой,\n заданных своими координатами,\n 4 - Выход \n";
		cin >> grade;
		switch (grade) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			sort_slin();
			break;
		case 4:
			std::cout << "Выходим!\n"; //выход
			break;
		default:
			std::cout << "Упс! Следует выбирать только из численного диапазона 1-4.\n"; //ошибка
			//return 0;
			break;

		}
	} 
	while (grade != 4);

}

