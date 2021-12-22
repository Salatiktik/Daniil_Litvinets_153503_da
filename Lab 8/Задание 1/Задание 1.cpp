// Задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
//объявление структур
struct person {
	string name;
	string patr;
	string last_name;
};

struct adress {
	string city;
	string street;
	string house;
};

struct base {
	person person_x;
	adress person_adress;
	int dis;
};
//сортировка по скидке
void qsort_mine(base*& a, int start, int end, int n)
{
	int s = start, e = end, middle = a[(start+end)/2].dis;
	if (n == 1)
	{
		do
		{
			while (a[s].dis < middle) s++;
			while (a[e].dis > middle) e--;
			if (s <= e)
			{
				base tmp = a[s];
				a[s] = a[e];
				a[e] = tmp;
				s++;
				e--;
			}
		} while (s <= e);
		if (s < end)qsort_mine(a, s, end, n);
		if (start < e)qsort_mine(a, start, e, n);
	}
	else
	{
		do {
			while (a[s].dis > middle) s++;
			while (a[e].dis < middle) e--;
			if (s < e)
			{
				base tmp = a[s];
				a[s] = a[e];
				a[e] = tmp;
				s++;
				e--;
			}
		} while (s < e);
		if (s < end)qsort_mine(a, s, end, n);
		if (start < e)qsort_mine(a, start, e, n);
	}
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
//перевод строки в маленький регистр для избежания ошибок поиска если пользователь введет не тот регистр
string little(string h)
{
	for (int i = 0; i < h.length(); i++)
	{
		h[i] = tolower(h[i]);
	}
	return h;
}
//проверка на ввод натуральных чисел в определенном промежутке
int da(int n)
{
	int x;
	while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x<=0||x>n)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Выберите из предложенных вариантов\n" << std::endl;
	}
	return x;
}
//ввод базы
void input_base(base*& a, int n, int& base_len, int y)
{
	if (y == 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Ячейка " << i + 1 << ":\n";
			cout << "\tФИО\n";
			cout << "\tВведите имя клиента:";
			cin >> a[i].person_x.name;
			cout << "\tВведите отчетсво клиента(если отсутствует введите -):";
			cin >> a[i].person_x.patr;
			cout << "\tВведите фамилию клиента:";
			cin >> a[i].person_x.last_name;
			cout << "\tАдресс клиента\n";
			cout << "\tГород проживания:";
			cin >> a[i].person_adress.city;
			cout << "\tУлица проживания:";
			cin >> a[i].person_adress.street;
			cout << "\tДом проживания(при наличии разделения дома на квартиры ввести сначала номер дома, слово квартира и номер квартиры):";
			cin >> a[i].person_adress.house;
			cout << "\nУ клиента есть скидка 1)Да 2)Нет:";
			int r = da(2);
			if (r == 1)
			{
				cout << "Введите целую скидку от 1 до 100:";
				a[i].dis = da(100);
			}
			else
			{
				a[i].dis = 0;
			}
			cout << "\n";
		}
	}
	else
	{
		for (int i = base_len; i < base_len+n; i++)
		{
			cout << "Ячейка " << i +1 << ":\n";
			cout << "\tФИО\n";
			cout << "\tВведите имя клиента:";
			cin >> a[i].person_x.name;
			cout << "\tВведите отчетсво клиента(если отсутствует введите -):";
			cin >> a[i].person_x.patr;
			cout << "\tВведите фамилию клиента:";
			cin >> a[i].person_x.last_name;
			cout << "\tАдресс клиента\n";
			cout << "\tГород проживания:";
			cin >> a[i].person_adress.city;
			cout << "\tУлица проживания:";
			cin >> a[i].person_adress.street;
			cout << "\tДом проживания(при наличии разделения дома на квартиры ввести сначала номер дома, двоеточие и номер квартиры):";
			string h;
			cin >> a[i].person_adress.house;
			cout << "\n\tУ клиента есть скидка 1)Да 2)Нет:";
			int r = da(2);
			if (r == 1)
			{
				cout << "Введите целую скидку от 1 до 100:";
				a[i].dis = da(100);
			}
			else
			{
				a[i].dis = 0;
			}
			cout << "\n";
		}
		base_len += n;
	}
	
}
//расширение памяти массива
void base_up(base*& a, int& base_len, int n)
{
	base* new_b = new base[n+base_len];
	for (int i = 0; i < base_len; i++)
	{
		new_b[i] = a[i];
	}
	delete[]a;
	a = new_b;
	input_base(a, n, base_len, 1);
}
//вывод базы
void out_base(base*& a, int i, int y)
{
	if (y == 1)
	{
		cout << "Ячейка " << i--;
		cout << "\tФИО\n";
		cout << "\tИмя клиента: ";
		cout << a[i].person_x.name;
		cout << "\n\tОтчетсво клиента: ";
		cout << a[i].person_x.patr;
		cout << "\n\tФамилия клиента: ";
		cout << a[i].person_x.last_name;
		cout << "\n\tАдресс клиента\n";
		cout << "\tГород проживания: ";
		cout << a[i].person_adress.city;
		cout << "\tУлица проживания: ";
		cout << a[i].person_adress.street;
		cout << "\tДом проживания: ";
		cout << a[i].person_adress.house;
		cout << "\nСкидка клиента: " << a[i].dis << "%\n\n";
	}
	else
	{
		int q = i;
		for (i = 0; i < q; i++)
		{
			cout << "Ячейка " << i+1;
			cout << "\tФИО\n";
			cout << "\tИмя клиента: ";
			cout << a[i].person_x.name;
			cout << "\n\tОтчетсво клиента: ";
			cout << a[i].person_x.patr;
			cout << "\n\tФамилия клиента: ";
			cout << a[i].person_x.last_name;
			cout << "\n\tАдресс клиента\n";
			cout << "\tГород проживания: ";
			cout << a[i].person_adress.city;
			cout << "\t\nУлица проживания: ";
			cout << a[i].person_adress.street;
			cout << "\t\nДом проживания: ";
			cout << a[i].person_adress.house;
			cout << "\nСкидка клиента: " << a[i].dis << "%\n\n";
		}
	}
}
//удаление старой базы и создание новой
void new_base(base*& prev, int& prev_len)
{
	cout << "Введите новый размер базы клиентов:\n";
	int n = c_nat();
	
	base* new_b = new base[n];
	for (int i = 0; i < prev_len; i++)
	{
		new_b[i] = prev[i];
	}
	delete[]prev;
	prev = new_b;
	prev_len = n;
	input_base(prev, prev_len, prev_len,0);
}
//поиск по определенному аспекту
void find_client(base*& a, int len, int n)
{
	switch (n)
	{
	case 1:
	{
		string name;
		cout << "Введите имя для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (little(a[i].person_x.name) == little(name))
			{
				mass[z] = i+1;
				z++;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		delete[] mass;
		break;
	}
	case 3:
	{
		string name;
		cout << "Введите отчество для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (little(a[i].person_x.patr) == little(name))
			{
				mass[z++] = i+1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		delete[] mass;
		break;
	}
	case 2:
	{
		string name;
		cout << "Введите фамилию для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (little(a[i].person_x.last_name) == little(name))
			{
				mass[z++] = i+1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		delete[] mass;
		break;
	}
	case 4:
	{
		string name;
		cout << "Введите город для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (little(a[i].person_adress.city) == little(name))
			{
				mass[z++] = i+1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t] , 1);
		}
		delete[] mass;
		break;
	}
	case 5:
	{
		string name;
		cout << "Введите улицу для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (little(a[i].person_adress.street) == little(name))
			{
				mass[z++] = i+1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		delete[] mass;
		break;
	}
	case 6:
	{
		int name;
		cout << "Введите величину скидки для поиска:";
		cin >> name;
		int* mass = new int[len];
		int z = 0;
		for (int i = 0; i < len; i++)
		{
			if (a[i].dis == name)
			{
				mass[z++] = i+1;
			}
		}
		cout << "Найдено " << z << " совпадений:\n";
		for (int t = 0; t < z; t++)
		{
			out_base(a, mass[t], 1);
		}
		delete[] mass;
		break;
	}
	}
}
//взаимодействие и изменение определенный полей базы
void change(base*& a, int len, int i)
{
	cout << "Что вы хотите изменить 1)ФИО 2) Адресс 3)Скидку\n";
	int g = da(3);
	switch (g)
	{
	case 1:
	{
		cout << "Что вы хотите изменить 1)Фамилию 2) Имя 3) Отчество\n";
		int y = da(3);
		switch (y)
		{
		case 1:
		{
			string ah;
			cout << "Введите новую фамилию:";
			cin >> a[i].person_x.last_name;
			cout << "Изменено успешно\n";
			break;
		}
		case 2:
		{
			string ah;
			cout << "Введите новое имя:";
			cin >> a[i].person_x.name;
			cout << "Изменено успешно\n";
			break;
		}
		case 3:
		{
			string ah;
			cout << "Введите новое отчество:";
			cin >> a[i].person_x.patr;
			cout << "Изменено успешно\n";
			break;
		}
		}
		break;
	}
	case 2:
	{
		cout << "Что вы хотите изменить 1)Город 2)Улицу 3)Дом\n";
		int y = da(3);
		switch (y) {
		case 1:
		{
			string ah;
			cout << "Введите город:";
			cin >> a[i].person_adress.city;
			cout << "Изменено успешно\n";
			break;
		}
		case 2:
		{
			string ah;
			cout << "Введите улицу:";
			cin >> a[i].person_adress.street;
			cout << "Изменено успешно\n";
			break;
		}
		case 3:
		{
			string ah;
			cout << "Введите дом(при наличии квартиры написать номер дома, двоеточие и номер квартиры):";
			cin >> a[i].person_adress.house;
			cout << "Изменено успешно\n";
			break;
		}

		}
		break;
		
	}
	case 3:
	{
		cout << "У клиента будет скидка 1)Да 2)Нет\n";
		int y = da(2);
		if (y == 1)
		{
			cout << "Введите новую скидку от 1 до 100:\n";
			a[i].dis = da(100);
			cout << "Изменено успешно\n";
			break;
		}
		else
		{
			a[i].dis = 0;
			cout << "Изменено успешно\n";
			break;
		}
	}
	}
}
//удаление одной ячейки
void delete_client(base*& a, int& len, int r)
{
	base* new_b = new base[len-1];
	int o = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == r )
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
	delete[]a;
	a = new_b;
	len--;

}

int main()
{
	setlocale(LC_ALL, "RU");
	int n,u,base_len;
	cout << "Добрый день. Вас приветствует ПРСБКМГ или программа работы с базой клиентов магазина Гаечка:";
	cout << "Так как это мой первый рабочий день создадим с вам для начала новую базу. На какое количество клиентов вы хотите создать базу?...";
	base_len = c_nat();

	base* client = new base[base_len];
	input_base(client, base_len,base_len,0);

	cout << "Прекрасно. В будущем вы сможете изменить свою базу и добавить в неё новых клиентов. Рада была вам помочь. Хотите продолжить работу? 1)Да 2)Нет";
	n = da(2);
	if (n == 2)
	{
		cout << "Пока пока!";
		exit;
	}

	cout << "Чем могу помочь вам?...";
	while (true)
	{
		cout << "1. Создание новой базы клиентов \n2.Вывести данные базы клиентов\n3.Дополнение уже существующей базы клиентов\n4.Поиск в базе клиентов по определенному аспекту\n5.Изменение или удаление уже существующего элемента базы клиентов\n6.Сортировка по определенному аспекту\n";
		u = da(6);
		switch(u){
		case 1:
		{
			cout << "Вы уверены что хотите удалить старую базу и создать новую? \n1)Да 2)Нет\n";
			n = da(2);
			if (n == 1)
				new_base(client, base_len);
			else
				break;
		}
		case 2:
		{
			cout << "Вывести: \n1) Определенную ячейку \n2)Все ячейки базы клиентов\n";
			n = da(2);
			if (n == 1)
			{
				cout << "Введите номер ячейки:";
				n = da(base_len);
				out_base(client, n, 1);
			}
			else
			{
				out_base(client, base_len, 0);
			}
			break;
		}
		case 3:
		{
			cout << "Сколько клиентов вы хотите добавить в базу:";
			n = c_nat();
			base_up(client, base_len, n);
			break;
		}
		case 4:
		{
			cout << "Выберите аспект по которому вы хотите искать:1)Имя\n2)Фамилия\n3)Отчество\n4)Город проживания \n5)Улица проживания\n6)Предоставляемая скидка\n:";
			n = da(6);
			find_client(client, base_len, n);
			break;
		}
		case 5:
		{
			cout << "Вы хотите изменить или удалить ячейку 1)Изменить 2)Удалить\n";
			n = da(2);
			cout << "Выберите номер ячейки:";
			int i = da(base_len);
			if (n == 1)
			{
				change(client, base_len,i-1);
			}
			else
			{
				delete_client(client, base_len, i-1);
			}
			break;
		}
		case 6:
		{
			cout << "Отсортировать клиентов по скидкам 1)к большей 2)к меньшей:";
			n = da(2);
			qsort_mine(client, 0, base_len-1, n);
			break;
		}
		}	
	}
}