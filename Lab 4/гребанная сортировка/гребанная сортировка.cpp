#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <iomanip>

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

void shellsort(int* arr, int* way, int n) {
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
	int N, M;
	scanf_s("%d", &N);
	scanf_s("%d", &M);

	int** arr = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		arr[i] = (int*)calloc(M, sizeof(int));
	}

	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			scanf_s("%d", &arr[i][z]);
		}
	}



	for (int i = 0; i < N; i++)
	{
		quicksort(arr[i], 0, M - 1);
	}

	for (int i = 0; i < N; i++) {
		for (int z = 0; z < M; z++)
			printf("%d\t", arr[i][z]);
		printf("\n");
	}printf("\n");



	for (int n = 0; n < N; n++) {
		for (int i = 0; i < M; i++) {
			for (int j = M - 1; j > i; j--) {
				if (arr[n][j] == arr[n][i]) {
					int a = j, b = j + 1;

					while (a < M - 1)
						swap(arr[n][a++], arr[n][b++]);
				}
			}
		}
	}


	int* size = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) 
	{
		while ((arr[i][size[i]] < arr[i][size[i] + 1]) && size[i] < M - 1)
		{
			size[i]++;
		}

		size[i]++;
		arr[i] = (int*)realloc(arr[i], size[i] * sizeof(int));
	}

	int* way = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		way[i] = i;
	}

	shellsort(size, way, N);

	for (int i = 0; i < N; i++) {
		for (int z = 0; z < size[i]; z++)
			printf("%d\t", arr[way[i]][z]);
		printf("\n");
	}printf("\n");

	
}