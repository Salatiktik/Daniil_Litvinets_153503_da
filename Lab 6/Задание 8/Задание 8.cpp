// Задание 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

bool sosed(string s, string t, int start, int i,int len_t)
{
    while (s[start + 1] == t[i])
    {
        if (i == len_t)
            return 1;
        start++;
        i++;
    }
    while (s[start - 1] == t[i])
    {
        if (i == len_t)
            return 1;
        start--;
        i++;
    }
    return 0;
}

int main()
{
    int N = c_nat(),len_t=0, start = 0;
    string s, t;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        cin >> t;
        while (t[len_t] != '\0')
        {
            len_t++;
        }
        len_t--;
        while (s.find(t[0], start) + 1)
        {
            start = s.find(t[0], start);
            if (len_t == 0)
            {
                cout << "Yes\n";
                break;
            }
            if (sosed(s, t, start, 1, len_t))
            {
                cout << "Yes\n";
                break;
            }
            start++;
        }
        if (s.find(t[0], start) == -1)
        {
            cout << "No\n";
        }
    }
}
