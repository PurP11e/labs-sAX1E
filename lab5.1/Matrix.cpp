#include"Matrix.h"
#include<iostream>
Matrix::Matrix(int rows, int cols) {
	if (mat != nullptr) { delete[]mat; }
	row = rows; col = cols;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = 0;
	}
}
Matrix::Matrix(int size) {
	row = size; col = size;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = 0;
	}
}
Matrix::Matrix() {
	row = 0; col = 0;
	mat = nullptr;
}
Matrix::Matrix(const Matrix& other) {
	this->row = other.row; this->col = other.col;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		this->mat[i] = other.mat[i];
	}
}
Matrix::~Matrix() {
	if (mat != nullptr) { delete[]mat; }
}

void Matrix::input(int rows, int cols) {
	row = rows; col = cols;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		std::cout << i + 1 << " элемент>";
		std::cin >> mat[i];
	}
}
void Matrix::input(int rows, int cols, double* mas) {
	row = rows; col = cols;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = mas[i];
	}
}
void Matrix::randinput(int rows, int cols) {
	row = rows; col = cols;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = rand() % 100;
	}
}
void Matrix::print() {
	int k = 0;
	for (int i = 0; i < row * col; i++) {
		if (k == col) {
			std::cout << "\n";
			k = 0;
		}
		std::cout << mat[i] << "\t";
		k++;
	}
	std::cout << "\n";
}
void Matrix::createmat(int rows, int cols) {
	row = rows; col = cols;
	std::cout << "Ввести случайную матрицу или ввести вручную: \n";
	std::cout << "1 - случайная матрица\n2 - вручную\n";
	int ans; std::cin >> ans;
	if (ans == 1) {
		this->randinput(row, col);
	}
	else {
		this->input(row, col);
	}
}
int Matrix::get_columns() {
	return col;
}
int Matrix::get_rows() {
	return row;
}
double Matrix::get_elem(int i, int j) {
	return mat[i * col + j];
}
bool Matrix::check_null(const Matrix& mat2) {
	if (this->col != mat2.row) { return false; }
	else { return true; }
}

Matrix Matrix::sum(const Matrix mat2) {
	//!!!!!!!!!!!!!!!!!
	Matrix mat3(row, col);
	if (this->row != mat2.row or this->col != mat2.col) {
		std::cout << "Для выполнения сложения матрицы должны быть одинакового размера\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.row << ", " << mat2.col << ")";
		return mat3;
	}
	for (int i = 0; i < row * col; i++) {
		mat3.mat[i] = mat[i] + mat2.mat[i];
	}
	std::cout << "Сумма матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::sum(double* mas, int size) {
	Matrix mat3(row, col);
	if (this->row != size or this->col != size) {
		std::cout << "Для выполнения сложения матрицы должны быть одинакового размера\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << size << ", " << size << ")";
		return mat3;
	}
	for (int i = 0; i < row * col; i++) {
		mat3.mat[i] = mat[i] + mas[i];
	}
	std::cout << "Сумма матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult(const Matrix mat2) {
	//!!!!!!!!!!!!!!!!!
	Matrix mat3(row, mat2.col);
	if (this->col != mat2.row) {
		std::cout << "Для умножения матриц кол-во колонок первой должно быть равно кол-ву строк второй\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.row << ", " << mat2.col << ")";
		return mat3;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < mat2.col; j++) {
			for (int k = 0; k < mat2.row; k++) {
				mat3.mat[i * mat2.col + j] += this->get_elem(i, k) * mat2.mat[k * mat2.col + j];
			}
		}
	}
	std::cout << "Произведение матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult(double* mas, int size) {
	Matrix mat3(row, size);
	if (this->col != size) {
		std::cout << "Для умножения матриц кол-во колонок первой должно быть равно кол-ву строк второй\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << size << ", " << size << ")";
		return mat3;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				mat3.mat[i * size + j] += this->get_elem(i, k) * mas[k * size + j];
			}
		}
	}
	std::cout << "Произведение матриц: \n";
	mat3.print();
	return mat3;
}
void Matrix::shiftmat(Matrix& addmat, int index) {
	int ki = 0;
	int size = this->row;
	for (int i = 1; i < size; i++) {
		for (int j = 0, kj = 0; j < size; j++) {
			if (j != index) {
				addmat.mat[ki * addmat.row + kj] = this->mat[i * size + j];
				kj++;
			}
		}
		ki++;
	}
}
double Matrix::det(int &a) {
	//!!!!!!!!!!!!!!!!!
	if (row != col) {
		std::cout << "Нельзя найти определитель\nМатрица должна быть квадратной\n";
		return -1;
	}
	int f = a;
	double opred = 0;
	int size = this->row;
	int k = 1;
	if (size < 1) { return 0; }
	else if (size == 1) { opred = mat[0]; }
	else if (size == 2) { opred = mat[0] * mat[3] - mat[1] * mat[2]; }
	else {
		for (int i = 0; i < size; i++) {
			f++;
			int m = size - 1;
			Matrix addmat(m);
			this->shiftmat(addmat, i);
			opred = opred + k * this->mat[i] * addmat.det(f);
			k = -k;
		}
	}
	if (row == a) {
		std::cout << "первая матрица:\n";
		this->print();
		std::cout << "\nОпределитель: " << opred << "\n";
		return 0;
	}
	else {
		return opred;
	}
}
double Matrix::trace() {
	//!!!!!!!!!!!!!!!!!
	if (row != col) {
		std::cout << "Нельзя найти след\nМатрица должна быть квадратной\n";
		return 0;
	}
	double summ = 0; int flag = row % 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j or (i + j) == row - 1) {
				summ += this->get_elem(i, j);
			}
		}
	}
	std::cout << "первая матрица:\n";
	this->print();
	std::cout << "След: " << summ << "\n";
	return 0;
}
Matrix Matrix::mult_by_num(double num) {
	Matrix mat3(row, col);
	for (int i = 0; i < row * col; i++) { mat3.mat[i] = mat[i] * num; }
	return mat3;
}