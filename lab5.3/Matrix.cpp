#include"Matrix.h"
#include<iostream>
Matrix::Matrix() {
	size = 0;
	mat = nullptr;
}
Matrix::Matrix(int len) {
	size = len;
	if (mat != nullptr) { delete[]mat; }
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		mat[i] = 0;
	}
}
Matrix::Matrix(const Matrix& other) {
	this->size = other.size;
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		this->mat[i] = other.mat[i];
	}
}
Matrix::~Matrix() {
	if (mat != nullptr) { delete[]mat; }
}

int Matrix::get_elem(int i, int j) {
	return mat[i * size + j];
}
void Matrix::input() {
	std::cout << "Введите размер матрицы: ";
	std::cin >> size;
	if (mat != nullptr) { delete[]mat; }
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		mat[i] = 0;
	}
	mat[0] = rand() % 100 - 50;
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (i == j) {
				mat[i * size + j] = rand() % 100 - 50;
				mat[i * size + j - 1] = rand() % 100 - 50;
				mat[(i - 1) * size + j] = rand() % 100 - 50;
			}
		}
	}
}
void Matrix::input(int len) {
	size = len;
	if (mat != nullptr) { delete[]mat; }
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		mat[i] = 0;
	}
	int k = 1;
	std::cout << k++ << " элемент>";
	std::cin >> mat[0];
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (i == j) {
				std::cout << k++ << " элемент>";
				std::cin >> mat[i * size + j];
				std::cout << k++ << " элемент>";
				std::cin >> mat[i * size + j - 1];
				std::cout << k++ << " элемент>";
				std::cin >> mat[(i - 1) * size + j];
			}
		}
	}
}
void Matrix::print() {
	int k = 0;
	for (int i = 0; i < size * size; i++) {
		if (k == size) {
			std::cout << "\n";
			k = 0;
		}
		std::cout << mat[i] << "\t";
		k++;
	}
	std::cout << "\n";
}
int Matrix::get_columns() {
	return size;
}

int Matrix::trace() {
	int summ = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j or (i + j) == size - 1) {
				summ += this->get_elem(i, j);
			}
		}
	}
	return summ;
}
void Matrix::shiftmat(Matrix& addmat, int index) {
	int ki = 0;
	int len = this->size;
	for (int i = 1; i < len; i++) {
		for (int j = 0, kj = 0; j < len; j++) {
			if (j != index) {
				addmat.mat[ki * addmat.size + kj] = this->mat[i * len + j];
				kj++;
			}
		}
		ki++;
	}
}
int Matrix::det() {
	int opred = 0;
	int k = 1;
	if (size < 1) { return 0; }
	else if (size == 1) { opred = mat[0]; }
	else if (size == 2) { opred = mat[0] * mat[3] - mat[1] * mat[2]; }
	else {
		for (int i = 0; i < size; i++) {
			int m = size - 1;
			Matrix addmat(m);
			this->shiftmat(addmat, i);
			opred = opred + k * this->mat[i] * addmat.det();
			k = -k;
		}
	}
	return opred;
}
Matrix Matrix::sum(const Matrix mat2) {
	Matrix mat3(size);
	if (this->size != mat2.size) {
		std::cout << "Для выполнения сложения матрицы должны быть одинакового размера\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << this->size << ", " << this->size << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.size << ", " << mat2.size << ")";
		return mat3;
	}
	for (int i = 0; i < size * size; i++) {
		mat3.mat[i] = mat[i] + mat2.mat[i];
	}
	std::cout << "Новая матрица: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult(const Matrix mat2) {
	Matrix mat3(size);
	if (this->size != mat2.size) {
		std::cout << "Для умножения матриц кол-во колонок первой должно быть равно кол-ву строк второй\n";
		std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << size << ", " << size << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.size << ", " << mat2.size << ")";
		return mat3;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < mat2.size; j++) {
			for (int k = 0; k < mat2.size; k++) {
				mat3.mat[i * mat2.size + j] += this->get_elem(i, k) * mat2.mat[k * mat2.size + j];
			}
		}
	}
	std::cout << "Произведение матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult_by_num(Matrix mat1, int num) {
	Matrix mat3(size);
	for (int i = 0; i < size * size; i++) { mat3.mat[i] = mat[i] * num; }
	return mat3;
}

Matrix operator+(Matrix mat1, Matrix mat2) {
	return mat1.sum(mat2);
}
Matrix operator-(Matrix mat1,Matrix mat2) {
	return mat1.sum(-mat2);
}
Matrix Matrix::operator-(){
	Matrix mat3(size);
	int t;
	for (int i = 0; i < size * size; i++) {
		if (mat[i] != 0) {
			t = -mat[i];
			mat3.mat[i] = t;
		}
	}
	std::cout << "Матрица с измененными знаками: \n";
	mat3.print();
	return mat3;
}
Matrix operator*(Matrix mat1, Matrix mat2) {
	return mat1.mult(mat2);
}
Matrix operator*(Matrix mat1, int m) {
	return mat1.mult_by_num(mat1, m);
}
void Matrix::operator+=(const Matrix mat2) {
	this->operator=(*this + mat2);
}
void Matrix::operator-=(const Matrix mat2) {
	this->operator=(*this-mat2);
}
std::ostream& operator <<(std::ostream& out, Matrix mat1) {
	int k = 0;
	for (int i = 0; i < mat1.size * mat1.size; i++) {
		if (k == mat1.size) {
			out << "\n";
			k = 0;
		}
		out << mat1.mat[i] << "\t";
		k++;
	}
	out << "\n";
	return out;
}
std::istream& operator >>(std::istream& in, Matrix& mat1) {
	std::cout << "Введите кол-во строк: "; int len; std::cin >> len;
	mat1.size = len;
	if (mat1.mat != nullptr) { delete[]mat1.mat; }
	mat1.mat = new int[mat1.size * mat1.size];
	for (int i = 0; i < mat1.size * mat1.size; i++) {
		mat1.mat[i] = 0;
	}
	int k = 1;
	std::cout << k++ << " элемент>";
	std::cin >> mat1.mat[0];
	for (int i = 1; i < mat1.size; i++) {
		for (int j = 1; j < mat1.size; j++) {
			if (i == j) {
				std::cout << k++ << " элемент>";
				std::cin >> mat1.mat[i * mat1.size + j];
				std::cout << k++ << " элемент>";
				std::cin >> mat1.mat[i * mat1.size + j - 1];
				std::cout << k++ << " элемент>";
				std::cin >> mat1.mat[(i - 1) * mat1.size + j];
			}
		}
	}
	return in;
}