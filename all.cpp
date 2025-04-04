#include <iostream>
#include <cmath>
using namespace std;
 
/**
 *@brief - Функция для вычисления A по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = -4.8;
    const double y = 17.5;
    const double z = 3.2;
    
    cout << "a = " << getA(x, y, z) << endl;
    cout << "b = " << getB(x, y, z) << endl;

    return 0;
}

double getA(const double x, const double y, const double z)
{
    return y * z * pow(x, 2) - z / pow(sin(x / z), 2);
}

double getB(const double x, const double y, const double z)
{
    return z * exp(-sqrt(z)) * cos((y * x) / z);
}
