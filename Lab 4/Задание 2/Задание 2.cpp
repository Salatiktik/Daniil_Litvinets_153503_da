#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int* arr, int first, int last) {
    int f = first, l = last;
    int mid = arr[(f + l) / 2];

    do {
        while (arr[f] < mid)
            f++;
        while (arr[l] > mid)
            l--;

        if (f <= l) {
            swap(arr[f], arr[l]);
            f++; l--;
        }
    } while (f < l);

    if (first < l) quicksort(arr, first, l);
    if (f < last) quicksort(arr, f, last);
}

void Shell(int* arr, int* way, int n) {
    int i, j, tmp, step, temp_w;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            tmp = arr[i]; temp_w = way[i];

            for (j = i; j >= step; j -= step) {
                if (tmp < arr[j - step]) {
                    arr[j] = arr[j - step]; way[j] = way[j - step];
                }
                else
                    break;
            }
            arr[j] = tmp;
            way[j] = temp_w;
        }
    }
}
int main()
{
    srand(time(NULL));
    int N, M;
    scanf_s("%d", &N);
    scanf_s("%d", &M);

    // Создание и заполнение массива
    int** array = (int**)calloc(N, sizeof(int*));
    for (int i = 0; i < N; i++)
        array[i] = (int*)calloc(M, sizeof(int));

    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf_s("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        quicksort(array[i], 0, M - 1);
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d\t", array[i][j]);
        printf("\n");
    }


    for (int n = 0; n < N; n++) {
        for (int i = 0; i < M; i++) {
            for (int j = M - 1; j > i; j--) {
                if (array[n][j] == array[n][i]) {
                    int a = j, b = j + 1;

                    while (a < M - 1)
                        swap(array[n][a++], array[n][b++]);
                }
            }
        }
    }


    int* size = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        while (array[i][size[i]] < array[i][size[i] + 1] && size[i] < M - 1)
            size[i]++;

        size[i]++;
        array[i] = (int*)realloc(array[i], size[i] * sizeof(int));
    }


    int* str = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        str[i] = i;

    Shell(size, str, N);


    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int z = 0; z < size[i]; z++)
            printf("%d\t", array[str[i]][z]);
        printf("\n");
    }
}

