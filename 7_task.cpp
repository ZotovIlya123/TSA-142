#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

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
 * @brief Создает двумерный массив (матрицу) размером m x n
 * @param m Количество строк в массиве
 * @param n Количество строк в массиве
 * @return Cозданный двумерный массив
 */
int** getNewArray(const size_t m, const size_t n);

/**
 * @brief Выводит массив в форматированном виде
 * @param array Массив для вывода
 * @param m Количество строк
 * @param n Количество столбцов
 */
void printArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив вручную через консоль
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void fillArray(int** array, const size_t m, const size_t n);

/**
 * @brief Заполняет массив случайными числами
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param start Нижняя граница значений
 * @param end Верхняя граница значений
 */
void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

/**
 * @brief Освобождает память двумерного массива
 * @param array Указатель на массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void deleteArray(int** array, const size_t m, const size_t n);

/**
 * @brief Создает копию массива
 * @param array Исходный массив для копирования
 * @param m Количество строк
 * @param n Количество столбцов
 * @return Новый массив-копию
 */
int** copyArray(int** array, const size_t m, const size_t n);

/**
 * @brief Находит глобальный максимальный по модулю элемент
 * @param array Целевой массив
 * @param m Количество строк
 * @param n Количество столбцов
 */
void replaceFirstWithGlobalMaxAbs(int** array, size_t m, size_t n);

/**
 * @brief Заменяет первый элемент (индекс 0) каждого столбца на это значение
 * @param array Исходный массив
 * @param m Количество строк
 * @param n Количество столбцов
 * @param new_n Количество столбцов в новом массиве
 */
int** insertZeroColumnAfterMaxAbs(int** array, size_t m, size_t n, size_t& new_n);

/**
* @brief Перечисление для выбора способа заполнения данных
* @param MANUALY Выбор ручного заполнения массива
* @param RANDOM Выбор автоматического заполнения массива
*/
enum { RANDOM = 5, MANUAL = 6 };

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() 
{
    cout << "Enter m (rows): ";
    size_t m = getSize();
    cout << "Enter n (columns): ";
    size_t n = getSize();

    int** array = getNewArray(m, n); 

    cout << "Enter the way to fill array: " << MANUAL << " to fill manually, " << RANDOM << " to fill randomly: ";
    int choice = getValue();
    int start = 0, end = 0;

    switch (choice) 
    {
        case RANDOM:
            cout << "Enter start: ";
            start = getValue();
            cout << "Enter end: ";
            end = getValue();
            fillRandom(array, m, n, start, end);
            break;
        case MANUAL:
            fillArray(array, m, n);
            break;
        default:
            cout << "Error";
            deleteArray(array, m, n);
            return 1;
    }

    cout << "Original array:";
    cout << "";
    printArray(array, m, n);

    int** task1Array = copyArray(array, m, n);
    replaceFirstWithGlobalMaxAbs(task1Array, m, n);
    cout << "After Task 1 (replaced first element with global max absolute):";
    cout << "";
    printArray(task1Array, m, n);
    deleteArray(task1Array, m, n);

    size_t new_n;
    int** task2Array = insertZeroColumnAfterMaxAbs(array, m, n, new_n);
    cout << "After Task 2 (inserted zero columns after columns with max abs element):";
    cout << "";
    if (task2Array != nullptr && new_n > 0) 
    {
        printArray(task2Array, m, new_n);
        deleteArray(task2Array, m, new_n);
    } else 
    {
        cout << "No columns inserted.";
    }

    deleteArray(array, m, n);
    return 0;
}

int** getNewArray(const size_t m, const size_t n) 
{
    int** array = new int*[m];
    for (size_t i = 0; i < m; i++) 
    {
        array[i] = new int[n];
    }
    return array;
}

void deleteArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        delete[] array[i]; 
    }
    delete[] array;
}

void printArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n) 
{
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            cout << "Enter array[" << i << "][" << j << "]: ";
            array[i][j] = getValue();
        }
    }
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end) 
{
    srand(time(0));
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

int getValue() 
{
    int value = 0;
    cin >> value;
    if (cin.fail()) 
    {
        cerr << "Invalid input!" << endl;
        abort();
    }
    return value;
}

size_t getSize() 
{
    int size = getValue();
    if (size <= 0) 
    {
        cerr << "Size must be positive!" << endl;
        abort();
    }
    return static_cast<size_t>(size);
}

int** copyArray(int** array, const size_t m, const size_t n) 
{
    int** newArray = getNewArray(m, n);
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            newArray[i][j] = array[i][j];
        }
    }
    return newArray;
}

void replaceFirstWithGlobalMaxAbs(int** array, size_t m, size_t n) 
{
    // Находим глобальный максимальный по модулю элемент
    int max_abs_val = abs(array[0][0]);
    int global_max_val = array[0][0];
    
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            if (abs(array[i][j]) > max_abs_val) 
            {
                max_abs_val = abs(array[i][j]);
                global_max_val = array[i][j];
            }
        }
    }
    
    // Заменяем первый элемент каждого столбца
    for (size_t j = 0; j < n; j++) 
    {
        array[0][j] = global_max_val;
    }
}

int** insertZeroColumnAfterMaxAbs(int** array, size_t m, size_t n, size_t& new_n) 
{
    // Находим глобальный максимальный по модулю элемент
    int max_abs_val = abs(array[0][0]);
    for (size_t i = 0; i < m; i++) 
    {
        for (size_t j = 0; j < n; j++) 
        {
            if (abs(array[i][j]) > max_abs_val) 
            {
                max_abs_val = abs(array[i][j]);
            }
        }
    }
    
    // Считаем столбцы, содержащие max_abs_val
    size_t count = 0;
    bool* hasMaxAbs = new bool[n];
    
    for (size_t j = 0; j < n; j++) 
    {
        hasMaxAbs[j] = false;
        for (size_t i = 0; i < m; i++) 
        {
            if (abs(array[i][j]) == max_abs_val) 
            {
                hasMaxAbs[j] = true;
                count++;
                break;
            }
        }
    }
    
    new_n = n + count;
    
    if (count == 0) 
    {
        delete[] hasMaxAbs;
        return nullptr;
    }
    
    // Создаем новый массив с добавленными столбцами
    int** newArray = getNewArray(m, new_n);
    size_t new_j = 0;
    
    for (size_t j = 0; j < n; j++) 
    {
        // Копируем оригинальный столбец
        for (size_t i = 0; i < m; i++) 
        {
            newArray[i][new_j] = array[i][j];
        }
        new_j++;
        
        // Вставляем столбец нулей после столбцов с max_abs_val
        if (hasMaxAbs[j]) 
        {
            for (size_t i = 0; i < m; i++) 
            {
                newArray[i][new_j] = 0;
            }
            new_j++;
        }
    }
    
    delete[] hasMaxAbs;
    return newArray;
}