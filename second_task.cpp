#include <iostream>
#include <cmath>
using namespace std;

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

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double rectangleSide1 = 5.0;
    const double rectangleSide2 = 3.0;
    
    const double triangleSide1 = 3.0;
    const double triangleSide2 = 4.0;
    const double triangleSide3 = 5.0;
    
    cout << "Площадь прямоугольника: " << getRectangleArea(rectangleSide1, rectangleSide2) << endl;
    cout << "Площадь треугольника: " << getTriangleArea(triangleSide1, triangleSide2, triangleSide3) << endl;

    return 0;
}

double getRectangleArea(const double a, const double b)
{
    return a * b;  // Площадь = длина × ширина
}

double getTriangleArea(const double a, const double b, const double c)
{
    const double p = (a + b + c) / 2.0;  // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));  // Формула Герона
}