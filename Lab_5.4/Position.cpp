#include "Position.h"

void Position::setX(double x) {
	this->x = x; //��������� � �������� ������ ��������, ��������� ������� ���������� �
}

void Position::setY(double y) {
	this->y = y;
}

//���������� �������� ���������
double Position::getX() {
	return this->x;
}

double Position::getY() {
	return this->y;
}