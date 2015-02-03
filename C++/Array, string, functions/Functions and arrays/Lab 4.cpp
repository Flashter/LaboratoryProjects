#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_SIZE = 100;
#define _CRT_SECURE_NO_WARNINGS
void Init(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = (rand() % 100) - 50;
	}
}

void Init(int array[MAX_SIZE][MAX_SIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j] = (rand() % 50) - 50;
		}
	}
}

void Show(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void Show(int array[MAX_SIZE][MAX_SIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void DeleteEven(int array[], int &n)
{
	int j = 0;
	for (int i = 0; i < n; i += 2)
	{
		array[j] = array[i];
		j++;
	}
	n = j;
}

void Turn(int array[MAX_SIZE][MAX_SIZE], int n, int m)
{
	for (int j = 1; j < m; j += 2)
	{
		for (int i = 0; i < n / 2 ; i++)
		{
			swap(array[i][j], array[n - i - 1][j]);
		}
	}
}

int GetWordCount(char* str)
{
	
     strcat(str," ");
	int count = 0;
	int length = strlen(str);
	for (int i = 0; i < length - 1; i++)
	{
		if ((str[i] != ' ') && (str[i + 1] == ' '))
		{
			count++;
		}
	}

	return count;
}

void main()
{
	int array1[MAX_SIZE];
	int n;
	int m;
	cout << "n= ";
	cin >> n;
	cout << "Array: ";
	Init(array1, n);
	Show(array1, n);
	DeleteEven(array1, n);
	Show(array1, n);

	int array2[MAX_SIZE][MAX_SIZE];
	cout << "n = ";
	cin >> n;
	cout << "\nm = ";
	cin >> m;
	Init(array2, n, m);
	Show(array2, n, m);
	Turn(array2, n, m);
	Show(array2, n, m);

	char str[MAX_SIZE];
	puts("string: ");
	gets(str);
	gets(str);
	cout << "Word count: " << GetWordCount(str);
	cin >> m;
	cin >> m;
}


