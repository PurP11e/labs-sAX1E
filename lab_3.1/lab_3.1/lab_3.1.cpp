#include <iostream>
using namespace std;
int* case_1(int*& a, int& size) {
    cout << " Сколько элементов в массиве должно быть: ";
    cin >> size;
    delete[] a;
    int* arr = new int[size];
    cout << "Введите значения элементов массива: " << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    //arr[i] = i;
    return arr;
}

void case_2(int* a, int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
int sum(int n) {
    int k = 0, ch = 0;
    while (n > 0) {
        k++;
        if (!(k % 2))
            ch += n % 10;
        n /= 10;
    }
    return ch;
}
void case_3(int* a, int size) {
    int t;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sum(a[j]) > sum(a[j + 1])) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
void case_4(int* a, int size) {
    int t;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] % 10 > a[j + 1] % 10) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] % 10 == a[j + 1] % 10 and (a[j] < a[j + 1])) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int choise, size = 0;
    int* a = new int[size];
    a = case_1(a, size);
    while (1) {
        cout << " Что вы хотите выполнить? " << endl <<
            "1. Ввод массива. " << endl <<
            "2. Вывод массива в консоль. " << endl <<
            "3. Сортировка по сумме цифр, стоящих на четных местах. " << endl <<
            "4. Сортировка массива по последней цифре." << endl <<
            "5. Выход. " << endl;

        cin >> choise;
        switch (choise) {
        case 1: {
            a = case_1(a, size);
            break; }
        case 2: {
            case_2(a, size);
            break; }
        case 3: {
            case_3(a, size);
            break; }
        case 4: {
            case_4(a, size);
            break; }
        case 5: exit(0);
        default: std::cout << "Wrong number";
            break;
        }
    }
    delete[] a;
    return 0;
}
