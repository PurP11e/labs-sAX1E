//#include<iostream>
//#include<ctime>
//
//class Matrix {
//private:
//	int row;
//	int col;
//	double* mat;
//public:
//	Matrix(int rows, int cols);
//	Matrix(int size);
//	Matrix();
//	Matrix(const Matrix& other);
//	~Matrix();
//
//	void input(int cols, int rows);
//	void randinput(int cols, int rows);
//	void print();
//	void createmat(int cols, int rows);
//	int get_columns();
//	int get_rows();
//	double get_elem(int i, int j);
//	bool check_null(const Matrix& mat2);
//
//	Matrix sum(const Matrix mat2);
//	Matrix mult(const Matrix mat2);
//	double trace();
//	void shiftmat(Matrix& addmat, int index);
//	double det();
//	Matrix mult_by_num(double num);
//};
//
//Matrix::Matrix(int rows, int cols) {
//	if (mat != nullptr) { delete[]mat; }
//	row = rows; col = cols;
//	mat = new double[row * col];
//	for (int i = 0; i < row * col; i++) {
//		mat[i] = 0;
//	}
//}
//Matrix::Matrix(int size) {
//	row = size; col = size;
//	mat = new double[row * col];
//	for (int i = 0; i < row * col; i++) {
//		mat[i] = 0;
//	}
//}
//Matrix::Matrix() {
//	row = 0; col = 0;
//	mat = new double[row];
//}
//Matrix::Matrix(const Matrix& other) {
//	this->row = other.row; this->col = other.col;
//	mat = new double[row * col];
//	for (int i = 0; i < row * col; i++) {
//		this->mat[i] = other.mat[i];
//	}
//}
//Matrix::~Matrix() {
//	if (mat != nullptr) { delete[]mat; }
//}
//
//void Matrix::input(int rows, int cols) {
//	row = rows; col = cols;
//	if (mat != nullptr) { delete[]mat; }
//	mat = new double[row * col];
//	for (int i = 0; i < row * col; i++) {
//		std::cout << i + 1 << " элемент>";
//		std::cin >> mat[i];
//	}
//}
//void Matrix::randinput(int rows, int cols) {
//	row = rows; col = cols;
//	if (mat != nullptr) { delete[]mat; }
//	mat = new double[row * col];
//	for (int i = 0; i < row * col; i++) {
//		mat[i] = rand() % 100;
//	}
//}
//void Matrix::print() {
//	int k = 0;
//	for (int i = 0; i < row * col; i++) {
//		if (k == col) {
//			std::cout << "\n";
//			k = 0;
//		}
//		std::cout << mat[i] << "\t";
//		k++;
//	}
//	std::cout << "\n";
//}
//void Matrix::createmat(int rows, int cols) {
//	row = rows; col = cols;
//	std::cout << "Ввести случайную матрицу или ввести вручную: \n";
//	std::cout << "1 - случайная матрица\n2 - вручную\n";
//	int ans; std::cin >> ans;
//	if (ans == 1) {
//		this->randinput(row, col);
//	}
//	else {
//		this->input(row, col);
//	}
//}
//int Matrix::get_columns() {
//	return col;
//}
//int Matrix::get_rows() {
//	return row;
//}
//double Matrix::get_elem(int i, int j) {
//	return mat[i * col + j];
//}
//bool Matrix::check_null(const Matrix& mat2) {
//	if (this->col != mat2.row) { return false; }
//	else { return true; }
//}
//
//Matrix Matrix::sum(const Matrix mat2) {
//	Matrix mat3(row, col);
//	for (int i = 0; i < row * col; i++) {
//		mat3.mat[i] = mat[i] + mat2.mat[i];
//	}
//	return mat3;
//}
//Matrix Matrix::mult(const Matrix mat2) {
//	Matrix mat3(row, mat2.col);
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < mat2.col; j++) {
//			for (int k = 0; k < mat2.row; k++) {
//				mat3.mat[i * mat2.col + j] += this->get_elem(i, k) * mat2.mat[k * mat2.col + j];
//			}
//		}
//	}
//	return mat3;
//}
//void Matrix::shiftmat(Matrix& addmat, int index) {
//	int ki = 0;
//	int size = this->row;
//	for (int i = 1; i < size; i++) {
//		for (int j = 0, kj = 0; j < size; j++) {
//			if (j != index) {
//				addmat.mat[ki * addmat.row + kj] = this->mat[i * size + j];
//				kj++;
//			}
//		}
//		ki++;
//	}
//}
//double Matrix::det() {
//	double opred = 0;
//	int size = this->row;
//	int k = 1;
//	if (size < 1) { return 0; }
//	else if (size == 1) { opred = mat[0]; }
//	else if (size == 2) { opred = mat[0] * mat[3] - mat[1] * mat[2]; }
//	else {
//		for (int i = 0; i < size; i++) {
//			int m = size - 1;
//			Matrix addmat(m);
//			this->shiftmat(addmat, i);
//			opred = opred + k * this->mat[i] * addmat.det();
//			k = -k;
//		}
//	}
//	return opred;
//}
//double Matrix::trace() {
//	double summ = 0; int flag = row % 2;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (i == j or (i + j) == row - 1) {
//				summ += this->get_elem(i, j);
//			}
//		}
//	}
//	return summ;
//}
//Matrix Matrix::mult_by_num(double num) {
//	Matrix mat3(row, col);
//	for (int i = 0; i < row * col; i++) { mat3.mat[i] = mat[i] * num; }
//	return mat3;
//}
//
//
//
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	srand(time(NULL));
//	int choise = 0;
//
//	Matrix mat1(4);
//	Matrix mat2(4);
//	while (true) {
//		std::cout << "Какую команду выполнить: \n";
//		std::cout << "1 - Ввод матрицы\n2 - печать матрицы\n3 - печать кол-ва строк матрицы\n4 - печать кол-ва столбцов матрицы\n5 - печать (i, j) элемента\n";
//		std::cout << "6 - сумма матриц\n7 - умножение матриц\n8 - печать следа матрица\n9 - печать определителя матрицы\n10 - умножение матрицы на число\n11 - выход\n";
//		std::cout << "Введите номер команды: "; std::cin >> choise;
//		switch (choise) {
//		case 1: {
//			system("cls");
//			std::cout << "Какую матрицу заполнить?\n1 - первую\n2 - вторую\n";
//			int ans; std::cin >> ans;
//			std::cout << "Введите размер матрицы: \nКол-во строк - ";
//			int rw; std::cin >> rw; std::cout << "Кол-во столбиков - "; int cl; std::cin >> cl;
//			if (ans == 1) {
//				mat1.createmat(rw, cl);
//			}
//			else {
//				mat2.createmat(rw, cl);
//			}
//			std::cout << "Матрица создана\n\n";
//			break;
//		}
//		case 2: {
//			system("cls");
//			std::cout << "Какую матрицу вывести?\n1 - первую\n2 - вторую\n";
//			int ans; std::cin >> ans;
//			if (ans == 1) {
//				mat1.print();
//			}
//			else {
//				mat2.print();
//			}
//			std::cout << "\n";
//			break;
//		}
//		case 3: {
//			system("cls");
//			std::cout << "Кол-во строк какой матрицы вывести?\n1 - первой\n2 - второй\n";
//			int ans; std::cin >> ans;
//			if (ans == 1) {
//				std::cout << "Кол-во строк первой матрицы = " << mat1.get_rows() << "\n\n";
//			}
//			else {
//				std::cout << "Кол-во строк первой матрицы = " << mat2.get_rows() << "\n\n";
//			}
//			break;
//		}
//		case 4: {
//			system("cls");
//			std::cout << "Кол-во колонок какой матрицы вывести?\n1 - первой\n2 - второй\n";
//			int ans; std::cin >> ans;
//			if (ans == 1) {
//				std::cout << "Кол-во колонок первой матрицы = " << mat1.get_columns() << "\n\n";
//			}
//			else {
//				std::cout << "Кол-во колонок первой матрицы = " << mat2.get_columns() << "\n\n";
//			}
//			break;
//		}
//		case 5: {
//			system("cls");
//			std::cout << "Из какой матрицы вывести (i, j) элемент?\n1 - из первой\n2 - из второй\n";
//			int ans; std::cin >> ans;
//			if (ans == 1) {
//				std::cout << "Введите номер строки(число от 0 до " << mat1.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
//				std::cout << "Введите номер колонки(число от 0 до " << mat1.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
//				std::cout << "Матрица: \n";
//				mat1.print();
//				std::cout << "Элемент на этой позиции = " << mat1.get_elem(ans_i, ans_j);
//			}
//			else {
//				std::cout << "Введите номер строки(число от 0 до " << mat2.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
//				std::cout << "Введите номер колонки(число от 0 до " << mat2.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
//				std::cout << "Матрица: \n";
//				mat2.print();
//				std::cout << "Элемент на этой позиции = " << mat2.get_elem(ans_i, ans_j);
//			}
//			std::cout << "\n\n";
//			break;
//		}
//		case 6: {
//			system("cls");
//			if (mat1.get_columns() != mat2.get_columns() or mat1.get_rows() != mat2.get_rows()) {
//				std::cout << "Для выполнения сложения матрицы должны быть одинакового размера\n";
//				std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << mat1.get_rows() << ", " << mat1.get_columns() << ")\n";
//				std::cout << "2 матрица (строки, колонки) = (" << mat2.get_rows() << ", " << mat2.get_columns() << ")";
//			}
//			else {
//				Matrix mat3(mat1.sum(mat2));
//				std::cout << "Первая матрица: \n";
//				mat1.print();
//				std::cout << "\n";
//				std::cout << "Вторая матрица: \n";
//				mat2.print();
//				std::cout << "\n";
//				std::cout << "Сумма матриц: \n";
//				mat3.print();
//			}
//			std::cout << "\n\n";
//			break;
//		}
//		case 7: {
//			system("cls");
//			if (mat1.get_columns() != mat2.get_rows()) {
//				std::cout << "Для умножения матриц кол-во колонок первой должно быть равно кол-ву строк второй\n";
//				std::cout << "Сейчас:\n1 матрица (строки, колонки) = (" << mat1.get_rows() << ", " << mat1.get_columns() << ")\n";
//				std::cout << "2 матрица (строки, колонки) = (" << mat2.get_rows() << ", " << mat2.get_columns() << ")";
//			}
//			else {
//				Matrix mat3(mat1.mult(mat2));
//				std::cout << "Первая матрица: \n";
//				mat1.print();
//				std::cout << "\n";
//				std::cout << "Вторая матрица: \n";
//				mat2.print();
//				std::cout << "\n";
//				std::cout << "Произведение матриц: \n";
//				mat3.print();
//			}
//			std::cout << "\n\n";
//			break;
//		}
//		case 8: {
//			system("cls");
//			std::cout << "След какой матрицы вывести?\n1 - след первой матрицы\n2 - след второй матрицы\n";
//			int ans; std::cin >> ans;
//			system("cls");
//			if (ans == 1) {
//				if (mat1.get_columns() == mat1.get_rows()) {
//					std::cout << "первая матрица:\n";
//					mat1.print();
//					std::cout << "След: " << mat1.trace() << "\n";
//				}
//				else {
//					std::cout << "Нельзя найти след\nМатрица должна быть квадратной\n";
//				}
//			}
//			else {
//				if (mat2.get_columns() == mat2.get_rows()) {
//					std::cout << "вторая матрица:\n";
//					mat2.print();
//					std::cout << "\nСлед: " << mat2.trace() << "\n";
//				}
//				else {
//					std::cout << "Нельзя найти след\nМатрица должна быть квадратной\n";
//				}
//			}
//			std::cout << "\n";
//			break;
//		}
//		case 9: {
//			system("cls");
//			std::cout << "Определитель какой матрицы вывести?\n1 - определитель первой матрицы\n2 - определитель второй матрицы\n";
//			int ans; std::cin >> ans;
//			system("cls");
//			if (ans == 1) {
//				if (mat1.get_columns() == mat1.get_rows()) {
//					std::cout << "первая матрица:\n";
//					mat1.print();
//					std::cout << "\nОпределитель: " << mat1.det() << "\n";
//				}
//				else {
//					std::cout << "Нельзя найти определитель\nМатрица должна быть квадратной\n";
//				}
//			}
//			else {
//				if (mat2.get_columns() == mat2.get_rows()) {
//					std::cout << "вторая матрица:\n";
//					mat2.print();
//					std::cout << "\nОпределитель: " << mat2.det() << "\n";
//				}
//				else {
//					std::cout << "Нельзя найти определитель\nМатрица должна быть квадратной\n";
//				}
//			}
//			std::cout << "\n";
//			break;
//		}
//		case 10: {
//			system("cls");
//			std::cout << "Введите число на которое умножить матрицу: ";
//			int k;  std::cin >> k;
//			std::cout << "Какую матрицу умножить на " << k << "?\n1 - первую\n2 - вторую\n";
//			int ans; std::cin >> ans;
//			if (ans == 1) {
//				std::cout << "Матрица до умножения: \n";
//				mat1.print();
//				Matrix mat3(mat1.mult_by_num(k));
//				std::cout << "Матрица после умножения:\n";
//				mat3.print();
//			}
//			else {
//				std::cout << "Матрица до умножения: \n";
//				mat2.print();
//				Matrix mat3(mat2.mult_by_num(k));
//				std::cout << "Матрица после умножения:\n";
//				mat3.print();
//			}
//			break;
//		}
//		case 11: {
//			return 0;
//		}
//		default:
//			std::cout << "Неверная команда\n";
//			continue;
//		}
//	}
//	return 0;
//}