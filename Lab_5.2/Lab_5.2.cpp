#include <iostream>
#include <Math.h>

/*Перегрузка функций собственного класса.
Перегрузить методы класса матриц.

matr(int i, int j);
matr(int i, int j, const double * arr);

matr* sum(const double * arr) или sum(const double * arr) - сложения матриц,

matr* mult(const double * arr) или void mult(const double * arr) - умножения двух матриц,
void input(int i, int j) - ввести матрицу с клавиатуры c заданными размерами,
void input(int i, int j, double * arr) - инициализировать матрицу заданным массивом*/
class Matr {
public:
	Matr(int cols, int rows, const double* values) {
		this->cols = cols;
		this->rows = rows;
		this->values = new double[cols * rows];
		for (int i = 0; i < cols * rows; i++) {
			this->values[i] = values[i];
		}
	}

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

	double get_elem(const int col, const int row) {
		return values[col * rows + row];
	}

	void set_elem(const int col, const int row, const double val) {
		this->values[col * rows + row] = val;
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
				std::cout << this->get_elem(col, row) << '\t';
			}

			std::cout << std::endl;
		}
	}

	Matr* sum(Matr* right_matr) {
		Matr* sum = new Matr(cols, rows, 0.0);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				double newVal = this->get_elem(i, j) + right_matr->get_elem(i, j);
				sum->set_elem(i, j, newVal);
			}
		}

		return sum;
	}

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

	double trace() {
		float trace = 0;
		for (int i = 0; i < (this->get_columns(), this->get_rows()); i++) {
			trace += this->get_elem(i, i);
		}

		return trace;
	}

	double det() {
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

	// ЛБ 2
	Matr(int cols, int rows) {
		Matr(cols, rows, 0.0);
	}

	Matr* sum(double* right_matr) {
		Matr* m2 = new Matr(cols, rows, right_matr);
		return this->sum(m2);
	}

	Matr* mult(double* right_matr) {
		Matr* m2 = new Matr(this->get_columns(), this->get_rows(), right_matr);
		return this->mult(m2);
	}

	void input(int cols, int rows) {
		this->cols = cols;
		this->rows = rows;
		std::cout << "Введите " << rows * cols << " чисел через пробел. Сначала элементы первой колонки, затем - второй и так далее." << std::endl;

		for (int i = 0; i < cols * rows; i++) {
			std::cin >> this->values[i];
		}
	}

	void input(int cols, int rows, double* values) {
		this->cols = cols;
		this->rows = rows;
		this->values = values;
	}

private:
	int cols, rows;
	double* values;
};


int main()
{
	setlocale(LC_ALL, "Russian");

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

	std::cout << "Детерминант:" << std::endl;
	std::cout << a.det();
}