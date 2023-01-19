#pragma once
#include"Position.h"
class Square : virtual public Position {
protected:
	int size;
private:
	double Getradius() { return 0; };
public:
	Square();
	~Square();
	Square(int len);
	Square(int kx, int ky, int len);
	void print() override;
	void Set() override;
	void perimeter() override;
	void area() override;
	int Getx() override { return x; };
	int Gety() override { return y; };
	int Getsize() override { return size; };
};