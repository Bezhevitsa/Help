#include <iostream>
/*
"\n Введите то, что вы хотите сделать: \n";
		cout << " 1 - Проверка на палиндром \n";
		cout << " 2 - Поиск подстроки в строке \n";
		cout << " 3 - Шифрование сдвигами \n";
		cout << " 4 - Выделение названий \n";
		cout << " 5 - Выйти \n";
*/

using namespace std;//знаю, что незя

void readStr(char input[255], const char* text) {
	cout << text << "\n";
	cin.getline(input, 255);//считывание массива символов(строки!!)
}

bool checkPal(char* str) {
	int length = strlen(str);
	int i1 = 0, i2 = length - 1;
	bool isPal = true;
	while (isPal && i1 < i2) {//пока не дойдем до середины 
		if (str[i1] != ' ' && str[i2] != ' ') 
		{
			isPal = tolower(str[i1]) == tolower(str[i2]);//меняем заглавные на незаглавные и наоборот
			i1++;
			i2--;
		}
		else if (str[i1] == ' ') 
		{
			i1++;
		}
		else if (str[i2] == ' ') 
		{
			i2--;
		}
	}

	return isPal;
}

//проверяет является ли часть строки первого аргумента начиная с n строкой переданной вторым аргументом
bool isSubstrAtN(const char* str_for_search_in, const char* substring, int n) {
	int len1 = strlen(str_for_search_in); //функция подсчета длины строки
	int len2 = strlen(substring);

	if (len1 - n < len2) {//если длина строки не совпадает после n, то все, конец
		return false;
	}

	for (int i = 0; i < len2; i++) {
		if (str_for_search_in[n + i] != substring[i]) {
			return false;
		}
	}

	return true;
}

//ищет номер первого символа подстроки в основной строке начиная со стартовой позиции переданной третьим аргументом
int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {//проходим по всей строке
	int len1 = strlen(str_for_search_in);
	int len2 = strlen(substring);
	for (int i1 = start_position; i1 < len1; i1++) {
		if (isSubstrAtN(str_for_search_in, substring, i1)) { //сравнивает подстроку основной строки начиная с символа n с переданной строкой
			return i1;
		}
	}

	return -1;//если не нашли строку, то -1
}
//ищет все подстроки
void find_substring2(const char* str_for_search_in, const char* substring) {//* -- несколько символов строка
	int len1 = strlen(str_for_search_in);// находим длину строки 
	int len2 = strlen(substring);

	cout << "[ ";
	for (int i1 = 0; i1 < len1; i1++) {
		if (isSubstrAtN(str_for_search_in, substring, i1)) {
			cout << i1 << " ";
		}
	}

	cout << "] \n";
}
//шифрование
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
}
//выделение названий
void findNames(const char* str) {
	int len = strlen(str);
	int i = 0;
	while (i < len) {
		int q1 = find_substring1(str, "\"", i);//номер символа первой кавычки
		int q2 = find_substring1(str, "\"", q1 + 1);
		if (q1 == -1 || q2 == -1) {//проверка на кавычки!!
			break;
		}

		for (int j = q1 + 1; j < q2; j++) {
			cout << str[j];//выходят все буковки в кавычках 
		}
		i = q2 + 1;
		cout << "; ";
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int grade;
	char mainStr[255], argStr[255]; // две строки, массив символов 
	//char* a; - динамическая, просто для примера
	do
	{
		cout << "\n Введите то, что вы хотите сделать: \n";
		cout << " 1 - Проверка на палиндром \n";
		cout << " 2 - Поиск подстроки в строке \n";
		cout << " 3 - Шифрование сдвигами \n";
		cout << " 4 - Выделение названий \n";
		cout << " 5 - Выйти \n";
		cin >> grade;
		cin.ignore();
		switch (grade)
		{
		case 1:
			readStr(mainStr, "Введите строку, палиндромность которой нужно проверить:");

			if (checkPal(mainStr) == true)
			{
				cout << "Это палиндром \n";
			}
			else
			{
				cout << "Это не палиндром \n";
			}
			break;

		case 2:
			readStr(mainStr, "Введите строку, в которой нужно искать:");
			readStr(argStr, "Введите строку, которую нужно искать:");

			find_substring2(mainStr, argStr);

			break;
		case 3:
			readStr(mainStr, "Введите строку, которую нужно зашифровать:");

			cout << "Введите ключ (число): \n";
			int key;
			cin >> key;
			encrypt(mainStr, key);

			cout << mainStr << '\n';

			break;
		case 4:
			readStr(mainStr, "Введите строку, в которой нужно найти названия:");

			findNames(mainStr);

			break;
		case 5:
			cout << "Выходим!\n"; //выход
			break;
		default:
			cout << "Упс! Следует выбирать только из численного диапазона 1-5.\n"; //ошибка
			break;
		}
	} while (grade != 5);
	return 0;
}
