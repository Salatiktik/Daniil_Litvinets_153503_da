// Задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>

using namespace std;

/*. На междугородной АТС информация о разговорах содержит
дату разговора, код и название города, время разговора, тариф, номер
телефона в этом городе и номер телефона абонента. Вывести по каждому
городу общее время разговоров с ним и сумму*/

//объявление структур

struct city_str {
	char* code;
	char* name;
};

struct call {
	char* date;
	char* time;
	city_str city;
	double rate;
	char* person1;
	char* person2;
};

struct city_base
{
	char* name;
	int* id;
	int count = 0;
	long long hole_time;
	long double hole_price;
};

//проверка на ввод натуральных чисел в определенном промежутке
int da(int n)
{
	int x;
	while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x <= 0 || x > n)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Выберите из предложенных вариантов\n" << std::endl;
	}
	return x;
}

//проверка на ввод
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

//ввод даты
char* date_in()
{
	char* h = (char*)calloc(11, sizeof(char));
	cin.getline(h,11);
	char* dd = (char*)calloc(3, sizeof(char));
	dd [0]= h[0];
	dd[1] = h[1];
	char* mm = (char*)calloc(3, sizeof(char));
	mm[0] = h[3];
	mm[1] = h[4];
	char* yy = (char*)calloc(5, sizeof(char));
	yy[0] = h[6];
	yy[1] = h[7];
	yy[2] = h[8];
	yy[3] = h[9]; 
	if (atoi(dd) >= 32 || atoi(mm) >= 13 || atoi(yy) < 1900 || atoi(yy) > 2021 || h[2] != '.' || h[5] != '.' || (int)h[11] != -3)
	{
		cout << "Некоректный ввод даты, попробуйте ещё:\n";
		free(h);
		free(dd);
		free(mm);
		free(yy);
		return date_in();
	}
	free(dd);
	free(mm);
	free(yy);
	return h;
}

//ввод времени
char* time_in()
{
	char* h = (char*)calloc(9, sizeof(char));
	cin.getline(h, 9);
	char* hh = (char*)calloc(3, sizeof(char));
	hh[0] = h[0];
	hh[1] = h[1];
	char* mm = (char*)calloc(3, sizeof(char));
	mm[0] = h[3];
	mm[1] = h[4];
	char* ss = (char*)calloc(3, sizeof(char));
	ss[0] = h[6];
	ss[1] = h[7];
	if (atoi(hh) > 99 || atoi(mm) >=60 || atoi(ss) >=60 || h[2] != ':' || h[5] != ':' || (int)h[9] != -3)
	{
		cout << "Некоректный ввод времени, попробуйте ещё:\n";
		free(h); 
		free(hh);
		free(mm);
		free(ss);
		return time_in();
	}
	free(hh);
	free(mm);
	free(ss);
	return h;
}

//ввод тариф

double c_rate()
{
	char* rate = (char*)calloc(6, sizeof(char));
	cin.getline(rate, 6);
	if (rate[2] == '.'&&rate[5]=='\0')
	{
		return atof(rate);
	}
	else if (rate[1] == '.'&&rate[4]=='\0')
	{
		return atof(rate);
	}
	else
	{
		cout << "Некоректный ввод, попробуйте ещё:";
		free(rate);
		return c_rate();
	}
}

//ввод номера и кода

char* num_in(char*& code)
{
	char* h = (char*)calloc(13, sizeof(char));
	cin.getline(h, 13);
	int i = 0;
	while (h[i] != ' ')cout << h[i++];
	code = (char*)calloc(i + 1, sizeof(char));
	if (i >= 3 && i <= 6 && h[0] == '8' && h[1] == '0' && h[12] != -3 && h[13]== -3)
	{
		for (int y = 0; y < i; y++)
			code[y] = h[y];
		return h;
	}
	else
	{
		cout << "Некоректный ввод, попробуйте ещё:";
		free(h);
		return num_in(code);
	}

}

char* num_in()
{
	char* h = (char*)calloc(13, sizeof(char));
	cin.getline(h, 13);
	int i = 0;
	while (h[i] != ' ')i++;
	if (i >= 3 && i<=6&& h[0] == '8' && h[1] == '0' && h[12] != -3 && h[13] == -3)
	{
		return h;
	}
	else
	{
		cout << "Некоректный ввод, попробуйте ещё:";
		free(h);
		return num_in();
	}
}

