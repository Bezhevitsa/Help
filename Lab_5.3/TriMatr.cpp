#pragma once
#include "TriMatr.h"
#include <iostream>

TriMatr::TriMatr() : Matr(0, 0)
{
}

float TriMatr::tr() {
	return this->trace();
}

void TriMatr::input()
{
	int diag;
	std::cout << "Введите разрядность матрицы: ";
	std::cin >> diag;
	Matr::input(diag, diag, new double[diag * diag]{ 0 });

	std::cout << "Введите элементы верхней побочной диагонали (" << diag - 1 << " чисел):";
	for (int i = 0; i < diag - 1; i++) {
		float val;
		std::cin >> val;
		Matr::set_elem(i + 1, i, val);
	}

	std::cout << "Введите элементы главной диагонали (" << diag << " чисел):";
	for (int i = 0; i < diag; i++) {
		float val;
		std::cin >> val;
		Matr::set_elem(i, i, val);
	}

	std::cout << "Введите элементы нижней побочной диагонали (" << diag - 1 << " чисел):";
	for (int i = 0; i < diag - 1; i++) {
		float val;
		std::cin >> val;
		Matr::set_elem(i, i + 1, val);
	}
}

void TriMatr::print()
{
	Matr::print();
}

int TriMatr::columns()
{
	return Matr::get_columns();
}

int TriMatr::rows()
{
	return Matr::get_rows();
}

TriMatr* TriMatr::operator+(TriMatr matr)
{
	Matr* newMatr = sum(&matr);
	return new TriMatr(newMatr);
}

TriMatr* TriMatr::operator*(float n)
{
	Matr* newMatr = mult_by_num(n);
	return new TriMatr(newMatr);
}

TriMatr* TriMatr::operator-(TriMatr matr)
{
	Matr* newMatr = sum(-matr);
	return new TriMatr(newMatr);
}

TriMatr* TriMatr::operator-()
{
	Matr* newMatr = mult_by_num(-1);
	return new TriMatr(newMatr);
}

TriMatr* TriMatr::operator>>(std::string str)
{
	// заглушка
	return nullptr;
}

std::string TriMatr::operator<<(TriMatr matr)
{
	std::string output = "<TriMatrix " + std::to_string(columns()) + "x" + std::to_string(rows()) + ">";
	return output;
}

TriMatr* TriMatr::operator*(TriMatr matr)
{
	Matr* newMatr = mult(&matr);
	return new TriMatr(newMatr);
}

TriMatr::TriMatr(Matr* matr) : Matr(*matr)
{
}

