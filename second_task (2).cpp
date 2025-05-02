#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Функция для безопасного ввода числа с проверкой
 * @return Введённое число
 */
double getValidNumber();

/**
 * @brief Проверяет, могут ли стороны образовать треугольник
 * @param a, b, c - стороны треугольника
 * @return true, если треугольник существует, иначе false
 */
bool isValidTriangle(double a, double b, double c);

/**
 * @brief Функция для вычисления площади прямоугольника
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @return Площадь прямоугольника
 */
double getRectangleArea(const double a, const double b);

/**
 * @brief Функция для вычисления площади треугольника по формуле Герона
 * @param a - длина первой стороны
 * @param b - длина второй стороны
 * @param c - длина третьей стороны
 * @return Площадь треугольника
 */
double getTriangleArea(const double a, const double b, const double c);

int main()
{
    setlocale(LC_ALL, "rus");
    
    // Ввод сторон прямоугольника
    cout << "Введите стороны прямоугольника:\n";
    cout << "Сторона a: ";
    double rectA = getValidNumber();
    cout << "Сторона b: ";
    double rectB = getValidNumber();

    // Ввод сторон треугольника с проверкой
    double a, b, c;
    do {
        cout << "\nВведите стороны треугольника:\n";
        cout << "Сторона a: ";
        a = getValidNumber();
        cout << "Сторона b: ";
        b = getValidNumber();
        cout << "Сторона c: ";
        c = getValidNumber();

        if(!isValidTriangle(a, b, c)) {
            cout << "Ошибка: такой треугольник не существует!\n";
        }
    } while(!isValidTriangle(a, b, c));

    // Вычисление и вывод результатов
    cout << "\nРезультаты:\n";
    cout << "Площадь прямоугольника: " << getRectangleArea(rectA, rectB) << endl;
    cout << "Площадь треугольника: " << getTriangleArea(a, b, c) << endl;

    return 0;
}

double getValidNumber() {
    double num;
    while(true) {
        cin >> num;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число: ";
        } 
        else if(num <= 0) {
            cout << "Ошибка! Число должно быть положительным: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

bool isValidTriangle(double a, double b, double c) {
    return (a + b > c) && 
           (a + c > b) && 
           (b + c > a);
}

double getRectangleArea(const double a, const double b) {
    return a * b;
}

double getTriangleArea(const double a, const double b, const double c) {
    const double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}