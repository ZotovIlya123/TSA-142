#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int getValue();

/**
 * @brief Получает и проверяет размер массива
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемое значение размера
 * @return Завершает программу при n <= 0
 */
void checkN(const int n);

/**
 * @brief Заполняет массив значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 * 
 */
void fillArray(int* arr, const size_t);


/**
 * @brief Находит сумму отрицательных элементов
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Максимальное отрицательное значение или -11 если таких элементов нет
 */
void printArray(const int* arr, const size_t);

/**
 * @brief Считает количество положительных элементов, не превышающих A
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param A Верхняя граница значений
 * @return Количество элементов удовлетворяющих условию
 */
int countPositiveLessThanA(const int* arr, const size_t n, const int A);

/**
 * @brief Вычисляет сумму отрицательных элементов
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param number Целевая сумма для сравнения
 * @return Возвращает индекс первого элемента пары.
 */
int sumNeg(const int* arr, const size_t n)

/**
 * @brief Ищет последнюю пару соседних элементов с разными знаками
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param number Целевая сумма для сравнения
 * @return Возвращает индекс первого элемента пары.
 */
int findLastPairWithDifferentSigns(const int* arr, const size_t n);

/**
* @brief Перечисление для выбора способа заполнения данных
* @param MANUALY Выбор ручного заполнения массива
* @param RANDOM Выбор автоматического заполнения массива
*/
enum {MANUALY, RANDOM};

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() 
{
    size_t n = getSize();
    int* arr = new int[n];
    fillArray(arr, n);
    cout << "Original array: ";
    printArray(arr, n);

    // Задача 1: сумма отрицательных элементов
    int sumNeg = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] < 0) 
        {
            sumNeg += arr[i];
        }
    }
    cout << "1. Sum of negatives: " << sumNeg << endl;

    // Задача 2: количество положительных элементов <= A
    cout << "2. Enter A: ";
    int A = getValue();
    int count = countPositiveLessThanA(arr, n, A);
    cout << "   Positive elements <= A: " << count << endl;

    // Задача 3: последняя пара соседних элементов с разными знаками
    int pairIndex = findLastPairWithDifferentSigns(arr, n);
    if (pairIndex == -1) 
    {
        cout << "3. No pair with different signs found." << endl;
    } 
    else 
    {
        cout << "3. Last pair with different signs starts at index: " << pairIndex << endl;
    }

    delete[] arr;
    return 0;
}

int getValue() 
{
    int value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Invalid input. Aborting." << endl;
        abort();
    }
    return value;
}

size_t getSize() 
{
    cout << "Enter array size (n): ";
    int n = getValue();
    checkN(n);
    return size_t(n);
}

void checkN(const int n) 
{
    if (n <= 0) 
    {
        cout << "Invalid size. Aborting." << endl;
        abort();
    }
}

void fillArray(int* arr, const size_t n) 
{
    cout << "Choose input method (" << RANDOM << " - random, " << MANUALY << " - manual): ";
    int choice = getValue();
    switch (choice) 
    {
        case RANDOM: 
        {
            srand(time(0));
            for (size_t i = 0; i < n; i++) 
            {
                int min = -100;
                int max = 200;
                arr[i] = min + rand() % (max - min + 1);
            }
            break;
        }
        case MANUALY: 
        {
            for (size_t i = 0; i < n; i++) 
            {
                while (true) 
                {
                    cout << "Enter arr[" << i << "] (-100 to 200): ";
                    int value = getValue();
                    
                    if (value >= -100 && value <= 200) 
                    {
                        arr[i] = value;
                        break;
                    }
                    cout << "Error! Value must be between -100 and 200. Try again." << endl;
                }
            }
            break;
        }
        default:
            cout << "Invalid choice. Aborting." << endl;
            abort();
    }
}

void printArray(int* arr, const size_t n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countPositiveLessThanA(int* arr, size_t n, int A) 
{
    int count = 0;
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] > 0 && arr[i] <= A)
         {
            count++;
        }
    }
    return count;
}

int findLastPairWithDifferentSigns(int* arr, size_t n) 
{
    if (n < 2) 
    {
        return -1;
    }
    for (size_t i = n - 1; i > 0; i--) 
    {
        if ((arr[i-1] < 0 && arr[i] >= 0) || (arr[i-1] >= 0 && arr[i] < 0)) 
        {
            return i-1;
        }
    }
    return -1;
}