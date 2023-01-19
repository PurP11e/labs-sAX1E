#include"Position.h"
#include<iostream>
Position::Position() {
	x = 0; y = 0;
}
Position::~Position() {}
Position::Position(int kz) {
	x = kz; y = kz;
}
Position::Position(int kx, int ky) {
	x = kx; y = ky;
}
void Position::print() {
	std::cout << "x = " << x << ", y = " << y << std::endl;
}
void Position::Set() {
	std::cout << "¬ведите новые координаты:\n";
	std::cout << "x = "; std::cin >> x;
	std::cout << "y = "; std::cin >> y;
}