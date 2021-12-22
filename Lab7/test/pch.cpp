//
// pch.cpp
//

#include "pch.h"


string main1(char* mass, int zn, int dot, int len)
{
    int st;
    char* s_num = new char[100];
    s_num = mass;
    long double tn = 0;
    int t = 0;
    st = dot - (0 - zn) - 1;
    for (int i = 0 - zn; i < len; i++)
    {
        if (i == dot && dot != 0)
            continue;
        tn += ((int)s_num[i] - 48) * pow(7, st--);
    }

    string ans = "";

    int tn_int = (int)tn, y = 0;

    long double a = (tn - tn_int);

    while (tn_int >= 12)
    {
        if (tn_int % 12 < 10)
        {
            s_num[t] = tn_int % 12 + 48;
        }
        else if (tn_int % 12 == 10)
        {
            s_num[t] = 'A';
        }
        else if (tn_int % 12 == 11)
        {
            s_num[t] = 'B';
        }
        t++;
        tn_int = tn_int / 12;

    }
    if (tn_int < 10)
    {
        s_num[t] = tn_int + 48;
    }
    else if (tn_int == 10)
    {
        s_num[t] = 'A';
    }
    else if (tn_int == 11)
    {
        s_num[t] = 'B';
    }
    if (zn == -1)
    {
        ans+= "-";
    }
    for (int i = t; i >= 0; i--)
    {
        ans+= s_num[i];
    }
    if (a != 0)
    {
        ans+=".";
        char* str_dr = new char[100];
        t = -1;
        do
        {
            t++;
            a *= 12;
            if ((int)a <= 9)
            {
                str_dr[t] = (int)a + 48;
            }
            else if ((int)a == 10)
            {
                str_dr[t] = 'A';
            }
            else if ((int)a == 11)
            {
                str_dr[t] = 'B';
            }
            a -= (int)a;
            ans+= str_dr[t];
        } while (t != 4);
    }
    return ans;
}

string main2(string mass, int zn, int dot, int len)
{
    int t = 0;
    string num = mass;
    string ans = "";
    if (num[0] == '1')
    {
        ans += "0";
        for (int i = 1; i < len; i++)
        {
            if (num[i] == '1')
                ans+="0";
            else if (num[i] == '0')
                ans+="1";
            else
                ans+=num[i];
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            ans+= num[i];
        }
    }
    return ans;
}

void obr(string& str, int i)
{
    for (int z = 1; z < i; z++)
    {
        if (str[z] == '1')
            str[z] = '0';
        else if (str[z] == '0')
            str[z] = '1';
        else
            str[z] = ',';
    }
}

void dop(string& str, int i)
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

void sum(string& str1, string& str2, int len1, int len2, int dot1, int dot2)
{
    int t = len2 - 1, z = len1 - 1;

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
        if (str1[z] - 96 + str2[t] >= 2)
        {
            if (z - 1 == dot1)
                str1[z - 2]++;
            else
                str1[z - 1]++;
        }
        str1[z] = (((int)str1[z] - 96 + (int)str2[t]) % 2) + 48;
        t--;
        z--;
    }

    z++;

    if (z != 0)
    {
        if (str1[z] >= 2)
        {
            str1[z - 1]++;
            str1[z] = (((int)str1[z] - 48) % 2) + 48;
        }
        else
        {
            str1[z] = (((int)str1[z] - 48) % 2) + 48;
        }

    }
    else
    {
        
        str1 = "0" + str1;
        if (str1[z+1] >= 2)
        {
            str1[z+1] = ((int)str1[z+2] - 48) % 2 + 48;
            str1[z] = '1';
        }
        else
        {
            str1[z+1] = (((int)str1[z+2] - 48) % 2) + 48;
        }
    }
}

string main3(string num1, string num2, int len1, int len2, int dot1, int dot2, int zn1, int zn2)
{
    setlocale(LC_ALL, "RU");
    int t = 0, n1 = 1, n2 = 1;

    if (len1 - dot1 > len2 - dot2)
    {
        for (int i = 0; i < ((len1 - dot1) - (len2 - dot2));)
        {
            num2+= "0";
            len2++;
        }
        num2+='\0';
    }
    if (len2 - dot2 > len1 - dot1)
    {
        for (int i = 0; i < ((len2 - dot2) - (len1 - dot1)); i++)
        {
            num1 += "0";
            len1++;
        }
        num1+= '\0';

    }


    if (num1[0] == '1')
    {
        obr(num1, len1);
        num1[0] = '1';
        dop(num1, len1 - 1);
    }
    if (num2[0] == '1')
    {
        obr(num2, len2);
        num2[0] = '1';
        dop(num2, len2 - 1);
    }

    if (len1 >= len2)
    {
        sum(num1, num2, len1, len2, dot1, dot2);
        return num1;
    }
    else
    {
        sum(num2, num1, len2, len1, dot1, dot2);
        return num2;
    }
}

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

