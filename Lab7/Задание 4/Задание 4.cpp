// Задание 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int biggest(string str1, string str2, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str1[i] == str2[i])
        {
            continue;
        }
        if (str1[i] > str2[i])
        {
            return 1;
        }
        if (str2[i] > str1[i])
        {
            return 2;
        }
    }
    return 0;
}

int find_sym(char a, string str, int len)
{
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == a)
        {
            return i;
        }
    }
    return -1;
}

int c_tw(string& num)
{
    cin >> num;
    int t = 0;
    while (num[t] != '\0')
    {
        if ((int)num[t] < 48 && (int)num[t] >58 && num[t] != 'A' && num[t] != 'B' && num[t] != '-' && num[t] != '+')
            break;
        if (num[t + 1] == '\0')
            return t + 1;
        t++;
    }
    cout << "Некоректный ввод\n";
    c_tw(num);
}

void remove_one(string& str, int t, string str_tw)
{
    if (str[t] != '0')
    {
        str[t] = str_tw[find_sym(str[t], str_tw, 12) - 1];
    }
    else
    {
        str[t] = 'B';
        remove_one(str, t - 1, str_tw);
    }
}

int add_one(string& str, int t, string str_tw , int& len)
{
    if (t != 0)
    {
        if (str[t] != 'B')
        {
            str[t] = str_tw[find_sym(str[t], str_tw, 12) + 1];
            return 0;
        }
        else
        {
            str[t] = '0';
            add_one(str, t - 1, str_tw, len);
        }
    }
    else
    {
        if (str[t] != 'B')
        {
            str[t] = str_tw[find_sym(str[t], str_tw, 12) + 1];
            return 0;
        }
        else
        {
            str[t] = '0';
            str = "1" + str;
            len++;
            return 1;
        }
    }
}

void sum(string& str1, string& str2, int len1, int len2, string &str_tw)
{
    int t = len1-1, z = len2-1;
    while (z != -1)
    {
        if (find_sym(str1[t], str_tw, 12) + find_sym(str2[z], str_tw, 12) < 12)
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) + find_sym(str2[z], str_tw, 12)];
        else
        {
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) + find_sym(str2[z], str_tw, 12) - 12];
            t += add_one(str1, t - 1, str_tw, len1);
        }
        z--;
        t--;
    }
}
void vich(string& str1, string& str2, int len1, int len2, string& str_tw)
{
    int t = len1 - 1, z = len2 - 1;
    while (z != -1)
    {
        if (find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12) >=0)
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12)];
        else
        {
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12) + 12];
            remove_one(str1, t -1 , str_tw);
        }
        z--;
        t--;
    }
}

int main()
{
    string num1,num2,zn1,zn2, str_tw = "0123456789AB";
    cout << "Введите первое число без знака(знак введете позже):\n";
    int len1 = c_tw(num1);
    cout << "Введите знак первого числа(+ или -):\n";
    cin >> zn1;
    cout << "Введите второе число без знака(знак введете позже):\n";
    int len2 = c_tw(num2);
    cout << "Введите знак второго числа(+ или -):\n";
    cin >> zn2;
    if (zn1 == zn2)
    {
        if (len1 >= len2)
        {
            sum(num1, num2, len1, len2, str_tw);
            cout << zn1 << num1;
        }
        else
        {
            sum(num2, num1, len2, len1, str_tw);
            cout << zn1 << num2;
        }
    }
    else
    {
        if (len1 > len2)
        {
            vich(num1, num2, len1, len2, str_tw);
            cout << zn1 << num1;
        }
        else if (len2 < len1)
        {
            vich(num2, num1, len2, len1, str_tw);
            cout << zn2 << num2;
        }
        else
        {
            if (biggest(num1, num2, len1) == 1)
            {
                vich(num1, num2, len1, len2, str_tw);
                cout << zn1 << num1;
            }
            else if (biggest(num1, num2, len1) == 2)
            {
                vich(num2, num1, len2, len1, str_tw);
                cout << zn2 << num2;
            }
            else
            {
                cout << 0;
            }
            
        }
    }
}