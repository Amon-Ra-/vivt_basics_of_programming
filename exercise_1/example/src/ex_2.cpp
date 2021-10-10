/*
Пример 2.2. Сумма элементов правее последнего отрицательного
Написать программу, которая для вещественного массива из n элементов
определяет сумму его элементов, расположенных правее последнего
отрицательного элемента.
*/

#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    double *a = new double[n];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ineg = -1;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            ineg = i;
    if (ineg == -1)
        cout << "Отрицательных элементов нет\n";
    else if (ineg == n - 1)
        cout << "Отрицательный элемент - последний\n";
    else
    {
        double sum = 0;
        for (int i = ineg + 1; i < n; i++)
            sum += a[i];
        cout << "Сумма отрицательных: \n"
             << sum;
    }
    system("pause");
}