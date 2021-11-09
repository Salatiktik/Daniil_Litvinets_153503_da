//Лабораторная работа №4, Задание 14. Выполнил Литвинец Даниил Николаевич
/*сапер*/

#include <iostream>

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

char* s_c(int G)
{
    char* stroka = (char*)malloc(G * sizeof(char));
    
    int ch = 0;
    cin >> stroka;
    int R = 0;
    while (stroka[R] != '\n')
    {
        R++;
    }
    for (int i = 0; i < G; i++)
    {
        if ((stroka[i] != '*' && stroka[i] != '.')||G!=R)
        {
            ch++;
        }
    }
    while (ch != 0)
    {
        ch = 0;
        cout << "Неверный ввод строки поля. Вводите только * и . или строку только c " << G << " элементами \n";
        cin >> stroka;
        for (int i = 0; i < G; i++)
        {
            if ((stroka[i] != '*' && stroka[i] != '.'))
            {
                ch++;
            }
        }
        
    }
    return stroka;
}

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите размер поля N строк и M столбцов\n";
    int N = c_nat(), M = c_nat();
    char** pole = (char**)malloc(N * sizeof(char*));
    char* stroka = (char*)malloc(M * sizeof(char));
    for (int i = 0; i < N; i++) {
        pole[i] = (char*)malloc(M * sizeof(char));
    }
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " строка поля\n";
        stroka = s_c(M);
        pole[i] = stroka;
    }
    cout  << "╔ ";
    for (int z = 0; z < M; z++)
    {
        cout << "═ ";
    }
    cout << "╗\n";
    for (int i = 0; i < N; i++)
    {
        cout << "║ ";
        for (int z = 0; z < M; z++)
        {
            cout << pole[i][z] << " ";
        }
        cout << "║\n";
    }
    cout << "╚ ";
    for (int z = 0; z < M; z++)
    {
        cout << "═ ";
    }
    cout << "╝\n";

    int d = 0;

    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < M; z++)
        {
            if (pole[i][z] == '.')
            {
                //блок для угловых клеток
                if (i == 0 && z == 0)
                {
                    if (pole[1][0] == '*')
                        d++;
                    if (pole[1][1] == '*')
                        d++;
                    if (pole[0][1] == '*')
                        d++;
                    pole[i][z] = d;
                }
                if (i == N - 1 && z == 0)
                {
                    if (pole[N - 1][1] == '*')
                        d++;
                    if (pole[N - 2][1] == '*')
                        d++;
                    if (pole[N - 2][0] == '*')
                        d++;
                    pole[i][z] = d;
                }

                if (i == 0 && z == M - 1)
                {
                    if (pole[1][M - 1] == '*')
                        d++;
                    if (pole[1][M - 2] == '*')
                        d++;
                    if (pole[0][M - 2] == '*')
                        d++;
                    pole[i][z] = d;
                }
                if (i == N - 1 && z == M - 1)
                {
                    if (pole[N - 1][M - 2] == '*')
                        d++;
                    if (pole[N - 2][M - 2] == '*')
                        d++;
                    if (pole[N - 2][M - 1] == '*')
                        d++;
                    pole[i][z] = d;
                }
                //блок для пограничных строк и столбцов
                if (i == 0 && z != 0 && z != M - 1)
                {
                    if (pole[1][z + 1] == '*')
                        d++;
                    if (pole[1][z - 1] == '*')
                        d++;
                    if (pole[1][z] == '*')
                        d++;
                    if (pole[0][z - 1] == '*')
                        d++;
                    if (pole[0][z + 1] == '*')
                        d++;
                    pole[i][z] = d;
                }
                if (i == N - 1 && z != 0 && z != M - 1)
                {
                    if (pole[N - 2][z + 1] == '*')
                        d++;
                    if (pole[N - 2][z - 1] == '*')
                        d++;
                    if (pole[N - 2][z] == '*')
                        d++;
                    if (pole[N - 1][z - 1] == '*')
                        d++;
                    if (pole[N - 1][z + 1] == '*')
                        d++;
                    pole[i][z] = d;
                }
                if (z == 0 && i != 0 && i != N - 1)
                {
                    if (pole[i][1] == '*')
                        d++;
                    if (pole[i - 1][1] == '*')
                        d++;
                    if (pole[i + 1][1] == '*')
                        d++;
                    if (pole[i - 1][0] == '*')
                        d++;
                    if (pole[i + 1][0] == '*')
                        d++;
                    pole[i][z] = d;
                }

                if (z == M - 1 && i != 0 && i != N - 1)
                {
                    if (pole[i][M - 2] == '*')
                        d++;
                    if (pole[i - 1][M - 2] == '*')
                        d++;
                    if (pole[i + 1][M - 2] == '*')
                        d++;
                    if (pole[i - 1][M - 1] == '*')
                        d++;
                    if (pole[i + 1][M - 1] == '*')
                        d++;
                    pole[i][z] = d;
                }

                //стандартные точки
                if (z != 0 && i != 0 && i != N - 1 && z != M - 1)
                {
                    if (pole[i][z - 1] == '*')
                        d++;
                    if (pole[i][z + 1] == '*')
                        d++;
                    if (pole[i + 1][z] == '*')
                        d++;
                    if (pole[i - 1][z] == '*')
                        d++;
                    if (pole[i + 1][z + 1] == '*')
                        d++;
                    if (pole[i + 1][z - 1] == '*')
                        d++;
                    if (pole[i - 1][z + 1] == '*')
                        d++;
                    if (pole[i - 1][z - 1] == '*')
                        d++;
                    pole[i][z] = d;

                }
                d = 0;
            }
        }            
    }
    cout << "╔ ";
    for (int z = 0; z < M; z++)
    {
        cout << "═ ";
    }
    cout << "╗\n";
    for (int i = 0; i < N; i++)
    {
        cout << "║ ";
        for (int z = 0; z < M; z++)
        {
            if (pole[i][z] == '*')
                cout << pole[i][z] << " ";
            else
                cout << (int)pole[i][z] << " ";
        }
        cout << "║\n";
    }
    cout << "╚ ";
    for (int z = 0; z < M; z++)
    {
        cout << "═ ";
    }
    cout << "╝\n";

}
