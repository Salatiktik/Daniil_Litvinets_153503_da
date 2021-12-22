// Задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h> 

using namespace std;

class student_adress
{
public:

    void pik(char a[50], char b[50])
    {
        int len_a = 0, len_b = 0;
        while (b[len_b++]);
        for (int i = 0; i < len_b; i++)
        {
            a[i] = b[i];
        }
        for (int i = len_b; i < 50; i++)
            a[i] = '\0';
    }
    void pik(int a[3], char b[3])
    {
        for (int i = 0; i < 3; i++)
        {
            a[i] = b[i];
        }
    }
    void set_city(char s_city[])
    {
        pik(city,s_city);
    }
    void set_street(char s_c[])
    {
        pik(street, s_c);
    }
    void set_h(char s_h[])
    {
        pik(house, s_h);
    }

    char* get_city()
    {
        return city;
    }
    char* get_street()
    {
        return street;
    }
    char* get_h()
    {
        return house;
    }
private:
    char city [50];
    char street[50];
    char house[50];
};

class student
{
public:

    void set_average()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3;
    }
    void set_l_n(char student_last_name[])
    {
        adress.pik(last_name,student_last_name);
    }

    void set_n(char student_name[])
    {
        adress.pik(name,student_name);
    }

    void set_p(char student_patr[])
    {
        adress.pik(patr, student_patr);
    }

    void set_m(int student_marks[3])
    {
        marks[0] = student_marks[0];
        marks[1] = student_marks[1];
        marks[2] = student_marks[2];

        set_average();
    }

    void set_a_c(char s_city[])
    {
        adress.set_city(s_city);
    }

    void set_a_s(char s_street[])
    {
        adress.set_street(s_street);
    }

    void set_a_h(char s_house[])
    {
        adress.set_h(s_house);
    }

    char* get_l_n()
    {
        return last_name;
    }

    char* get_n()
    {
        return name;
    }

    char* get_p()
    {
        return patr;
    }

    int* get_m()
    {
        return marks;
    }

    char* get_a_c()
    {
        return adress.get_city();
    }

    char* get_a_s()
    {
        return adress.get_street();
    }

    char* get_a_h()
    {
        return adress.get_h();
    }

    double get_av()
    {
        return average;
    }
private:
    char name [50];
    char last_name [50];
    char patr[50];

    int marks[3];

    double average;

    student_adress adress;
};

void pik(char a[50], char b[])
{
    int len_a = 0, len_b = 0;
    while (b[len_b++]);
    for (int i = 0; i < len_b; i++)
    {
        a[i] = b[i];
    }
    for (int i = len_b; i < 50; i++)
        a[i] = '\0';
}

void qsort_out(student*& a, int start, int end)
{
    int s = start, e = end;
    char middle [50];
    pik(middle, a[(start + end) / 2].get_l_n());
    do
    {
        while (a[s].get_l_n() < middle) s++;
        while (a[e].get_l_n() > middle) e--;
        if (s <= e)
        {
            student tmp = a[s];
            a[s] = a[e];
            a[e] = tmp;
            s++;
            e--;
        }
    } while (s <= e);
    if (s < end)qsort_out(a, s, end);
    if (start < e)qsort_out(a, start, e);
}

//проверка на ввод натуральных чисел в определенном промежутке
double da(double n)
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

