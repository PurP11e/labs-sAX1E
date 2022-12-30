#include <iostream>
#pragma once
#ifndef Matrix_Z352
#define Matrix_Z352

class Matrix
{
private:
	int row, col;

public:
	double* elem;
	
	//Конструкторы 
	Matrix();										//Конструктор по-умолчанию
	Matrix(int _row, int _col);						//Конструктор с двумя параметрами
	Matrix(const Matrix& temp);						//Конструктор копирования
	~Matrix();										//Конструктор, который нам память освобождает	


	//Наши методы
	void input();
	void input(int i, int j);
	void print();
	int matradd(double* elem, double* elem2, int _col, int _row);
	void mult_by_num(double num);
	int get_columns();
	int get_rows();
	int get_size();
	double get_elem(int i, int j);
	double trace(double* elem, int size);
};

#endif // !Matrix_Z352



