//
// pch.cpp
//

#include "pch.h"
void reverse_str(char*& str, int last_void, int t_void)
{
	int summ = 0;
	for (int z = last_void + 1; z < t_void; z++)
	{
		summ += int(str[z]);
	}
	if (summ % 2 == 0)
	{
		if ((t_void - last_void) % 2 == 0)
		{
			for (int q = last_void + 1; q < (t_void + last_void) / 2; q++)
			{
				str[q] ^= str[(t_void - (q - last_void))] ^= str[q] ^= str[(t_void - (q - last_void))];
			}
		}
		else
		{
			for (int q = last_void + 1; q <= (t_void + last_void) / 2; q++)
			{
				str[q] ^= str[(t_void - (q - last_void))] ^= str[q] ^= str[(t_void - (q - last_void))];
			}
		}

	}
	summ = 0;

}

void check_str(char*& str)
{
	int last_void, t_void = -1, summ = 0;

	for (int i = 0; i < 80; i++)
	{
		if ((int)str[i] == 32 || (int)str[i] == 0 || (int)str[i] == 46 || (int)str[i] == 63 || (int)str[i] == 44 || (int)str[i] == 58 || (int)str[i] == 33 || (int)str[i] == 94 || (int)str[i] == 45 || (int)str[i] == 43 || (int)str[i] == 61 || (int)str[i] == 92 || (int)str[i] == 47 || (int)str[i] == 40 || (int)str[i] == 41)
		{
			last_void = t_void;
			t_void = i;
			reverse_str(str, last_void, t_void);
			if (str[i] == '\0' || str[i] == '\n')
			{
				str[i] = '\0';
			}
		}
	}
}
