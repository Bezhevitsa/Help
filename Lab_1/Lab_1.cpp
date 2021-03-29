
#include <iostream> //и ауе стрим
#include <bitset>


#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <ctype.h>
using namespace std;
void readStr(char input[255], const char* text) {
	cout << text << "\n";
	cin.getline(input, 255);//считывание массива символов(строки!!)
}

void task1() {
	cout << "Введите слово\n";
	string str1 = "";
	cin >> str1;
	int d = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str1[str1.length() - 1 - i]) {
			d++;
		}
	}
	if (d == str1.length())
		cout << "yes\n\n";
	else
		cout << "no\n\n";
};


void encrypt(char* str_for_encrypt, int key) {
	char ch;
	for (int i = 0; str_for_encrypt[i] != '\0'; ++i) {
		ch = str_for_encrypt[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			str_for_encrypt[i] = ch;
		}

		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			str_for_encrypt[i] = ch;
		}
	}
};


int main()
 {
	setlocale(0, "");
	cout << "Выберите действие:\n";
	int p = 0;
	char mainStr[255];
	while (true) {
		cout << "1.Проверить на полиндром\n"
			<< "2.Шифр цезаря\n"
			<< "3.Текст в тексте\n"
			<< "4.Выход\n";
		cin >> p;

		switch (p) {
		case 1:
			task1();
			break;
		case 2:
			readStr(mainStr, "Введите строку, которую нужно зашифровать:");
			cout << "Введите ключ (число): \n";
			int key;
			cin >> key;
			encrypt(mainStr, key);

			cout << mainStr << '\n';
			break;
		default:
			cout << "Введите ключ (число): \n";

			break;


		}

	}
}

/*int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std; //избавление от необходимости прописывать std::cout
	cout << "1.\n";
	cout << "Solozhentseva Alina Alekseevna, 201-352\n";//вывод первого задания

	//вывод второго задания
	cout << "2.\n";
	cout << "min int =" << INT_MIN << ", max int = " << INT_MAX << ", size of int = " << sizeof(int) << "\n";
	cout << "min unsigned int =" << 0 << ", max unsigned int =" << UINT_MAX << " , size of unsigned int = " << sizeof(unsigned int) << "\n";
	cout << "min short =" << SHRT_MIN << ", max short =" << SHRT_MAX << ", size of short =" << sizeof(short) << "\n";
	cout << "min unsigned short =" << 0 << ", max unsigned short = " << USHRT_MAX << ", size of unsigned short =" << sizeof(unsigned short) << "\n";
	cout << "min long =" << LONG_MIN << ", max long =" << LONG_MAX << ", size of long =" << sizeof(long) << "\n";
	cout << "min long long =" << LLONG_MIN << " , max long long = " << LLONG_MAX << ", size of long long =" << sizeof(long long) << "\n";
	cout << "min double =" << DBL_MIN << ", max double = " << DBL_MAX << " , size of double =" << sizeof(double) << "\n";
	cout << "min char =" << CHAR_MIN << ", max char =" << CHAR_MAX << ", size of char = " << sizeof(char) << "\n";
	cout << "min bool =" << 0 << ", max bool =" << 1 << " , size of bool = " << sizeof(bool) << "\n";

	cout << "3.\n"; //вывод третьего задания
	cout << "Введите число:\n";
	int chislo;
	cin >> chislo;
	int res = 0;
	int chislo2 = chislo;
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
	cout << "В бинарном виде:" << bitset<16>(chislo) << "\n";
	

	cout << "\n";
	cout << "4.\n"; //вывод четвертого задания
	cout << "Ведите коэффиценты а*х=b:\n";
	int a, b;
	cin >> a;
	cin >> b;
	cout << a << "  * x =" << b << "\n";
	cout << "x = " << b << "/" << a << "\n";
	cout << "x = " << double(b/a) << "\n";
	cout << "Ответ:" << double(b/a)<< "\n";


	cout << "5.\n"; //вывод пятого задания
	cout << "Введите координаты отрезка на прямой:\n";
	int k1, k2;
	cin >> k1;
	cin >> k2;
	double k12 = (k1 + k2) / 2;
	cout << "Середина отрезка находится в точке с координатой " << k12 << "\n";

}
*/
