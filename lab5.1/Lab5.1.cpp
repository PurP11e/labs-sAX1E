#include<iostream>
#include"Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int choise = 0;

	Matrix mat1(4);
	Matrix mat2(4);
	while (true) {
		std::cout << "Какую команду выполнить: \n";
		std::cout << "1 - Ввод матрицы\n2 - печать матрицы\n3 - печать кол-ва строк матрицы\n4 - печать кол-ва столбцов матрицы\n5 - печать (i, j) элемента\n";
		std::cout << "6 - сумма матриц\n7 - умножение матриц\n8 - печать следа матрица\n9 - печать определителя матрицы\n10 - умножение матрицы на число\n11 - выход\n";
		std::cout << "Введите номер команды: "; std::cin >> choise;
		switch (choise) {
		case 1: {
			system("cls");
			std::cout << "Какую матрицу заполнить?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			std::cout << "Введите размер матрицы: \nКол-во строк - ";
			int rw; std::cin >> rw; std::cout << "Кол-во столбиков - "; int cl; std::cin >> cl;
			if (ans == 1) {
				mat1.createmat(rw, cl);
			}
			else {
				mat2.createmat(rw, cl);
			}
			std::cout << "Матрица создана\n\n";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "Какую матрицу вывести?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				mat1.print();
			}
			else {
				mat2.print();
			}
			std::cout << "\n";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "Кол-во строк какой матрицы вывести?\n1 - первой\n2 - второй\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Кол-во строк первой матрицы = " << mat1.get_rows() << "\n\n";
			}
			else {
				std::cout << "Кол-во строк первой матрицы = " << mat2.get_rows() << "\n\n";
			}
			break;
		}
		case 4: {
			system("cls");
			std::cout << "Кол-во колонок какой матрицы вывести?\n1 - первой\n2 - второй\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Кол-во колонок первой матрицы = " << mat1.get_columns() << "\n\n";
			}
			else {
				std::cout << "Кол-во колонок первой матрицы = " << mat2.get_columns() << "\n\n";
			}
			break;
		}
		case 5: {
			system("cls");
			std::cout << "Из какой матрицы вывести (i, j) элемент?\n1 - из первой\n2 - из второй\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Введите номер строки(число от 0 до " << mat1.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "Введите номер колонки(число от 0 до " << mat1.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "Матрица: \n";
				mat1.print();
				std::cout << "Элемент на этой позиции = " << mat1.get_elem(ans_i, ans_j);
			}
			else {
				std::cout << "Введите номер строки(число от 0 до " << mat2.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "Введите номер колонки(число от 0 до " << mat2.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "Матрица: \n";
				mat2.print();
				std::cout << "Элемент на этой позиции = " << mat2.get_elem(ans_i, ans_j);
			}
			std::cout << "\n\n";
			break;
		}
		case 6: {
			system("cls");
			mat1.sum(mat2);
			std::cout << "\n\n";
			break;
		}
		case 7: {
			system("cls");
			mat1.mult(mat2);
			std::cout << "\n\n";
			break;
		}
		case 8: {
			system("cls");
			std::cout << "След какой матрицы вывести?\n1 - след первой матрицы\n2 - след второй матрицы\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				mat1.trace();
			}
			else {
				mat2.trace();
			}
			std::cout << "\n";
			break;
		}
		case 9: {
			system("cls");
			std::cout << "Определитель какой матрицы вывести?\n1 - определитель первой матрицы\n2 - определитель второй матрицы\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				int f = mat1.get_columns();
				mat1.det(f);
			}
			else {
				int f = mat2.get_columns();
				mat2.det(f);
			}
			std::cout << "\n";
			break;
		}
		case 10: {
			system("cls");
			std::cout << "Введите число на которое умножить матрицу: ";
			int k;  std::cin >> k;
			std::cout << "Какую матрицу умножить на " << k << "?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Матрица до умножения: \n";
				mat1.print();
				Matrix mat3(mat1.mult_by_num(k));
				std::cout << "Матрица после умножения:\n";
				mat3.print();
			}
			else {
				std::cout << "Матрица до умножения: \n";
				mat2.print();
				Matrix mat3(mat2.mult_by_num(k));
				std::cout << "Матрица после умножения:\n";
				mat3.print();
			}
			break;
		}
		case 11: {
			return 0;
		}
		default:
			std::cout << "Неверная команда\n";
			continue;
		}
	}
	return 0;
}