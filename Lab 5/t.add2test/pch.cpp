//
// pch.cpp
//

#include "pch.h"

unsigned long long pow_bin(unsigned long long x, unsigned long long t, unsigned long long m)//�������� ���������� � ������� ��� ���������� � ������� �� ������ ������ https://ru.wikipedia.org/wiki/����������_�_�������_��_������
{
	if (t == 0)
		return 1 % m;
	if (t % 2 == 0)
		return(pow_bin(x, t / 2, m) * pow_bin(x, t / 2, m) % m);
	if (t % 2 == 1)
		return((x * pow_bin(x, t / 2, m) * pow_bin(x, t / 2, m) % m) % m);
}
