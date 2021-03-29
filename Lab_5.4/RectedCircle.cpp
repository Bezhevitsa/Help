#include "RectedCircle.h"

void RectedCircle::setRadius(double radius) {
	Circle::setRadius(radius);
	Rect::setWidth(radius*2);
}

double RectedCircle::setWidth(double width) {
	Circle::setRadius(radius/2);
	Rect::setWidth(radius);
}