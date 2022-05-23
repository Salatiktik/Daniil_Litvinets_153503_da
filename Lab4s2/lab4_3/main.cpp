#include <iostream>

#include <mvector.h>
#include <iostream>

#include <QDebug>

using namespace std;

bool bit(string str, int k)
{
    int b = 0;
    int len = (int)str.size();

    for (int i = 0; i < k; i++) {
        b = (str.back() - 48) % 2;
        str.back() -= b;

        for (int j = (int)len - 1; j >= 0; --j) {
            if (j != len - 1 && (str[j] - 48) % 2)
                str[j + 1] += 5;

            str[j] = (str[j] - 48) / 2 + 48;
        }
    }

    return (bool)b;
}

string mul(string str, int k) {

    string num = "1";
    if (k == 0)
        return num;

    for (int i = 0; i < k - (int)str.size(); i++){
        num += "0";
    }

    for (int i = 0; i < (int)str.size(); i++){
        num += str[i];
    }

    qDebug()<<num.c_str();
    return num;
}


string bindec(int N) {

    mvector<string> Ak(1000, "0");
    mvector<string> Bk(1000, "0");

    int inA = 1,inB = 0,k = 1,answer = 1;

    qDebug()<<Ak[0].c_str();
    qDebug()<<Bk[0].c_str();
    while (answer <= N) {
        int i_tmp = 0;
        inB = 0;
        for (int i = 0; i < inA; i++){
            if (bit(Ak[i], k) == 0)
                Ak[i_tmp++] = Ak[i];
        }

        inA = i_tmp;
        for (int i = 0; i < inA; i++){
            Bk[i] = mul(Ak[i], k - 1);
        }

        inB = inA;
        for (int i = 0; i < inB; i++){
            Ak[inA++] = Bk[i];
        }
        answer += inB;
        k++;
    }


    return Bk[N + inB - answer];
}

int main()
{

    int n;
    cin >> n;
    cout << bindec(n);
}
