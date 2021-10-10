/*
Пример 2.3. Сортировка массива методом выбора
Написать программу, которая упорядочивает вещественный массив по
возрастанию значений его элементов методом выбора.
*/
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    double *arr = new double[n];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ///////////////////// Сортировка методом выбора/////////////////////
    double tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    cout << "Отсортированный по возрастанию массив: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    system("pause");
}