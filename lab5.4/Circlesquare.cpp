#include"Circlesquare.h"
#include<iostream>
Circlesquare::Circlesquare() {};
Circlesquare::~Circlesquare() {};
Circlesquare::Circlesquare(int len) {
	size = len; radius = size / 2.;
}
Circlesquare::Circlesquare(int kx, int ky, double r) {
	x = kx; y = ky; radius = r; size = radius * 2;
}
void Circlesquare::print() {
	this->::Square::print();
	this->::Circle::print();
}
void Circlesquare::Set() {
	std::cout << "¬ведите новые координаты:\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
	std::cout << "¬вести размер квадрата или радиус окружности?\n1 - размер квадрата\n2 - радиус окружности\n";
	int ans; std::cin >> ans;
	if (ans == 1) {
		std::cout << "size = "; std::cin >> size;
		radius = size / 2.;
	}
	else {
		std::cout << "radius = "; std::cin >> radius;
		size = radius * 2;
	}
}
void Circlesquare::perimeter() {
	this->::Square::perimeter();
	this->::Circle::perimeter();
}
void Circlesquare::area() {
	this->::Square::area();
	this->::Circle::area();
}