int da(int n)
{
    int x;
    while (!(std::cin >> x) || std::cin.peek() != '\n' || x <= 0 || x > n)
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

//взаимодействие и изменение определенный полей базы

void out_base(student*& a, int i, int y)
{
    if (y == 1)
    {
        cout << "\n\n\nЯчейка " << i + 1;
        cout << "\tФИО\n";
        cout << "\n\tФамилия абитуриента: ";
        cout << a[i].get_l_n();
        cout << "\n\tИмя абитуриента: ";
        cout << a[i].get_n();
        cout << "\n\tОтчетсво абитуриента: ";
        cout << a[i].get_p();
        cout << "\n\n\tАдресс абитуриента\n";
        cout << "\n\tГород проживания: ";
        cout << a[i].get_a_c();
        cout << "\n\tУлица проживания: ";
        cout << a[i].get_a_s();
        cout << "\n\tДом проживания: ";
        cout << a[i].get_a_h();
        cout << "\n\n\tОтметки по вступительным испытаниям абитуриента\n\n";
        cout << "\tСольфеджио: ";
        cout << a[i].get_m()[0];
        cout << "\n\tИсполнение камерной программы: ";
        cout << a[i].get_m()[1];
        cout << "\n\tИсполнение оперной программы: ";
        cout << a[i].get_m()[2];
        cout << "\n\tИтоговый средний балл: ";
        cout << a[i].get_av();
    }
    else
    {
        int q = i;
        for (i = 0; i < q; i++)
        {
            cout << "\n\n\nЯчейка " << i + 1;
            cout << "\tФИО\n";
            cout << "\n\tФамилия абитуриента: ";
            cout << a[i].get_l_n();
            cout << "\n\tИмя абитуриента: ";
            cout << a[i].get_n();
            cout << "\n\tОтчетсво абитуриента: ";
            cout << a[i].get_p();
            cout << "\n\n\tАдресс абитуриента\n";
            cout << "\n\tГород проживания: ";
            cout << a[i].get_a_c();
            cout << "\n\tУлица проживания: ";
            cout << a[i].get_a_s();
            cout << "\n\tДом проживания: ";
            cout << a[i].get_a_h();
            cout << "\n\n\tОтметки по вступительным испытаниям абитуриента\n\n";
            cout << "\tСольфеджио: ";
            cout << a[i].get_m()[0];
            cout << "\n\tИсполнение камерной программы: ";
            cout << a[i].get_m()[1];
            cout << "\n\tИсполнение оперной программы: ";
            cout << a[i].get_m()[2];
            cout << "\n\tИтоговый средний балл: ";
            cout << a[i].get_av();
        }
    }
}

//ввод в файл базы

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

void find_client(student*& a, int len, int n)
{
    switch (n)
    {
    case 1:
    {
        char h [50];
        cout << "Введите город для поиска:";
        cin.getline(h, 50);
        int* mass = new int[len];
        int z = 0;
        for (int i = 0; i < len; i++)
        {
            if (compare(h,a[i].get_a_c()))
            {
                mass[z++] = i;
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
        cout << "Вывести все баллы 1)больше введенного 2) меньше веденного";
        int u = da(2);
        cout << "Введите средний балл для поиска: ";
        double ball = da(5);
        switch (u)
        {
        case 2:
        {
            int* mass = new int[len];
            int z = 0;
            for (int i = 0; i < len; i++)
            {
                if (ball>a[i].get_av())
                {
                    mass[z++] = i ;
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
        case 1:
        {
            int* mass = new int[len];
            int z = 0;
            for (int i = 0; i < len; i++)
            {
                if (ball < a[i].get_av())
                {
                    mass[z++] = i;
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
    }
}

void edit_file(student* e, int i)
{
    FILE* f;
    fopen_s(&f, "base_abitura.txt", "rb+");
    fseek(f,(i)*(int)sizeof(student),0);
    fwrite((char*)&e[i], sizeof(student), 1, f);

    fclose(f);
}

//ввод базы
void append_base(student*& base, int n, int& base_len)
{
    for (int y = base_len; y < base_len + n; y++)
    {
        char h[50];
        cout << "\nВНИМАНИЕ ВВОД ОСУЩЕСТВЛЯЕТСЯ ЛАТИНСКИМИ БУКВАМИ!!!";
        cout << "\n\tВведите фамилию абитуриента: ";
        cin.getline(h,50);
        base[y].set_l_n(h);
        cout << "\n\tВведите имя абитуриента: ";
        cin.getline(h, 50);
        base[y].set_n(h);
        cout << "\n\tВведите отчество абитуриента: ";
        cin.getline(h, 50);
        base[y].set_p(h);

        cout << "\nВведите оценки абитуриента(от 1 до 5): ";
        int marks [3];
        cout << "\n\tВведите оценку за сольфеджио: ";
        marks[0] = da(5);
        cout << "\n\tВведите оценку за исполнение камерной программы: ";
        marks[1] = da(5);
        cout << "\n\tВведите оценку за исполнение оперной программы: ";
        marks[2] = da(5);
        base[y].set_m(marks);
        
        base[y].set_average();
        
        cout << "\nВведите адресс проживания абитуриента: ";
        cout << "\n\tГород проживания: ";
        cin.ignore(50, '\n');
        cin.getline(h, 50);
        base[y].set_a_c(h);
        cout << "\n\tУлицу проживания: ";
        cin.getline(h, 50);
        base[y].set_a_s(h);
        cout << "\n\tДом проживания(при наличии квартиры писать в формате дом:квартира): ";
        cin.getline(h, 50);
        base[y].set_a_h(h);
        edit_file(base, y);
    }
    base_len += n;
}

void base_rewrite(student* a, int i, int& len)
{
    cout << 1;
    FILE* f;
    fopen_s(&f, "base_abitura.txt", "rb+");
    cout << 1;
    for (int y = i; y < len + 2 ; y++)
    {
        fseek(f, i * (int)sizeof(student), 0);

        fwrite((char*)&a[i], sizeof(student), 1, f);
    }

    fseek(f, 0, 0);

    _chsize(_fileno(f), sizeof(student) * (len-1));

    fclose(f);

}

void base_up(student*& a, int& base_len, int n)
{
    a = (student*)realloc(a, (base_len + n)*sizeof(student));
    append_base(a, n, base_len);
}

student* load_base(student* a, int& len)
{
    FILE* f;
    student* Load = 0;
    fopen_s(&f, "base_abitura.txt", "rb+");

    student Pars;


    while (fread((char*)&Pars,sizeof(student), 1, f)) {
        
        Load = (student*)realloc(Load, ++len * sizeof(student));
        Load[len - 1] = Pars;
    }
    fclose(f);
    free(a);
    return Load;
}

void delete_client(student*& a, int& len, int r)
{
    base_rewrite(a, r, len);
    student* new_b = (student*)calloc(len - 1, sizeof(student));
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
}

void change(student*& base, int len, int i)
{
    cout << "Что вы хотите изменить 1)ФИО 2)Адресс 3)Оценки\n";
    int g = da(3);
    switch (g)
    {
    case 1:
    {
        cout << "Что вы хотите изменить 1)Фамилию 2)Имя 3)Отчество\n";
        int t = da(3);
        switch (t)
        {
        case 1:
        {
            cout << "Введите новую фамилию: ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_l_n(h);
            cout << "Изменено\n\n";
            break;
        }
        case 2:
        {
            cout << "Введите новое имя: ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_n(h);
            cout << "Изменено\n\n";
            break;
        }
        case 3:
        {
            cout << "Введите новое отчество: ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_p(h);
            cout << "Изменено\n\n";
            break;
        }
        }
        break;
    }
    case 2:
    {
        cout << "Что вы хотите изменить 1)Город 2)Улицу 3)Дом\n";
        int t = da(3);
        switch (t)
        {
        case 1:
        {
            cout << "Введите новый город проживания: ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_a_c(h);
            cout << "Изменено\n\n";
            break;
        }
        case 2:
        {
            cout << "Введите новую улицу проживания: ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_a_s(h);
            cout << "Изменено\n\n";
            break;
        }
        case 3:
        {
            cout << "Введите новый дом проживания(в случае деления на квартиры ввести дом:квартира): ";
            char h[50];
            cin.ignore(33000, '\n');
            cin.getline(h, 50);
            base[i].set_a_h(h);
            cout << "Изменено\n\n";
            break;
        }
        }
        break;
    }
    case 3:
    {
        cout << "Введите новые оценки:";
        int marks[3];
        cout << "\nВведите оценку за сольфеджио: ";
        marks[0] = da(5);
        cout << "\nВведите оценку за исполнение камерной программы: ";
        marks[1] = da(5);
        cout << "\nВведите оценку за исполнение оперной программы: ";
        marks[2] = da(5);
        base[i].set_m(marks);

        base[i].set_average();
        break;
    }
    }
    edit_file(base, i);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, u;
	cout << "Добрый день. Вас приветствует ПРСБА или программа работы с базой абитуриентов.";

	ifstream fin;  

    student* base = new student[1];
    cout << sizeof(base[0]) << "\n";

    int base_len = 0;

    base = load_base(base,base_len);
    if (!base_len) base = (student*)calloc(1, sizeof(student));


    if (base_len != 0) 
    {
        cout << "На данный момент в базе имеются данные " << base_len << " абитуриентов";
    }
    else
    {
        cout << "На данный момент база пуста";
    }

    out_base(base, base_len, 0);

	cout << "Чем могу помочь вам?...\n";
	while (1)
	{
		cout << "1.Вывести данные базы абитуриентов\n2.Дополнение уже существующей базы абитуриентов\n3.Поиск в базе абитуриентов по определенному аспекту\n4.Изменение или удаление уже существующего элемента базы абитуриентов\n5.Отсортировать базу по определенному аспекту\n6.Сохранение и выход из программы\n";
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
				out_base(base, n, 1);
			}
			else
			{
				out_base(base, base_len, 0);
			}
			break;
		}
		case 2:
		{
			cout << "Сколько абируентов вы хотите добавить в базу:";
			n = c_nat();
			cin.clear();
			cin.ignore(33000, '\n');
			base_up(base, base_len, n);
			break;
		}
		case 3:
		{
			cout << "Выберите аспект по которому вы хотите искать:1)Город\n2)Средний балл\n:";
			n = da(2);
			cin.clear();
			cin.ignore(33000, '\n');
			find_client(base, base_len, n);
			break;
		}
		case 4:
		{
			cout << "Вы хотите изменить или удалить ячейку 1)Изменить 2)Удалить\n";
			n = da(2);
			cout << "Выберите номер ячейки:";
			int i = da(base_len);
			cin.clear();
			cin.ignore(33000, '\n');
			if (n == 1)
			{
				change(base, base_len, i - 1);
			}
			else
			{
				delete_client(base, base_len, i - 1);
                base = (student*)calloc(0, sizeof(student));
                base_len = 0;
                load_base(base, base_len);
			}
			break;
		}
		case 5:
		{
            qsort_out(base, 0, base_len - 1);
            out_base(base, base_len, 0);
		}
		}
	}
}