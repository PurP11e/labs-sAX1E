#pragma once
class Position {
protected:
	int x;
	int y;
private:
	virtual void perimeter() {};
	virtual void area() {};
	virtual int Getsize() { return 0; };
	virtual double Getradius() { return 0; };
public:
	Position();
	~Position();
	Position(int kz);
	Position(int kx, int ky);
	virtual void print();
	virtual void Set();
	virtual int Getx() { return x; };
	virtual int Gety() { return y; };
};