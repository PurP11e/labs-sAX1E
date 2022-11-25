#include <iostream>
#include <cstring>
#include <string.h>
bool palindrom(char* str) {              // функция проверки на палиндром
    int n = strlen(str) - 1;
    bool k = true;
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            k = false;
            break;
        }
    }
    return k;
}
int find_substring1(const char* str_for_search_in, const char* substring, int start_pos) {          // поиск первого вхождения подстроки
    int pos = -1;
    for (int i = start_pos; i < strlen(str_for_search_in); i++) {
        if (str_for_search_in[i] == substring[0]) {
            pos = i;
            i++;
            for (int j = 1; j < strlen(substring); j++, i++) {
                if (str_for_search_in[i] != substring[j]) {
                    pos = -1;
                    break;
                }
            }
            if (pos != -1) return pos;
        }
    }
    return pos;
}
void encrypt(char* text, int key) {                     //ввод строки, ключа шифрования. Cтрока меняется в соответствии с шифром Цезаря
    char encr_text[256];
    const char* abc = "abcdefghijklmnopqrstuvwxyz";
    strcpy_s(encr_text, text);
    for (int i = 0; i < std::strlen(text); i++) {
        if (std::strchr(abc, encr_text[i]))
            text[i] = char(int(encr_text[i]) + key);
        else text[i] = encr_text[i];
    }
}
void input(char* text) { //Ввод строки
    std::cout << "Enter string: " << '\n';
    std::cin.ignore();
    std::cin.getline(text, 256);
}
int main() {
    int start_pos, choise, key;
    char str[255] = " ";
    char substring[256] = " ";
    while (1) {
        std::cout << "Choose the case: \n" << "Entering a string - enter 1\n" << "Checking for a palindrome - enter 2\n" << "Index of occurrence of substring - enter 3\n" << "Caesar 's cipher - enter 4\n" << "exit - enter 5\n";
        std::cin >> choise;
        switch (choise) {
        case 1: {
            input(str);
            break;
        }
        case 2: {
            if (palindrom(str)) std::cout << "String is palindrom." << std::endl;
            else std::cout << "String is not palindrom." << std::endl;
            break;
        }
        case 3: {
            std::cout << "Enter a substring: "; std::cin >> substring;
            std::cout << "Enter a search start: "; std::cin >> start_pos;
            std::cout << "Index of occurrence: " << find_substring1(str, substring, start_pos) << "\n";
            break;
        }
        case 4: {
            std::cout << "Enter the key: "; std::cin >> key;
            encrypt(str, key);
            std::cout << "\n" << str << std::endl;
            break;
        }
        case 5: exit(0);
        default: std::cout << "Wrong number";
            break;
        }
    }
    return 0;
}