//ввод базы
void input_base(call*& calls, int n, int& base_len, int y)
{
	for (int i = base_len; i < base_len + n; i++)
	{
		cout << "Ячейка " << i + 1 << "\n";
		cout << "\tДата разговора (дд.мм.гггг):";
		calls[i].date = date_in();
		cout << "\tВремя разговора (чч:мм:сс):";
		calls[i].time = time_in();
		cout << "\tНазвание города(латиницей):";
		calls[i].city.name = (char*)calloc(21, sizeof(char));
		cin.getline(calls[i].city.name, 21);
		cout << "\tКод города и номер без кода звонящего через пробел (кодгорода номертелефона):";
		calls[i].person1 = num_in(calls[i].city.code);
		cout << "\tКод города и номер без кода абонента через пробел (кодгорода номертелефона):";
		calls[i].person2 = num_in();
		cout << "\tТарифный план(рр.кк):";
		calls[i].rate = c_rate();
	}
	base_len += n;
}

//расширение памяти массива
void base_up(call*& a, int& base_len, int n)
{
	a = (call*)realloc(a,(base_len + n) * (sizeof(char*) * 4 + sizeof(double) + sizeof(char*) * 2));
	input_base(a, n, base_len, 1);
}

//вывод базы
void out_base(call*& a, int i, int y)
{
	if (y == 1)
	{
		cout << "\n\nЯчейка " << i--;
		cout << "\n\tГород: ";
		cout << a[i].city.name;
		cout << "\n\tКод города: ";
		cout << a[i].city.code;
		cout << "\n\tТариф клиента: ";
		cout << a[i].rate;
		cout << "\n\tДата разговора:";
		cout << a[i].date;
		cout << "\n\tВремя разговора: ";
		cout << a[i].time;
		cout << "\n\tНомер телефона звонящего: ";
		cout << a[i].person1;
		cout << "\n\tНомер телефона абонента: ";
		cout << a[i].person2;
		cout << "\n";
	}
	else
	{
		int q = i;
		for (i = 0; i < q; i++)
		{
			cout << "\n\nЯчейка " << i+1;
			cout << "\n\tГород: ";
			cout << a[i].city.name;
			cout << "\n\tКод города: ";
			cout << a[i].city.code;
			cout << "\n\tТариф клиента: ";
			cout << a[i].rate;
			cout << "\n\tДата разговора:";
			cout << a[i].date;
			cout << "\n\tВремя разговора: ";
			cout << a[i].time;
			cout << "\n\tНомер телефона звонящего: ";
			cout << a[i].person1;
			cout << "\n\tНомер телефона абонента: ";
			cout << a[i].person2;
			cout << "\n";
		}
	}
}

//сравнение двух массивов char
bool compare(char* a, char* b)
{
	int len_a = 0, len_b = 0;
	while (a[len_a] != '\0')len_a++;
	while (b[len_b] != '\0')len_b++;
	if (len_a != len_b)return false;
	else 
		for (int i = 0; i < len_a; i++)
		{
			if (tolower(a[i]) != tolower(b[i]))
				return false;
		}

	return true;
}

