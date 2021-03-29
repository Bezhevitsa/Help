#include <iostream>
#include "TriMatr.h"
/*Написать класс трехдиагональных  матриц 
(элементы отличны от нуля на главной диагонали,
над ней и под ней, т.е. a[ i, i] != 0, a[ i, i-1] != 0, a[ i-1, i] != 0)
с методами tr(след матрицы - сумма диагональных элементов), det (определитель), 
input (ввод матрицы), print( печать), columns (количество столбцов),
rows (количество строк) и перегрузить операторы >>, <<, +, - (бинарный и унарный),
* (бинарный и унарный = умножение на число).*/
int main()
{
	setlocale(LC_ALL, "Russian");

	TriMatr* a = new TriMatr(), * b = new TriMatr();

	a->input();
	b->input();

	std::cout << "Матрица 1:" << std::endl;
	a->print();
	std::cout << "Матрица 2:" << std::endl;
	b->print();

	std::cout << "Сложение:" << std::endl;
	(*a + *b)->print();

	std::cout << "Умножение:" << std::endl;
	(*a * *b)->print();

	std::cout << "Умножение на 3.9:" << std::endl;
	(*a * 3.9)->print();

	std::cout << "След:" << std::endl;
	std::cout << a->tr();

	std::cout << "Детерминант:" << std::endl;
	std::cout << a->det();
}
