/*
������ 2.3. ���������� ������� ������� ������
�������� ���������, ������� ������������� ������������ ������ ��
����������� �������� ��� ��������� ������� ������.
*/
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;
    double *arr = new double[n];
    cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ///////////////////// ���������� ������� ������/////////////////////
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
    cout << "��������������� �� ����������� ������: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    system("pause");
}