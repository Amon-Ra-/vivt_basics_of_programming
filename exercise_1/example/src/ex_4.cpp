/*
������ 2.4. ������� ���������� �������
�������� ���������, ������� ������������� ������������ ������ ��
����������� �������� ��� ��������� ������� ������� ����������.
*/
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 20;
    float arr[n];
    int *stackl = new int[n], *stackr = new int[n];
    cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ///////////////////// ������� ���������� /////////////////////
    int sp = 1;
    stackl[sp] = 0;
    stackr[sp] = n - 1; // 1
    while (sp > 0)
    {                           // ������� �� ����� ���������� ������� // 2
        int left = stackl[sp];  //3
        int right = stackr[sp]; //4
        sp--;                   //5
        while (left < right)
        { //6
            // ���������� { arr[left] .. arr[right] }
            int i = left, j = right;                //7
            float middle = arr[(left + right) / 2]; //8
            while (i < j)
            { //9
                while (arr[i] < middle)
                    i++; //10
                while (middle < arr[j])
                    j--; //11
                if (i <= j)
                {
                    float temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i++;
                    j--;
                }
            }
            if (i < right)
            { // ������ � ���� ������� �� ������ ����� //12
                sp++;
                stackl[sp] = i;
                stackr[sp] = right;
            }
            right = j; // ������ left � right ������������ ����� ����� //13
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    system("pause");
}