#include <iostream>
#include <Math.h>

/*Написать класс матриц.

Свойства класса: число строк, число столбцов, одномерный динамический массив для хранения элементов.

Реализовать методы
matr* sum(const matr * mat2) или sum(const matr * mat2) - сложения матриц,
matr* mult(const matr * mat2) или void mult(const matr * mat2) - умножения двух матриц,
double trace() - след матрицы (сумма диагональных элементов квадратной матрицы),
double det() - определитель матрицы (для квадратных),
matr* mult_by_num(double num) или void mult_by_num(double num) - умножение матрицы на число,
void input() - ввести матрицу с клавиатуры,
void print() - печать матрицы в консоль,
int get_columns() - количество столбцов,
int get_rows() - количество строк
double get_elem(int i, int j) - вернуть (i,j) элемент */

class Matr {
public:
	Matr(int cols, int rows, const double* values) {//констуктор 
		this->cols = cols;
		this->rows = rows;
		this->values = new double[cols * rows];
		for (int i = 0; i < cols * rows; i++) {
			this->values[i] = values[i];
		}
	}
	//создает новый экземпляр класса и заполняют нужные поля
	Matr(int cols, int rows, const double initValue) {
		this->cols = cols;
		this->rows = rows;
		this->values = new double[cols * rows];
		for (int i = 0; i < cols * rows; i++) {
			this->values[i] = initValue;
		}
	}

	int get_columns() {
		return cols;
	}

	int get_rows() {
		return rows;
	}
		
	//возвращение элемента по номеру строки
	double get_elem(const int col, const int row) {
		return values[col * rows + row];
	}

	//установка значения в одну ячейку
	void set_elem(const int col, const int row, const double val) { 
		this->values[col * rows + row] = val;//с помощью выражения в квадратных скобок получаем индекс элемента в одномерном массиве
	}

	void input() {
		std::cout << "Введите " << rows * cols << " чисел через пробел. Сначала элементы первой колонки, затем - второй и так далее." << std::endl;

		for (int i = 0; i < cols * rows; i++) {
			std::cin >> this->values[i];
		}
	}

	void print() {
		std::cout << "Матрица:" << std::endl;

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				std::cout << this->get_elem(col, row) << '\t';//зис - обозначение текущего объекта
			}

			std::cout << std::endl;
		}
	}
	//функция возращает ссылку на новую матрицу
	Matr* sum(Matr* right_matr) {
		Matr* sum = new Matr(cols, rows, 0.0);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				//левая + правая матрица=отправляем полученное значение
				double newVal = this->get_elem(i, j) + right_matr->get_elem(i, j);
				sum->set_elem(i, j, newVal);
			}
		}
		//возвращает ссылку на матрицу
		return sum;
	}
	//умножение текущей матрицы слева и умножаем на правую
	Matr* mult(Matr* right_matr) {
		Matr* mult = new Matr(right_matr->get_columns(), this->get_rows(), 0.0);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < right_matr->get_columns(); j++)
			{
				double c = 0;
				for (int k = 0; k < this->get_columns(); k++) {
					c += this->get_elem(i, k) * right_matr->get_elem(k, j);
				}

				mult->set_elem(i, j, c);
			}
		}

		return mult;
	}
	//умножение матрицы на число
	Matr* mult_by_num(float num) {
		Matr* matr = new Matr(this->get_columns(), this->get_rows(), this->values);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				double newVal = matr->get_elem(i, j) * num;
				matr->set_elem(i, j, newVal);
			}
		}

		return matr;
	}
	//складывание диагоналей
	double trace() {
		float trace = 0;
		for (int i = 0; i < (this->get_columns(), this->get_rows()); i++) {
			trace += this->get_elem(i, i);
		}

		return trace;
	}

	double det() {//поле дет типа матр
		return Matr::det(this->get_columns(), this);
	}

	double det(int rank, Matr* matr) const {
		int det = 0;
		Matr* sub = new Matr(10, 10, 0.0);

		if (rank == 2) {
			return ((matr->get_elem(0, 0) * matr->get_elem(1, 1)) - (matr->get_elem(1, 0) * matr->get_elem(0, 1)));
		}
		else {
			for (int x = 0; x < rank; x++) {
				int subi = 0;
				for (int i = 1; i < rank; i++) {
					int subj = 0;
					for (int j = 0; j < rank; j++) {
						if (j == x)
							continue;
						sub->set_elem(subi, subj, matr->get_elem(i, j));
						subj++;
					}
					subi++;
				}
				det = det + (pow(-1, x) * matr->get_elem(0, x) * Matr::det(rank - 1, sub));
			}
		}

		return det;
	}

private:
	int cols, rows;
	double* values;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	//объявлем матрицу и ее строки и столбцы и заполняем
	Matr a(3, 3, 1), b(3, 3, 2);

	std::cout << "Матрица 1:" << std::endl;
	a.print();
	std::cout << "Матрица 2:" << std::endl;
	b.print();

	std::cout << "Сложение:" << std::endl;
	a.sum(&b)->print();

	std::cout << "Умножение:" << std::endl;
	a.mult(&b)->print();

	std::cout << "Умножение на 3.9:" << std::endl;
	a.mult_by_num(3.9)->print();

	std::cout << "След:" << std::endl;
	std::cout << a.trace();

	std::cout << "Детерминант:\t" << std::endl;
	std::cout << a.det();
}
