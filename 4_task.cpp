#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

/**
 * @brief Безопасный ввод числа с плавающей точкой
 * @param prompt - приглашение для ввода
 * @return Введённое число
 */
double getValidDouble(const string& prompt);

int main() {
    setlocale(LC_ALL, "rus");

    // Ввод параметров
    double start = getValidDouble("Введите начальное значение x: ");
    double end = getValidDouble("Введите конечное значение x: ");
    double step = getValidDouble("Введите шаг (Δx): ");

    // Проверка корректности шага
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным!" << endl;
        return 1;
    }

    // Заголовок таблицы
    cout << "\n x      | y" << endl;
    cout << "-----------------------" << endl;

    // Табулирование функции
    for (double x = start; x <= end + 1e-9; x += step) {
        // Вычисление знаменателя
        double denominator = 3.0 + sin(3.6 * x);
        
        // Проверка на возможность вычисления
        if (fabs(denominator) < 1e-9) {
            cout << fixed << setprecision(2) << x << " | Ошибка: деление на ноль" << endl;
        } else {
            double y = x - (1.0 / denominator);
            cout << fixed << setprecision(2) << x << " | " << setprecision(5) << y << endl;
        }
    }

    return 0;
}

double getValidDouble(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}
