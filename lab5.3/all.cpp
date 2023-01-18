#include <iostream>
#include <ctime>

class Matrix{
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

	void operator>>(int len);
	void operator<<(int len);
	void operator=(const Matrix& other);
	Matrix operator +(const Matrix mat2);
	Matrix operator -(const Matrix mat2);
	Matrix operator -(int s);
	Matrix operator *(const Matrix mat2);
	Matrix operator *(int m);
	void operator +=(const Matrix mat2);
	void operator -=(const Matrix mat2);
};



Matrix::Matrix(){
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
	std::cout << "¬ведите размер матрицы: ";
	std::cin >> size;
	if (mat != nullptr) { delete[]mat; }
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		mat[i] = rand() % 100 - 50;
	}
}
void Matrix::input(int len) {
	size = len;
	if (mat != nullptr) { delete[]mat; }
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		std::cout << i + 1 << " элемент>";
		std::cin >> mat[i];
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

void Matrix::operator>>(int len) {
	this->input(len);
}
void Matrix::operator<<(int len) {
	this->print();
}
void Matrix::operator=(const Matrix& other) {
	this->size = other.size;
	mat = new int[size * size];
	for (int i = 0; i < size * size; i++) {
		this->mat[i] = other.mat[i];
	}
}
Matrix Matrix::operator+(const Matrix mat2) {
	Matrix mat3(size);
	if (this->size != mat2.size) {
		std::cout << "ƒл€ выполнени€ сложени€ матрицы должны быть одинакового размера\n";
		std::cout << "—ейчас:\n1 матрица (строки, колонки) = (" << this->size << ", " << this->size << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.size << ", " << mat2.size << ")";
		return mat3;
	}
	for (int i = 0; i < size * size; i++) {
		mat3.mat[i] = mat[i] + mat2.mat[i];
	}
	std::cout << "—умма матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::operator-(const Matrix mat2) {
	Matrix mat3(size);
	if (this->size != mat2.size) {
		std::cout << "ƒл€ выполнени€ сложени€ матрицы должны быть одинакового размера\n";
		std::cout << "—ейчас:\n1 матрица (строки, колонки) = (" << this->size << ", " << this->size << ")\n";
		std::cout << "2 матрица (строки, колонки) = (" << mat2.size << ", " << mat2.size << ")";
		return mat3;
	}
	for (int i = 0; i < size * size; i++) {
		mat3.mat[i] = mat[i] - mat2.mat[i];
	}
	std::cout << "–азница матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::operator-(int s) {
	Matrix mat3(size);
	int t;
	for (int i = 0; i < size * size; i++) {
		if (mat[i] != 0) {
			t = -mat[i];
			mat3.mat[i] = t; 
		}
	}
	std::cout << "ћатрица с измененными знаками: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::operator*(const Matrix mat2) {
	Matrix mat3(size);
	if (this->size != mat2.size) {
		std::cout << "ƒл€ умножени€ матриц кол-во колонок первой должно быть равно кол-ву строк второй\n";
		std::cout << "—ейчас:\n1 матрица (строки, колонки) = (" << this->size << ", " << this->size << ")\n";
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
	std::cout << "ѕроизведение матриц: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::operator*(int m) {
	Matrix mat3(size);
	for (int i = 0; i < size * size; i++) { mat3.mat[i] = mat[i] * m; }
	std::cout << "”множенна€ матрица: \n";
	mat3.print();
	return mat3;
}
void Matrix::operator+=(const Matrix mat2) {
	this->operator=(this->operator+(mat2));
}
void Matrix::operator-=(const Matrix mat2) {
	this->operator=(this->operator-(mat2));
}



int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	Matrix mat1;
	Matrix mat2;
	Matrix mat3;
	mat1.input();
	mat2.input();
	mat1.print();
	std::cout << "\n\n";
	mat2.print();
	std::cout << "\n\n";
	mat1 -= mat2;
	return 0;
}