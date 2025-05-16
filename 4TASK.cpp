#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
    * @brief Считывает значения с клавиатуры с проверкой ввода
    * @return возвращает значение, если оно правильное, иначе завершает программу
*/
double getValue();

/**
    * @brief Функция для вычисления значения функции y = x - (1 / (3 + sin(3.6 * x)))
    * @return x - (1 / (3 + sin(3.6 * x)))
*/
double calculate_expression(const double x);

/**
    * @brief Функция для проверки, что шаг положительный
    * @return положительный шаг
    */
double getPositiveStep();

/**
    * @brief Функция для проверки, что значение x входит в область определения функции (ООФ)
    * @param x значение x
    * @return true, если x входит в ООФ, иначе false
*/
bool isOOF(double x);

/**
    * @brief Точка входа в программу
    * @return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX =getValue();

    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x <= endX + numeric_limits<double>::epsilon(); x += step)
    {
        if (isOOF(x))
        {
            double y = calculate_expression(x);
            cout << x << " | " << y << endl;
        }
        else
        {
            cout << x << " | Функция не определена" << endl;
        }
    }

    return 0;
}

double getValue()
{
    double value=0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

double calculate_expression(const double x) {
    return x - (1.0 / (3.0 + sin(3.6 * x)));
}

double getPositiveStep()
{
double step=0;
step = getValue();
if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
            abort();
        }
return step;
}
bool isOOF(double x)
{
    return fabs(x) > numeric_limits<double>::epsilon();
}