/*
����� � ��� ������: ������������ ������ �1
�������� ������: �������� ���������, ��������� � �����
�.�.�.: 
����� �������� ������: 
������: 
�������: �9
*/
/*
������� 9
? ����� ������������ �� ������ ������� �������.
? ����� ����� ��������� �������, ������������� ����� ������ �
������ �������������� ����������.
? ������������� ������ ����� �������, ����� ��������, ������
����, ������������� ����� ���� ���������.
*/

//����������� ����������� ���������
#include <iostream>
#include <locale>
#include <cstdlib>
#include <cmath>
using namespace std;

// ����� ������� � �������
void print_arr();

// ������������� ������� ����� ������� �������
void init_arr();


// ����� ������������� ��������
void search_max();

// ����� ��������� ����� ����� ��������������
void sum_between_one_two();

// ���������� ���������� ��������� �������
void sort_arr();

// ��������� ������� �������
const int arr_size = 20;

//����������� ���������� arr, ������� ����� ������������� ���������� ��������
int arr[arr_size];

//����������� ���������� ������������ � �������� � ����������� �� ��������� ��������
int i, max_elem, sum, j, temp = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������:\n";

    //�������� ������������� �������.
    init_arr();
    //������� ������.
    print_arr();
    
    //����� ������������� �� ������ �������� �������.
    search_max();
    cout << "1. ���������� ������� �� ������: " << max_elem << '\n';
    
    //����� ��������� ����� ����� �������������� ���������� �������.
    sum_between_one_two();
    cout << "2. ����� ��������� ����� ����� �������������� ����������: " << sum << '\n';
    
    //���������� �������.
    cout << "3. ��������, ������ ����, ������������� ����� ���� ���������.\n";
    sort_arr();
    print_arr();
}

// ������������� ������� ����� ������� �������, �.�. ������ ���������� ���������� ���������.
void init_arr()
{
    int sign = 0;

    //� ����� �������� ������ ����� ��������� �����.
    srand(time(NULL)); //�������������� ��������� ����� ������� ��� �� �����
    for (i = 0; i < arr_size; ++i)
    {
        arr[i] = rand() % 100;
        sign = rand() % 2;
        if (sign) arr[i] *= -1;
    }
    
    //��� ������� ��������� � ��������� ��������� ������� ��������
    arr[3] = 0;
    arr[5] = 0;
    arr[10] = 0;
    arr[15] = 0;
}

// ����� ������� �� �����
void print_arr()
{
    for (i = 0; i < arr_size; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

//����� ������������� �� ������ ��������
void search_max()
{

    // ���������� ������, ���������� ����������, ���� ��������, ������ �����������
    for (i = 0; i < arr_size; i++)
    {
        if (abs(arr[i]) > max_elem)
        {
            max_elem = arr[i];
        }
    }
}

//���������� ����� ��������� ������� ����� ������ � ������ �������������� ����������
void sum_between_one_two()
{
    //��������� ����������
    int temp = 0;
    i = 0;
    //���� ������ �������������
    //���� �����, ������� �� �����
    while (i < arr_size)
    {
        if (arr[i] > 0)
        {
            temp = i + 1;
            break;
        }
        
        i++;
    }
    
    //��������� ��������, ���� �� ���������� � ������������� ���������
    while (temp < arr_size)
    {
        if (arr[temp] > 0)
        {
            break;
        }
        
        sum += arr[temp];
        temp++;
    }
}

// ��������� ��� �������� ������ 0 � ����� �������
void sort_arr()
{
    for (int i=0; i <= arr_size; i++)                                       // ���� for , ������� ������������ ������� �������� �������
    {
        if(arr[i] == 0)
        {
            for (j = i + 1; j < arr_size; j++)
            if ( arr[j] !=0 && arr[i]==0 )
            {
                int a = arr[j];
                arr[j] = arr[i];
                arr[i] = a;
            }
            
        }
        
    }
}