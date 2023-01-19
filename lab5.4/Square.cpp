#include"Square.h"
#include<iostream>
Square::Square() {
	size = 0;
}
Square::~Square() {}
Square::Square(int len) {
	size = len;
}
Square::Square(int kx, int ky, int len) {
	x = kx; y = ky; size = len;
}
void Square::print() {
	std::cout << "x = " << x << ", y = " << y << ", size = " << size << std::endl;

}
void Square::Set() {
	std::cout << "¬ведите новые координаты и размер:\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	std::cout << "size = "; std::cin >> size;
}
void Square::perimeter() {
	std::cout << " вадрат со стороной " << size << " и центом в точке с координатами (" << x << ", " << y << ")\n";
	std::cout << "≈го периметр = " << size * 4 << std::endl;
}
void Square::area() {
	std::cout << " вадрат со стороной " << size << " и центом в точке с координатами (" << x << ", " << y << ")\n";
	std::cout << "≈го площадь = " << size * size << std::endl;
}