#include "Circle.h"
/*Написать класс Position, задающий положение фигуры.
Написать классы окружность и квадрат  как наследники Position. 
Написать класс ОкружностьВКвадрате.*/
void Circle::setRadius(double radius) {
    this->radius = radius;
}

double Circle::getRadius() {
    return this->radius;
}