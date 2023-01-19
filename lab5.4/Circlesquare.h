#pragma once
#include"Circle.h"
#include"Square.h"
class Circlesquare : public Square, public Circle {
public:
	Circlesquare();
	~Circlesquare();
	Circlesquare(int len);
	Circlesquare(int kx, int ky, double r);
	void print() override;
	void Set() override;
	void perimeter() override;
	void area() override;
	int Getx() override { return x; };
	int Gety() override { return y; };
	int Getsize() override { return size; };
	double Getradius() override { return radius; };
};