#include "Position.h"

void Position::setX(double x) {
	this->x = x; //обращение к свойству класса позитион, установка текущую координату х
}

void Position::setY(double y) {
	this->y = y;
}

//возвращает значение координат
double Position::getX() {
	return this->x;
}

double Position::getY() {
	return this->y;
}