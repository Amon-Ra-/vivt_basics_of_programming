/*
Номер и вид работы: Лабораторная работа №1
Название работы: Линейные программы, ветвления и циклы
Ф.И.О.: <Указать ФИО перед сдачей работы преподу>
Группа: ИВТз-202
Вариант: №15
*/
/*
Вариант 15
? Найти количество элементов массива, больших С.
? Найти произведение элементов массива, расположенных после
максимального по модулю элемента.
? Преобразовать массив таким образом, чтобы сначала
располагались все отрицательные элементы, а потом — все
положительные (элементы, равные 0, считать положительными).
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <locale>
using namespace std;

void print_arr();
void init_arr();
int count_c(int c);
int mul_elem();
void sort_arr();

const int arr_size = 20;
int arr[arr_size];
int i = 0, c = 0, max_elem = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Инициализация массива:\n";
    init_arr();
    print_arr();
    cout << "Укажите число C: ";
    cin >> c;
    cout << "1. Кол-во элементов больше C: " << count_c(c) << '\n';
    int res = mul_elem();
    cout << "2. Произведение элементов массива, расположенных после максимального по модулю элемента (после " << max_elem << "): " << res << '\n';
    cout << "3. Результат сортировки массива: \n";
    sort_arr();
    print_arr();
}

// Инициализация массива.
void init_arr()
{
    int sign = 0;
    for (i = 0; i < arr_size; ++i)
    {
        arr[i] = rand() % 100;
        sign = rand() % 2;
        if (sign)
            arr[i] *= -1;
    }
}

// Вывод массива на экран
void print_arr()
{
    for (i = 0; i < arr_size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

// Подсчёт кол-ва элементов больших C
int count_c(int c)
{
    int res = 0;
    for (i = 0; i < arr_size; ++i)
    {
        if (arr[i] > c)
            ++res;
    }
    return res;
}

// Вычисление произведения элементов расположенных после максимального по модулю.
int mul_elem()
{
    max_elem = 0;
    int res = 0, j = 0;
    for (i = 0; i < arr_size; ++i)
    {
        if (abs(arr[i]) > max_elem)
        {
            max_elem = abs(arr[i]);
            j = i + 1;
        }
    }
    if (!(j < arr_size))
        return 0;
    res = arr[j];
    j++;
    for (i = j; i < arr_size; ++i)
    {
        res *= arr[i];
    }
    return res;
}

// Сортировка массива.
void sort_arr()
{
    int j, temp;
    for (i = 1; i < arr_size; ++i)
    {
        for (j = arr_size - 1; j >= i; --j)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}