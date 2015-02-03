#include "stdafx.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int MAX_SIZE = 100;
	int array[MAX_SIZE];
	int n;
	cout << "n= ";
	cin >> n;
	cout << "Array: ";
	for (int i = 0; i < n; i++)
	{
		array[i] = (rand() % 100) - 50;
		cout << array[i] << " ";
	}

	cout << "\n";

	// Удаление минимального
	int min = array[0];
	int minIdx = 0;
	for (i = 0; i < n; i++)
	{
		if (*(array + i) < min)
		{
			min = *(array + i);
			minIdx = i;
		}
	}

	for (i = minIdx; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;

	for (i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";

	// Добавление K элементов в конец
	int k;
	cout << "k= ";
	cin >> k;
	for (i = n; i < n + k; i++)
	{
		array[i] = (rand() % 100) - 50;
	}
	n += k;

	for (i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";

	//Циклический сдвиг на m элементов вправо
	int m;
	cout << "m=";
	cin >> m;
	int tempArray[MAX_SIZE];
	int tempIdx;;
	for (i = 0; i < n; i++)
	{
		tempIdx = i + m;
		if (tempIdx >= n)
		{
			tempIdx -= n;
		}

		tempArray[tempIdx] = array[i];
	}

	cout << "Array with shifted element: \n";
	for (i = 0; i < n; i++)
	{
		array[i] = tempArray[i];
		cout << array[i] << " ";
	}
	cout << "\n";

	// Поиск первого отрицательного
	int temp = 0;
	tempIdx = -1;
	
	for (i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			temp = array[i];
			tempIdx = i;
			break;
		}
	}
	if (tempIdx == -1)
	{
		cout << "Negative element not found.\n";
	}
	else
	{
		cout << "First negative element: " << temp << ". Index: " << tempIdx << ".\n";
	}

	// Сортировка простым выбором
	for (i = 0; i < n - 1; i++)
	{
		min = array[i];
		minIdx = i; 
		for (int j = i + 1; j < n; j++)
		if (array[j] <min)
		{
			min = array[j];
			minIdx = j;
		}
		array[minIdx] = array[i]; 
		array[i] = min;
	}

	cout << "Sorted array: \n";
	for (i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	cin >> n;
}


