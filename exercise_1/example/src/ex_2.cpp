/*
������ 2.2. ����� ��������� ������ ���������� ��������������
�������� ���������, ������� ��� ������������� ������� �� n ���������
���������� ����� ��� ���������, ������������� ������ ����������
�������������� ��������.
*/

#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;
    double *a = new double[n];
    cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ineg = -1;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            ineg = i;
    if (ineg == -1)
        cout << "������������� ��������� ���\n";
    else if (ineg == n - 1)
        cout << "������������� ������� - ���������\n";
    else
    {
        double sum = 0;
        for (int i = ineg + 1; i < n; i++)
            sum += a[i];
        cout << "����� �������������: \n"
             << sum;
    }
    system("pause");
}