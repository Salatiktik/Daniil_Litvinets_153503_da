// Задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int c_bin(char*& num,int& dot)
{
    cin.getline(num,100);
    int t = 0,int_len=0;
    while (num[t] != '\0')
    {
        if (num[t] != '1' && num[t] != '0' && num[t]!=',')
            break;
        if (num[t] == ',')
        {
            dot = t;
            int_len = t;
        }
        if (num[t + 1] == '\0')
            if ((int_len) % 8 == 0||(int_len==0&&(t+1)%8==0))
            {
                return t + 1;
            }
        t++;
    }
    cout << "Некоректный ввод\n";
    c_bin(num,dot);
}

void obr(char*& str, int i)
{
    for (int z = 1; z < i; z++)
    {
        if (str[z] == '1')
            str[z] = '0';
        else
            str[z] = '1';
    }
}

void dop(char*& str, int i)
{   
    if (str[i] == '0')
    {
        str[i] = '1';
        return;
    }
    else
    {
        str[i] = '0';
        dop(str, i - 1);
    }
}

void sum(char*& str1, char*& str2, int len1, int len2,int dot1, int dot2)
{
    int t = len2-1,z=len1-1;
    
    while (t != -1)
    {
        if (t == dot2)
        {
            t--;
        }
        if (z == dot1)
        {
            z--;
        }
        if (str1[z]-96 + str2[t] >= 2)
        {
            if (z - 1 == dot1)
                str1[z - 2]++;
            else
                str1[z - 1]++;
        }
        str1[z] = (((int)str1[z]-96 + (int)str2[t]) % 2)+48;
        t--;
        z--;
    }
    if (z != 0)
    {
        if (str1[z] >= 2)
        {
            str1[z - 1]++;
            str1[z] = (((int)str1[z] - 48) % 2)+48;
        }
    }
    else
    {
        str1[z]=((int)str1[z]-48)%2+48;
    }

}

int main()
{
    setlocale(LC_ALL, "RU");
    int t = 0, zn1 = 0, zn2 = 0, n1 = 1,n2 = 1,dot1,dot2;
    char* num1 = new char[100];
    char* num2 = new char[100];
    cout << "Введите числа в естественном коде(в случае некоректного ввода к примеру нарушения количества разрядов программа не несет ответственности за ваши криворучки):\n";
    int len1 = c_bin(num1,dot1);
    int len2 = c_bin(num2,dot2);
    if (len1 - dot1 > len2 - dot2)
    {
        for (int i = 0; i < ((len1 - dot1) - (len2 - dot2));)
        {
            cout << 1 << " ";
            num2[len2] = '0';
            len2++;
        }
        num2[len2] = '\0';
        while (num2[t])cout << num2[t++];
        cout << "\n";
        t = 0;
        
    }
    if (len2 - dot2 > len1 - dot1)
    {
        for (int i = 0; i < ((len2 - dot2) - (len1 - dot1)); i++)
        {
            num1[len1] = '0';
            len1++;
        }
        num1[len1] = '\0';

    }

    if (num1[0] == '1')
    {
        obr(num1, len1);
        num1[0] = '1';
        dop(num1,len1-1);
    }
    if (num2[0] == '1')
    {
        obr(num2, len2);
        num2[0] = '1';
        dop(num2, len2 - 1);
    }
    if (len1 >= len2)
    {
        sum(num1, num2, len1, len2,dot1,dot2);
        cout << num1;
    }
    else
    {
        sum(num2, num1, len2, len1,dot1,dot2);
        cout << num2;
    }
}
