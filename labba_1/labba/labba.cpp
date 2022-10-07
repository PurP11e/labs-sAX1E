#include <iostream>
#include <bitset>
#include <limits>
int main()
{
    //task 1
    std::cout << "1." << std::endl << "Gogichaev Eduard Vladimirovich, 221-351" << std::endl;

    //task 2
    std::cout << "2." << std::endl;
    std::cout << "min int = " << std::numeric_limits<int>::min() << ", "
        << "max int = " << std::numeric_limits<int>::max() << ", "
        << "size of int = " << sizeof(int) << std::endl;
    std::cout << "min unsigned int = " << std::numeric_limits<unsigned int>::min() << ", "
        << "max unsigned int = " << std::numeric_limits<unsigned int>::max() << ", "
        << "size of unsigned int = " << sizeof(unsigned int) << std::endl;
    std::cout << "min short = " << std::numeric_limits<short>::min() << ", "
        << "max short = " << std::numeric_limits<short>::max() << ", "
        << "size of short = " << sizeof(short) << std::endl;
    std::cout << "min unsigned short = " << std::numeric_limits<unsigned short>::min() << ", "
        << "max unsigned short = " << std::numeric_limits<unsigned short>::max() << ", "
        << "size of unsigned short = " << sizeof(unsigned short) << std::endl;
    std::cout << "min long = " << std::numeric_limits<long>::min() << ", "
        << "max long = " << std::numeric_limits<long>::max() << ", "
        << "size of long = " << sizeof(long) << std::endl;
    std::cout << "min long long = " << std::numeric_limits<long long>::min() << ", "
        << "max long long = " << std::numeric_limits<long long>::max() << ", "
        << "size of long long = " << sizeof(long long) << std::endl;
    std::cout << "min double = " << std::numeric_limits<double>::min() << ", "
        << "max double = " << std::numeric_limits<double>::max() << ", "
        << "size of double = " << sizeof(double) << std::endl;
    std::cout << "min char = " << std::numeric_limits<char>::min() << ", "
        << "max char = " << std::numeric_limits<char>::max() << ", "
        << "size of char = " << sizeof(char) << std::endl;
    std::cout << "min bool = " << std::numeric_limits<bool>::min() << ", "
        << "max bool = " << std::numeric_limits<bool>::max() << ", "
        << "size of bool = " << sizeof(bool) << std::endl;

    //task 3
    std::cout << "3." << std::endl;
    int x;
    setlocale(LC_ALL, "");
    std::cout << "Введите число: ";
    std::cin >> x;
    std::cout << std::endl;
    std::cout
        << "В бинарном виде: " << std::bitset<8 * sizeof(x)>(x) << std::endl
        << "В шестнадцатиричном виде: " << std::hex << x << std::endl
        << "bool: " << bool(x) << std::endl
        << "double: " << double(x) << std::endl
        << "char: " << char(x) << std::endl;
    //task 4
    std::dec;
    std::cout << "4." << std::endl;
    int a, b;
    std::cout << "Введите коэффиценты a*x=b: ";
    std::cin >> a >> b;
    std::cout << a << " * x = " << b << std::endl;
    if ((a == 0) and (b == 0)) {
        std::cout << "x принадлежит R" << std::endl;
    }
    else if ((a == 0) and (b != 0)) {
        std::cout << "Ошибка" << std::endl;
    }
    else if ((a != 0) and (b != 0)) {
        std::cout
            << "x = " << b << " / " << a << std::endl
            << "Ответ: "
            << "x = " << double(b) / a << std::endl;
    }
    //task 5
    std::cout << "5." << std::endl;
    int c, d;
    std::cout << "Введите координаты отрезка на прямой: ";
    std::cin >> c >> d;
    std::cout << "Середина отрезка находится в точке с координатой " << (c + d) / 2.;
    return 0;
}