#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getValue();

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетворяет условию n>=0
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Вычисляет сумму первых n членов ряда ∑[((-1)^k/(k!))•k)]
 * @param n Количество суммируемых членов
 * @return Значение частичной суммы ряда
 */

void checkE(const double e);

/**
 * @brief Вычисляет следующий член ряда по рекуррентной формуле
 * @param current Текущий член ряда
 * @param k Текущий индекс
 * @return Следующий член ряда
 */
double sumN(const int n);

/**
 * @brief Вычисляет следующий член ряда по рекуррентной формуле
 * @param current Текущий член ряда
 * @param k Текущий индекс (номер члена - 1)
 * @return Следующий член ряда
 */
double getNext(const double current, const int k);

/**
 * @brief Вычисляет сумму членов ряда, больших или равных заданной точности по модулю
 * @param e Требуемая точность вычислений
 * @return Значение суммы с заданной точностью
 */
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main() 
{
    setlocale(LC_ALL, "Russian");
    
    cout << "Введите количество членов ряда (n >= 0): ";
    int n = getValue();
    checkN(n);
    cout << "Сумма первых " << n << " членов ряда: " << fixed << setprecision(6) << sumN(n) << endl;
    
    cout << "Введите точность e (>0): ";
    double e = getDouble();
    checkE(e);
    cout << "Сумма членов ряда с точностью " << e << ": " << sumE(e) << endl;
    
    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}

double getDouble() 
{
    double value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Ошибка ввода!" << endl;
        abort();
    }
    return value;
}

void checkE(const double e) 
{
    if (e <= 0) 
    {
        cerr << "Ошибка: e должно быть > 0!" << endl;
        abort();
    }
}

void checkN(const int n) 
{
    if (n < 0) 
    {
        cerr << "Ошибка: n должно быть >= 0!" << endl;
        abort();
    }
}

double sumN(const int n) 
{  
    double current = 1.0; 
    double sum = current;
    
    for (int k = 1; k <= n; k++) 
    { 
        current = getNext(current, k); 
        sum += current;
    }
    return sum;
}

double getNext(const double current, const int k) 
{
    double N = current * (-1.0) / ((k + 1) * (k + 2));
    return N;
}



double sumE(const double e) 
{
    double sum = 0.0;
    double current = 1.0; 
    int k = 0;
    
    while (abs(current) >= e) 
    {
        sum += current;
        current = getNext(current, k); 
        k++;
    }
    return sum;
}