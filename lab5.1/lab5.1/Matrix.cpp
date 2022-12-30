#include "Matrix.h"
#include <iostream>



Matrix::Matrix()
{
	row = 0;
	col = 0;
	elem = nullptr;
}

Matrix::Matrix(int _row, int _col)
{
	row = _row;
	col = _col;
	elem = new double[row * col];
}

Matrix::Matrix(const Matrix& temp)
{
	row = temp.row;
	col = temp.col;
	elem = new double[row * col];
	for (int i = 0; i < row * col; i++)
	{
		elem[i] = temp.elem[i];
	}
}

Matrix::~Matrix()
{
	if (elem != nullptr)
	{
		delete[] elem;
	}
}





void Matrix::input()
{
	std::cout << "Size of matrix: ";
	std::cin >> col >> row;
	elem = new double[(col) * (row)];
	std::cout << "Input elements:" << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Input " << "[" << i << "][" << j << "]: ";
			std::cin >> elem[i * col + j];
		}
	}
	std::cout << std::endl;
}

void Matrix::input(int i, int j)
{
	row = j;
	col = i;
	elem = new double[(col) * (row)];
	std::cout << "Input elements:" << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Input " << "[" << i << "][" << j << "]: ";
			std::cin >> elem[i * col + j];
		}
	}
	std::cout << std::endl;
}

void Matrix::print()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << elem[i * (col)+j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Matrix::matradd(double* elem1, double* elem2, int col1, int row2)
{
	if (col1 != row2) {
		std::cout << "The size of matrix must be the same.";
	}
	elem = new double[col1 * row2];
	col = col1; 
	row = row2;
	for (int i = 0; i < row2 * col1; i++)
	{
		elem[i] = elem1[i] + elem2[i];
	}
	return 0;
}

void Matrix::mult_by_num(double num)
{
	for (int i = 0; i < row * col; i++)
	{
		elem[i] = elem[i] * num;
	}
}

double Matrix::trace(double* elem, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + elem[i * size + i];
	}
	return sum;
}

int Matrix::get_columns()
{
	return col;
}

int Matrix::get_rows()
{
	return row;
}

int Matrix::get_size()
{
	return row * col;
}

double Matrix::get_elem(int i, int j)
{
	if (i >= 0 && j >= 0 && i < row && j < col)
	{
		return elem[i * col + j];
	}
}



