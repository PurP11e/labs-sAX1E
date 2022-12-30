#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix matr;
	matr.input();
	matr.print();
	std::cout << matr.trace(matr.elem, matr.get_rows()) << std::endl;
	Matrix matr2;
	matr2.input();
	matr2.print();
	Matrix matr3;
	matr3.matradd(matr.elem, matr2.elem, matr.get_columns(), matr2.get_rows());
	matr3.print();

	Matrix matr4;
	matr4.input();
	matr4.mult_by_num(3);
	matr4.print();
}