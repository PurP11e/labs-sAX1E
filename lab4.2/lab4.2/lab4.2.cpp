#include <iostream>
#include <cstring>
#include <fstream>
std::string file_format(const std::string file_path_full) {   // функция возвращает расширение файла по введённому полному расположению
    int num;
    std::string format;
    num = file_path_full.find_first_of('.');
    format = file_path_full.substr(num, file_path_full.size() - num);
    return format;
}
std::string file_name(const std::string file_path_full) { //  функция возвращает название файла по введённому полному расположению
    int num, num1;
    std::string name;
    num = file_path_full.find_last_of('.');
    num1 = file_path_full.find_last_of("\\");
    int a = file_path_full.size() - num1 - 1 - (file_path_full.size() - num);
    name = file_path_full.substr(num1 + 1, a);
    return name;
}
std::string file_path(const std::string file_path_full) { //  функция выводит расположение файла по введенному полному расположению
    int num;
    std::string name;
    num = file_path_full.find_last_of("\\");
    name = file_path_full.substr(0, num);
    return name;
}
char file_disk(const std::string file_path_full) {   //  функция возвращает название диска по введенному полному расположению файла
    return file_path_full.at(0);
}
std::string file_rename(std::string file_path_full) { // функция возвращает переименованный файл
    std::string new_name;
    std::cin >> new_name;
    file_path_full = file_path_full.substr(0, file_path_full.find_last_of("\\") + 1) + new_name + ".cpp";
    return file_path_full;
}
bool file_copy(const std::string file_path_full) {
    int num;
    std::fstream fs;
    std::fstream out;
    std::string temp;
    num = file_path_full.find_first_of('.');
    fs.open(file_path_full, std::fstream::in);
    out.open(file_path_full.substr(0, num) + "_copy" + file_path_full.substr(num, file_path_full.size() - num), std::fstream::out);
    while (!fs.eof()) {
        fs >> temp;
        out << temp << '\n';
    }
    return 1;
}
int main() {
    std::string file_path_name;
    int a = 0, k = 0;
    int choise;
    while (1) {
        std::cout << "Choose the case: \n" << "Entering a name of the file - enter 1\n" << "File format - enter 2\n" << "File name - enter 3\n" << "Path - enter 4\n" << "Disk - enter 5\n" << "Rename - enter 6\n" << "Copy - enter 7\n" << "Exit - enter 8\n";
        std::cin >> choise;
        switch (choise) {
        case 1: {
            std::cout << "Enter full file name:  "; std::cin >> file_path_name;
            break;
        }
        case 2: {
            std::cout << file_format(file_path_name) << '\n';
            break;
        }
        case 3: {
            std::cout << file_name(file_path_name) << "\n";
            break;
        }
        case 4: {
            std::cout << file_path(file_path_name) << "\n";
            break;
        }
        case 5: {
            std::cout << file_disk(file_path_name) << "\n";
            break;
        }
        case 6: {
            std::cout << file_rename(file_path_name) << "\n";
            break;
        }
        case 7: {
            file_copy(file_path_name);
            break;
        }
        case 8:
            exit(0);
        default: {
            std::cout << "Wrong number";
            break;
        }
        }
    }
    return 0;
}