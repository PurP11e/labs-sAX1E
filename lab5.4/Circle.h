#pragma once
#include"Position.h"
class Circle : virtual public Position {
protected:
	double radius;
private:
	int Getsize() override { return 0; };
public:
	Circle();
	~Circle();
	Circle(double r);
	Circle(int kx, int ky, double r);
	void print() override;
	void Set() override;
	void perimeter() override;
	void area() override;
	int Getx() override { return x; };
	int Gety() override { return y; };
	double Getradius() override { return radius; };
};