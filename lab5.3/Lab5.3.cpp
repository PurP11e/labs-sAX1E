#include<iostream>
#include"Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int choise;

	Matrix mat1(4);
	Matrix mat2(4);

	while (true) {
		std::cout << "Какую команду выполнить: \n";
		std::cout << "1 - Ввод матрицы\n2 - Заполнение матрицы случайными числами\n3 - печать матрицы\n4 - печать кол-ва столбцов матрицы\n5 - печать следа матрицы\n";
		std::cout << "6 - печать определителя матрицы\n7 - сложение матриц\n8 - вычитание матриц\n9 - смена знаков в матрице\n10 - умножение матриц\n11 - умножение матрицы на число\n12 - Выход\n";
		std::cout << "Введите номер команды: "; std::cin >> choise;
		switch (choise){
		case 1: {
			system("cls");
			std::cout << "Какую матрицу заполнить?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cin >> mat1;
				std::cout << "\n";
				std::cout << "Матрица заполнена";
			}
			else {
				std::cin >> mat2;
				std::cout << "\n";
				std::cout << "Матрица заполнена";
			}
			std::cout << "\n\n";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "Какую матрицу заполнить?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				mat1.input();
				std::cout << "\n";
				std::cout << "Матрица заполнена";
			}
			else {
				mat2.input();
				std::cout << "\n";
				std::cout << "Матрица заполнена";
			}
			std::cout << "\n\n";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "Какую матрицу вывести?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			std::cout << "\n";
			if (ans == 1) {
				std::cout << mat1;
			}
			else {
				std::cout << mat2;
			}
			std::cout << "\n";
			break;
		}
		case 4: {
			system("cls");
			std::cout << "Кол-во столбиков какой матрицы вывести?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			std::cout << "\nКол-во столбцов: ";
			if (ans == 1) {
				std::cout << mat1.get_columns() << "\n\n";
			}
			else {
				std::cout << mat2.get_columns() << "\n\n";
			}
			break;
		}
		case 5: {
			system("cls");
			std::cout << "След какой матрицы вывести?\n1 - след первой матрицы\n2 - след второй матрицы\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				std::cout << mat1.trace();
			}
			else {
				std::cout << mat2.trace();
			}
			std::cout << "\n\n";
			break;
		}
		case 6: {
			system("cls");
			std::cout << "Определитель какой матрицы вывести?\n1 - Определитель первой матрицы\n2 - Определитель второй матрицы\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				std::cout << mat1.det();
			}
			else {
				std::cout << mat2.det();
			}
			std::cout << "\n\n";
			break;
		}
		case 7: {
			system("cls");
			std::cout << "Первая матрица: \n";
			mat1.print();
			std::cout << "\nВторая матрица: \n";
			mat2.print();
			std::cout << "\n";
			mat1 + mat2;
			break;
		}
		case 8: {
			system("cls");
			std::cout << "Первая матрица: \n";
			mat1.print();
			std::cout << "\nВторая матрица: \n";
			mat2.print();
			std::cout << "\n";
			mat1 - mat2;
			break;
		}
		case 9: {
			system("cls");
			std::cout << "Знаки какой матрицы поменять?\n1 - первой\n2 - второй\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Первая матрица: \n";
				mat1.print();
				-mat1;
			}
			else {
				std::cout << "\nВторая матрица: \n";
				mat2.print();
				-mat2;
			}
			break;
		}
		case 10: {
			system("cls");
			std::cout << "Первая матрица: \n";
			mat1.print();
			std::cout << "\nВторая матрица: \n";
			mat2.print();
			std::cout << "\n";
			mat1 * mat2;
			break;
		}
		case 11: {
			system("cls");
			std::cout << "\nНа какое число умножить матрицу?\n";
			int k; std::cin >> k;
			std::cout << "Какую матрицу умножить?\n1 - первую\n2 - вторую\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Первая матрица: \n";
				mat1.print();
				mat1 * k;
			}
			else {
				std::cout << "\nВторая матрица: \n";
				mat2.print();
				mat2 * k;
			}
			break;
		}
		case 12: {
			return 0;
		}
		default:
			std::cout << "Неверная команда\n";
			std::cout << "\n";
			continue;
		}
	}
}