int add_one(string& str, int t, string str_tw, int& len)
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

void sum(string& str1, string& str2, int len1, int len2, string& str_tw)
{
    int t = len1 - 1, z = len2 - 1;
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
        if (find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12) >= 0)
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12)];
        else
        {
            str1[t] = str_tw[find_sym(str1[t], str_tw, 12) - find_sym(str2[z], str_tw, 12) + 12];
            remove_one(str1, t - 1, str_tw);
        }
        z--;
        t--;
    }
}

string main4(string num1, string num2, char zn1, char zn2, int len1, int len2)
{
    string str_tw = "0123456789AB";
    if (zn1 == zn2)
    {
        if (len1 >= len2)
        {
            sum(num1, num2, len1, len2, str_tw);
            return zn1 + num1;
        }
        else
        {
            sum(num2, num1, len2, len1, str_tw);
            return zn2 + num2;
        }
    }
    else
    {
        if (len1 > len2)
        {
            vich(num1, num2, len1, len2, str_tw);
            return zn1 + num1;
        }
        else if (len2 < len1)
        {
            vich(num2, num1, len2, len1, str_tw);
            return zn2 + num2;
        }
        else
        {
            if (biggest(num1, num2, len1) == 1)
            {
                vich(num1, num2, len1, len2, str_tw);
                return zn1 + num1;
            }
            else if (biggest(num1, num2, len1) == 2)
            {
                vich(num2, num1, len2, len1, str_tw);
                return zn2 + num2;
            }
            else
            {
                cout << "0";
            }

        }
    }
}

string main5(int N)
{
    string rim = "";
    for (int i = 0; i < N / 1000; i++)
    {
        rim += 'M';
    }
    if (N - (int(N / 1000)) * 1000 >= 500)
    {
        if (N - (int(N / 1000)) * 1000 >= 900)
            rim += "CM";
        else
        {
            rim += "D";
            for (int i = 0; i < (N - (int(N / 1000)) * 1000 - 500) / 100; i++)
            {
                rim += "C";
            }
        }
    }
    else {
        if (N - (int(N / 1000)) * 1000 >= 400)
            rim += "CD";
        else for (int i = 0; i < (N - (int(N / 1000)) * 1000) / 100; i++)
        {
            rim += "C";
        }
    }

    if (N - (int(N / 100)) * 100 >= 50)
    {
        if (N - (int(N / 100)) * 100 >= 90)
            rim += "XC";
        else
        {
            rim += "L";
            for (int i = 0; i < (N - (int(N / 100)) * 100 - 50) / 10; i++)
            {
                rim += "X";
            }
        }
    }
    else
    {
        if (N - (int(N / 100)) * 100 >= 40)
            rim += "XL";
        else
        {
            for (int i = 0; i < (N - (int(N / 100)) * 100) / 10; i++)
            {
                rim += "X";
            }
        }
    }
    if (N % 10 >= 5)
    {
        if (N % 10 == 9)
        {
            rim += "IX";
        }
        else
        {
            rim += "V";
            for (int i = 0; i < N % 10 - 5; i++)
            {
                rim += "I";
            }
        }
    }
    else
    {
        if (N % 10 == 4)
        {
            rim += "IV";
        }
        else
        {
            for (int i = 0; i < N % 10; i++)
            {
                rim += "I";
            }
        }
    }

    return rim;
}

string main7(int n)
{
    setlocale(LC_ALL, "RU");
    string ans = "";
    int tr = 0, ts = 0, vn = 0;
    while (tr < n)
    {
        tr += 3;
    }
    if (tr == n)
    {
        ans += "+";
    }
    else
    {
        ans += "-";
    }
    while (ts < n)
    {
        ts += 37;
    }
    if (ts == n)
    {
        ans += "+";
    }
    else
    {
        ans += "-";
    }
    while (vn < n)
    {
        vn += 89;
    }
    if (vn == n)
    {
        ans += "+";
    }
    else
    {
        ans += "-";
    }
    return ans;
}

string main8(int n) {
    string s = "";
    if (n % 2 == 0)
    {
        n = ((n - 9) * 2 + 10);
    }
    else
    {
        n = ((n - 9) * 2 + 9);
    }
    while (n > 0)
    {
        s = char((n % 2) + 48) + s;
        n /= 2;
    }
    return s;

}

string main9(int n)
{
    int t = 0;
    string ans = "";
    char* n_tr = new char[100];
    while (n > 3)
    {
        if (n % 3 != 0)
        {
            n_tr[t] = (n % 3) + 48;
            n = (n - (n % 3)) / 3;
        }
        else
        {
            n_tr[t] = '3';
            n -= 3;
            n /= 3;
        }
        t++;
    }
    n_tr[t] = n + 48;

    for (int i = t; i >= 0; i--)
    {
        ans+= n_tr[i];
    }
    return ans;
}
