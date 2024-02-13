#include <iostream>
#include <cmath>
using namespace std;

// Рекурсивная функция для вычисления факториала
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Рекурсивная функция для вычисления суммы функционального ряда
double functionalSeries(int n, double x, int currentTerm) {
    if (currentTerm > n) {
        return 0;
    }
    else {
        int sign = (currentTerm % 2 == 0) ? 1 : -1;
        return sign * pow(2 * x, 2 * currentTerm) / factorial(2 * currentTerm) + functionalSeries(n, x, currentTerm + 1);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    double x;

    cout << "Введите количество членов ряда (n): ";
    cin >> n;
    cout << "Введите значение переменной (x): ";
    cin >> x;

    double sum = functionalSeries(n, x, 0);

    cout << "Сумма функционального ряда: " << sum << endl;

    return 0;
}