//взаимодействие и изменение определенный полей базы
void change(call*& a, int len, int i)
{
	cout << "Что вы хотите изменить 1)Дату разговора 2)Время разговора 3)Тариф 4)Название города 5)Код города и номер звонящего 6)Номер абонента\n";
	int g = da(6);
	switch (g)
	{
	case 1:
	{
		cout << "Введите новую дату разговора (дд.мм.гггг):";
		a[i].date = date_in();
		cout << "Изменение прошло успешно!\n";
		break;
	}
	case 2:
	{
		cout << "Введите новое время разговора (чч:мм:сс):";
		a[i].time = time_in();
		cout << "Изменение прошло успешно!\n";
		break;
	}
	case 3:
	{
		cout << "Введите новый тариф (рр.кк):";
		a[i].rate = c_rate();
		cout << "Изменение прошло успешно!\n";
		break;
	}
	case 4:
	{
		cout << "Введите измененное название города:";
		cin.getline(a[i].city.name, 21);
		cout << "Изменение прошло успешно!\n";
		break;
	}
	case 5:
	{
		cout << "Введите новый номер телефона и код города(кодгорода номертелефона):";
		a[i].person1 = num_in(a[i].city.code);
		cout << "Изменение прошло успешно!\n";
		break;
	}
	case 6:
	{
		cout << "Введите новый номер телефона и код города(кодгорода номертелефона):";
		a[i].person2 = num_in();
		cout << "Изменение прошло успешно!\n";
		break;
	}
	}
}
//удаление одной ячейки
void delete_client(call*& a, int& len, int r)
{
	call* new_b = (call*)calloc(len - 1, sizeof(char*) * 4 + sizeof(double) + sizeof(char*) * 2);
	int o = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == r)
		{
			i++;
			if (i == len)
			{
				break;
			}
		}
		new_b[o] = a[i];
		o++;
	}
	free(a);
	a = new_b;
	len--;

}

