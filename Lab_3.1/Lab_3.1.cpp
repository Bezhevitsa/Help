#include <iostream>


// Написать программу с меню, которая по запросу пользователя выполняет одно из следующих действий
// 1. Сортирует числовой массив(длины не более 1000) по возрастанию по алгоритму пузырьковой
// сортировки. Саму сортировку написать отдельной функцией. Массив, введенный
// пользователем передавать в функцию сортировки.
// 2. Сортирует символьный массив(буквы a - z) (длины не более 1000) по возрастанию по
// алгоритму сортировки подсчетом.Саму сортировку написать отдельной функцией.Массив,
// введенный пользователем передавать в функцию сортировки.
// 3. Сортирует числовой массив(длины не более 1000) по возрастанию по алгоритму сортировки
// слиянием.Саму сортировку написать отдельной функцией.Массив, введенный пользователем
// передавать в функцию сортировки.



void input_mas(int** mas, int* size, bool asChar = false) //асчар это буковка
{
	std::cout << "Введите длину массива:";
	std::cin >> *size;
	*mas = new int[*size]; //меняю указатель на мас
	for (int i = 0; i < *size; i++)
	{
		std::cout << "[" << i + 1 << "]" << ": ";

		if (!asChar) { //если буковка не буковка, то 
			std::cin >> (*mas)[i]; // Ввод с клавиатуры значение ячейки массива
		}
		else
		{
			char a{}; //коды символов в массив
			std::cin >> a;
			(*mas)[i] = a;
		}
	};
}


void print_mas(int* mas, int size, bool asChars = false)
{
	if (asChars) {//если да, то тогда фор. тру опускается
		for (int i = 0; i < size; i++)  //начало цикла
		{
			std::cout << "[" << i + 1 << "]: " << char(mas[i]) << "\n";
		}
	}
	else
	{
		for (int i = 0; i < size; i++)  //начало цикла
		{
			std::cout << "[" << i + 1 << "]: " << mas[i] << "\n";
		}
	}
}


void puzir(int* mas, int size)	//пузырьковая сортировка
{
	int b;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				b = mas[j];
				mas[j] = mas[j + 1]; // меняем местами
				mas[j + 1] = b; // значения элементов
			}
		}
	}
}


void countSortSymb(int* mas, int size) {//Пробегаем по всем элементам
	int min = 'a';
	int max = 'z';
	int* counts = new int[max] { 0 };//указываем на массив макс и заполняем его нуликами, выделяя ему еще и память
	for (int i = 0; i < size; i++) {
		int el = mas[i] - min;
		counts[el]++;
	}

	int Index = 0;
	for (int i = min; i <= max; i++) {
		for (int j = 0; j < counts[i]; j++) {
			mas[Index] = counts[i];
			Index++; //окончание сортировки
		}
	}
}


//функция, сливающая массивы
void Sort3sub(int* A, int first, int last) {
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;  //вычисление среднего элемента
	start = first;                //начало левой части
	final = middle + 1;           //начало правой части
	for (j = first; j <= last; j++)  //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
			mas[j] = A[start];
			start++;
		}
		else {
			mas[j] = A[final];
			final++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[] mas;
};

//рекурсивная процедура сортировки
void Sort3(int* A, int first, int last) {
	if (first < last) {
		Sort3(A, first, (first + last) / 2);  //сортировка левой части
		Sort3(A, (first + last) / 2 + 1, last);  //сортировка правой части
		Sort3sub(A, first, last);  //слияние двух частей
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int grade;
	int* mas;
	int size;

	do
	{
		std::cout << "Введите то, что вы хотите сделать, если \n 1 - Сортирует числовой массив(длины не более 1000) по возрастанию по алгоритму пузырьковой сортировки,\n";
		std::cout << " 2 - Сортирует символьный массив(буквы a - z) (длины не более 1000) по возрастанию по алгоритму сортировки подсчетом. \n";
		std::cout << " 3 - Сортирует числовой массив(длины не более 1000) по возрастанию по алгоритму сортировки слиянием.\n 4 - Выход \n";
		std::cin >> grade;
		switch (grade)
		{
		case 1:
			input_mas(&mas, &size);
			puzir(mas, size);
			print_mas(mas, size);
			break;
		case 2:
			input_mas(&mas, &size, true);
			puzir(mas, size); //вызов сортирующей процедуры
			print_mas(mas, size, true);
			break;
		case 3:
			input_mas(&mas, &size);
			Sort3(mas, 0, size - 1); //вызов сортирующей процедуры
			print_mas(mas, size);
			break;
		case 4:
			std::cout << "Выходим!\n"; //выход
			break;
		default:
			std::cout << "Упс! Следует выбирать только из численного диапазона 1-4.\n"; //ошибка
			break;

		}
	} while (grade != 4);
}