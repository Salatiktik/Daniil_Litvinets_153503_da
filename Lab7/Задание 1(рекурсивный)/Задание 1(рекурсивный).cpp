// Задание 1(рекурсивный).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

long double c_p()
{
    long double x;
    while (!(std::cin >> x) || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(100500, '\n');
        std::cout << "Некоректный ввод данных" << std::endl;
    }
    return x;
}

long double in()
{
    long double sv = c_p(),sv_d=sv,ch=0;

    while (sv >= 1)
    {
        if ((int)sv % 10 >= 7)
        {
            ch++;
        }
        sv /= 10;
    }
    sv = sv_d;
    if (sv != round(sv))
    {
        sv -= int(sv);
        while (sv != round(sv))
        {
            sv *= 10;
            if ((int)sv % 10 >= 7)
                ch++;
        }
    }
    if (ch != 0)
    {
        cout << "Некоректный ввод";
        return in();
    }
    else
        return sv_d;
}

int len_int_f(long double n)
{
    int t = (int)n,z=0;
    while (t >= 1)
    {
        t /= 10;
        z++;
    }
    return z;
}

int len_f(long double n)
{
    int t = (int)n, z = 0;
    while (t >= 1)
    {
        t /= 10;
        z++;
    }
    return z;
}

int len_dr_f(long double n)
{
    int z = 0;
    while (n != round(n))
    {
        n *= 10;
        z++;
    }
    return z;
}

long double to_ten(long double n, int len_int, int len_dr, int i,long double& ten)
{
    if (i > 0)
    {
        ten += ((int)((int)n / pow(10, i - 1)) % 10) * pow(7, i - 1);
        to_ten(n, len_int, len_dr, --i,ten);

    }
    else
    {
        if (i >= (-len_dr) && i >= -5)
        {
            ten += ((int((n - (int)n) * pow(10, -i + 1))) % 10) * pow(7, i - 1);
            to_ten(n, len_int, len_dr, --i,ten);
        }
        else
            return 0;
    }
}

void to_tw_int(int ten, int i)
{
    if (int(ten / pow(12, i - 1)) % 12 <= 9)
        cout << int(ten / pow(12, i - 1)) % 12;
    else if (int(ten / pow(12, i - 1)) % 12 == 10)
        cout << 'A';
    else if (int(ten / pow(12, i - 1)) % 12 == 1)
        cout << 'B';

    if (i != 1)
        to_tw_int(ten, --i);
}

void to_tw_dr(long double ten, int i)
{
    ten *= 12;

    if ((int)ten <= 9)
        cout << (int)ten;
    else if ((int)ten == 10)
        cout << 'A';
    else
        cout << 'B';

    ten -= (int)(ten);
    i++;
    if (i != 5)
    {
        to_tw_dr(ten, i);
    }
}

int main()
{
    long double n = in();
    long double ten = 0;
    if (n != round(n))
    {
        int dot = 0, len_int = len_int_f(n), len_dr = len_dr_f(n);

        to_ten(n, len_int, len_dr, len_int, ten);
        int a = (int)(log(ten + 1) / log(12));
        if (a < log(ten + 1) / log(12))
            a++;
        
        to_tw_int((int)ten, a);
        cout << ".";
        to_tw_dr(ten - (int)ten, 0);
    }
    else
    {
        int len = len_f(n);
        to_ten(n, len, 0, len, ten);

        int a = (int)(log(ten + 1) / log(12));
        if (a < log(ten + 1) / log(12))
            a++;

        to_tw_int((int)ten, a);

    }
        
}