//поиск по определенному аспекту
void find_client(call*& a, int len, int n)
{
	switch (n)
	{
	case 1:
	{
		char* city = (char*)calloc(20,sizeof(char));
		cout << "Введите город для поиска:";
		cin.getline(city,20);
		int* mass = (int*)calloc(len,sizeof(int));
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (compare(city,a[i].city.name))
			{
				mass[z] = i + 1;
				z++;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		free(mass);
		free(city);
		break;
	}
	case 2:
	{
		double rate;
		cout << "Введите тариф для поиска(рр.кк):";
		rate = c_rate();
		int* mass = (int*)calloc(len, sizeof(int));
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (rate == a[i].rate)
			{
				mass[z++] = i + 1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		free(mass);
		break;
	}
	case 3:
	{
		
		cout << "Введите номер телефона с кодом для поиска(кодгорода номертелефона):";
		char* num = num_in();
		int* mass = (int*)calloc(len, sizeof(int));
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (compare(num,a[i].person1)||compare(num, a[i].person2))
			{
				mass[z++] = i + 1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		free(mass);
		free(num);
		break;
	}
	case 4:
	{
		cout << "Введите дату разговора для поиска(дд.мм.гггг):";
		char* date = date_in();
		int* mass = (int*)calloc(len, sizeof(int));
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (compare(date,a[i].date))
			{
				mass[z++] = i + 1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		free(mass);
		free(date);
		break;
	}
	}
}

void calls_city_out(call*& a, int base_len)
{
	int unic = base_len;
	city_base* base = (city_base*)calloc(base_len, sizeof(char*) + sizeof(int*) + sizeof(int) + sizeof(long long)+sizeof(long double));
	base[0].name = a[0].city.name;
	base[0].id = (int*)calloc(base_len, sizeof(int));
	base[0].id[0] = 0;
	base[0].count = 1;
	base[0].hole_price = 0;
	base[0].hole_time = 0;
	int cnt = 1,ch = 0;
	for (int i = 1; i < base_len; i++)
	{
		for (int y = 0; y < cnt; y++)
		{
			if (compare(a[i].city.name, base[y].name))
			{
				base[y].id[base[y].count] = i;
				base[y].count++;
				ch = 1;
				continue;
			}
		}
		if (ch ==1)
		{
			ch = 0;
			continue;
		}		
		base[cnt].name = a[i].city.name;
		base[cnt].id = (int*)calloc(base_len, sizeof(int));
		base[cnt].id[0] = i;
		base[cnt].count = 1;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
	{
		for (int y = 0; y < base[i].count; y++)
		{
			base[i].hole_time += ((a[base[i].id[y]].time[0] - 48) * 10 + (a[base[i].id[y]].time[1] - 48)) * 3600 + ((a[base[i].id[y]].time[3] - 48) * 10 + (a[base[i].id[y]].time[4] - 48)) * 60 + ((a[base[i].id[y]].time[6] - 48) * 10 + (a[base[i].id[y]].time[7] - 48));
			base[i].hole_price += (((a[base[i].id[y]].time[0] - 48) * 10 + (a[base[i].id[y]].time[1] - 48)) * 60 + ((a[base[i].id[y]].time[3] - 48) * 10 + (a[base[i].id[y]].time[4] - 48)) + 1 ) * a[base[i].id[y]].rate;
		}
		cout << "\tГород:" << base[i].name << "\n\tОбщее время разговора: " << (int)base[i].hole_time / 3600 << " ч " << (int)(base[i].hole_time - ((int)base[i].hole_time / 3600) * 3600) / 60 << " м " << base[i].hole_time % 60 << " с \n\tОбщая цена: " << base[i].hole_price << "\n\n";
	}
}

void file_out(call*& a, int& base_len)
{
	ofstream fout;
	fout.open("result_base.txt");
	fout << base_len << "\n";
	for (int i = 0; i < base_len; i++)
	{
		fout << a[i].date << "\n";
		fout << a[i].time << "\n";
		fout << a[i].city.code << "\n";
		fout << a[i].city.name << "\n";
		fout << a[i].rate << "\n";
		fout << a[i].person1 << "\n";
		fout << a[i].person2 << "\n";
	}
	fout.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, u;
	cout << "Добрый день. Вас приветствует ПРСБЗ или программа работы с базой звонков.";

	string file = "base_atc.txt",str_read = "";
	ifstream fin;

	fin.open(file);
	getline(fin, str_read);
	int base_len = stoi(str_read);
	call* calls = (call*)calloc(base_len,sizeof(char*)*4+sizeof(double)+sizeof(char*)*2);
	for (int y = 0; y < base_len; y++)
	{
		calls[y].date = (char*)calloc(11, sizeof(char));
		fin.getline(calls[y].date, 11);
		calls[y].time = (char*)calloc(9, sizeof(char));
		fin.getline(calls[y].time,9);
		calls[y].city.code = (char*)calloc(7, sizeof(char));
		fin.getline(calls[y].city.code,7);
		calls[y].city.name = (char*)calloc(21, sizeof(char));
		fin.getline(calls[y].city.name,21);
		char* h =(char*)calloc(5,sizeof(char));
		fin.getline(h, 5);
		calls[y].rate = atof(h);
		free(h);
		calls[y].person1 = (char*)calloc(13, sizeof(char));
		fin.getline(calls[y].person1, 13);
		calls[y].person2 = (char*)calloc(13, sizeof(char));
		fin.getline(calls[y].person2, 13);
	}
	fin.close();

	cout << "Чем могу помочь вам?...\n";
	while (1)
	{
		cout << "1.Вывести данные базы звонков\n2.Дополнение уже существующей базы звонков\n3.Поиск в базе звонков по определенному аспекту\n4.Изменение или удаление уже существующего элемента базы звонков\n5.Время разговоров и их цена по городам\n6.Сохранение и выход из программы\n";
		u = da(6);
		switch (u) {
		case 1:
		{
			cout << "Вывести: \n1) Определенную ячейку \n2)Все ячейки базы клиентов\n";
			n = da(2);
			if (n == 1)
			{
				cout << "Введите номер ячейки:";
				n = da(base_len);
				out_base(calls, n, 1);
			}
			else
			{
				out_base(calls, base_len, 0);
			}
			break;
		}
		case 2:
		{
			cout << "Сколько клиентов вы хотите добавить в базу:";
			n = c_nat();
			cin.clear();
			cin.ignore(33000, '\n');
			base_up(calls, base_len, n);
			break;
		}
		
		
		case 3:
		{
			cout << "Выберите аспект по которому вы хотите искать:1)Город\n2)Тариф\n3)Номер телефона\n4)Дата разговора\n:";
			n = da(4);
			cin.clear();
			cin.ignore(33000, '\n');
			find_client(calls, base_len, n);
			break;
		}
		case 4:
		{
			cout << "Вы хотите изменить или удалить ячейку 1)Изменить 2)Удалить\n";
			n = da(2);
			cout << "Выберите номер ячейки:";
			int i = da(base_len);

			if (n == 1)
			{
				change(calls, base_len, i - 1);
			}
			else
			{
				delete_client(calls, base_len, i - 1);
			}
			break;
		}
		case 5:
		{
			calls_city_out(calls,base_len);
			break;
		}
		case 6:
		{
			file_out(calls, base_len);
			cout << "Пока-пока!!!";
			return 0;
		}
		}
	}
}