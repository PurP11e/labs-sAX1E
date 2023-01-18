#pragma once
#include<iostream>
class Matrix {
private:
	int size;
	int* mat;
public:
	Matrix();
	Matrix(int len);
	Matrix(const Matrix& other);
	~Matrix();

	int get_elem(int i, int j);
	void input();
	void input(int len);
	void print();
	int get_columns();

	int trace();
	void shiftmat(Matrix& addmat, int index);
	int det();
	Matrix sum(const Matrix mat2);
	Matrix mult(const Matrix mat2);
	Matrix mult_by_num(Matrix mat1, int num);

	friend Matrix operator +(Matrix mat1, Matrix mat2);
	friend Matrix operator -(Matrix mat1, Matrix mat2);
	Matrix operator -();
	friend Matrix operator *(Matrix mat1, Matrix mat2);
	friend Matrix operator *(Matrix mat1, int m);
	void operator +=(const Matrix mat2);
	void operator -=(const Matrix mat2);
	friend std::ostream& operator <<(std::ostream& out, Matrix mat1);
	friend std::istream& operator >>(std::istream& in, Matrix& mat1);
};
Matrix operator +(Matrix mat1, Matrix mat2);
Matrix operator -(Matrix mat1, Matrix mat2);
Matrix operator *(Matrix mat1, Matrix mat2);
Matrix operator *(Matrix mat1, int m);
std::ostream& operator <<(std::ostream& out, Matrix mat1);
std::istream& operator >>(std::istream& in, Matrix& mat1);