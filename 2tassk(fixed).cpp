#include <iostream>
#include <cmath> //Для sqrt()

using namespace std;

/**
    *@brief Считывает значение с клавиатуры с проверкой ввода
    *@return Введенное значение
*/

double getValue();

/**
    *@brief Вычисляет площадь прямоугольника
    *@param а Длина прямоугольника
    *@param b Ширина прямоугольника
    *@return Площадь прямоугольника
*/

double getRectangleArea(const double a, const double b);

/**
    *@brief Вычисляет площадь треугольника по формуле Герона
    *@param а Первая сторона треугольника
    *@param b Вторая сторона треугольника
    *@param c Третья сторона треугольника
    *@return Площадь треугольника
*/

double getTriangleArea(const double a, const double b, const double c);

/**
    *@brief Проверяет существование треугольника по введенным сторонам
    *@param а Первая сторона треугольника
    *@param b Вторая сторона треугольника
    *@param c Третья сторона треугольника
*/

void checkExist(const double a, const double b, const double c);

/**
    *@brief проверяет положительны ли стороны прямоугольника
    *@param а Длина прямоугольника
    *@param b Ширина прямоугольника
*/

void checkPositive(const double a, const double b, const double c);

/**
    *@brief проВеряет положительны ли стороны треугольника
    *@param а Первая сторона треугольника
    *@param b Вторая сторона треугольника
    *@param c Третья сторона треугольника
*/

void checkPositiveB(const double length, const double width);

/**
    *@brief Toчка входа в npoграмму
    *@return 0, ecnu npoгpaмма выполнена корректно, иначе 1
*/

int main()
{
    cout << "Введите длину прямоугольника: ";
    double length = getValue();
    cout << "Введите ширину прямоугольника: ";
    double width = getValue();
    checkPositiveB(length, width);
    cout << "Площадь прямоугольника равна:" << getRectangleArea(length, width) << endl;

    cout << "Введите первую сторону треугольника: ";
    double a = getValue();
    cout << "Введите вторую сторону треугольника: ";
    double b = getValue();
    cout << "Введите третью сторону треугольника: ";
    double c = getValue();
    checkPositive(a, b, c);
    checkExist(a, b, c); //Проверка существования треугольника

    cout << "Площадь треугольника равна: " << getTriangleArea(a, b, c) << endl;
    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail()) {
        cout << "Неверное значение." << endl;
        abort();
    }
    return value;
}

double getRectangleArea(const double a, const double b)
{
    return a * b;
}

double getTriangleArea(const double a, const double b, const double c)
{
    double p = (a + b + c) / 2.0; //полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c)); //формула Герона
}

void checkExist(const double a, const double b, const double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "Треугольник не существует." << endl;
        abort();
    }
}

void checkPositive(const double a, const double b, const double c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        cout << "Было введено отрицательное значение" << endl;
        abort();
    }
}

void checkPositiveB(const double length, const double width)
{
    if (length < 0 || width < 0)
    {
        cout << "Было введено отрицательное значение" << endl;
        abort();
    }
}