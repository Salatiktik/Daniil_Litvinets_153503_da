// Задание 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int c_nat()
{
    int x;
    while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x <= 0)
    {
        std::cin.clear();
        std::cin.ignore(100500, '\n');
        std::cout << "Некоректный ввод данных" << std::endl;
    }
    return x;
}

void check(string s1, string s2, int L, int m)
{
    int len1 = 0, len2 = 0, ch = 0, a = 0;
    while (s1[len1] != '\0')
    {
        len1++;
    }
    while (s2[len2] != '\0')
    {
        len2++;
    }
    if (len1 + len2 <= L)
    {
        std::cout << (long long)(2 * pow(26, L - len1 - len2)) % m << "\n";
    }
    if (len1 + len2 > L)
    {
        for (int r = L - len2; r < len1; r++)
        {
            if (s1[r] == s2[r - L + len2])
            {
                ch++;
            }
        }
        if (ch == len1 - L + len2)
        {
            a++;
        }
        ch = 0;
        for (int r = L - len1; r < len2; r++)
        {
            if (s2[r] == s1[r - L + len1])
            {
                ch++;
            }
        }
        if (ch == len1 - L + len2)
        {
            a++;
        }
        ch = 0;
        std::cout << a << "\n";
    }
}

int main()
{
    int i = c_nat(), L, m;
    for (int p = 0; p < i; p++)
    {
        string s1, s2;
        L = c_nat();
        m = c_nat();
        cin >> s1;
        cin >> s2;
        check(s1, s2, L, m);
        
    }
}