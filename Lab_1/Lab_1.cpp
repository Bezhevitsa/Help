// Lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std; //избавление от необходимости прописывать std::cout
	cout << "1.\n";
	cout << "Solozhentseva Alina Alekseevna, 201-352\n";//вывод первого задания

	//вывод второго задания
	cout << "2.\n";
	cout << "min int = -2147483648, max int = 2147483647, size of int = 4 байта\n";
	cout << "min unsigned int = 0, max unsigned int =  4 294 967 295, size of unsigned int = 4 байта\n";
	cout << "min short = -32 768, max short = 32 767, size of short = 2 байта\n";
	cout << "min unsigned short = 0, max unsigned short =  65 535, size of unsigned short = 2 байта\n";
	cout << "min long = -2 147 483 648 , max long = 2 147 483 647 , size of long = 4 байта\n";
	cout << "min long long = -9 223 372 036 854 775 808, max long long = -9 223 372 036 854 775 807, size of long long = 8 байт\n";
	cout << "min double = -9 223 372 036 854 775 808 .0, max double = 9 223 372 036 854 775 807 .0, size of double = 8 байт\n";
	cout << "min char = -128, max char = 127, size of char = 1 байт\n";
	cout << "min bool = false, max bool = true, size of bool = 1 байт\n";

	cout << "3.\n";
	cout << "Введите число:\n";
	int chislo;
	cin >> chislo;
	int res = 0;
	int chislo2 = chislo;//костыль, чтобы использовать манипулятор hex
	cout << "В шестнадцатиричном виде:" << hex/*преобразование десятичного числа в шестнадцатеричное*/ << chislo2 << "\n";
	cout << "int:" << int(chislo) << "\n";
	cout << "unsigned int:" << unsigned int(chislo) << "\n";
	cout << "short:" << short(chislo) << "\n";
	cout << "unsigned short:" << unsigned short(chislo) << "\n";
	cout << "long:" << long(chislo) << "\n";
	cout << "long long:" <<  long long (chislo) << "\n";
	cout << "bool:" << bool(chislo) << "\n";
	cout << "double:" << double(chislo) << "\n";
	cout << "char:" << char(chislo) << "\n";
	cout << "В бинарном виде:";
	for (int i = 7; i >= 0; i--)
	{		if (chislo & (1 << i))
				cout << "1";
			else
		cout << "0";
	}

	cout << "\n";
	cout << "4.\n";
	cout << "Ведите коэффиценты а*х=b:\n";
	double a, b;
	cin >> a;
	cin >> b;
	cout << a << "  * x =" << b << "\n";
	cout << "x = " << b << "/" << a << "\n";
	cout << "x = " << b/a << "\n";
	cout << "Ответ:" << b/a<< "\n";


	cout << "5.\n";
	cout << "Введите координаты отрезка на прямой:\n";
	double k1, k2;
	cin >> k1;
	cin >> k2;
	int k12 = (k1 + k2) / 2;
	cout << "Середина отрезка находится в точке с координатой " << k12 << "\n";

}

