#include"Circle.h"
#include<iostream>
Circle::Circle() {
	radius = 0;
}
Circle::~Circle() {};
Circle::Circle(double r) {
	radius = r;
}
Circle::Circle(int kx, int ky, double r) {
	x = kx; y = ky; radius = r;
}
void Circle::print() {
	std::cout << "x = " << x << ", y = " << y << ", radius = " << radius << std::endl;

}
void Circle::Set() {
	std::cout << "Введите новые координаты и радиус:\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	std::cout << "radius = "; std::cin >> radius;
}
void Circle::perimeter() {
	std::cout << "Окружность с радиусом " << radius << " и центом в точке с координатами (" << x << ", " << y << ")\n";
	std::cout << "Её периметр = " << 6.28 * radius << std::endl;
}
void Circle::area() {
	std::cout << "Окружность с радиусом " << radius << " и центом в точке с координатами (" << x << ", " << y << ")\n";
	std::cout << "Её площадь = " << 3.14 * radius * radius << std::endl;
}