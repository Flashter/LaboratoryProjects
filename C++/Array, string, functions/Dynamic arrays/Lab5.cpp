#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

void Init(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = (rand() % 100) - 50;
	}
}

void Init(int** array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j] = (rand() % 50) - 50;
		}
	}
}

void Show(int* array, int n)
{
	if (array == NULL)
	{
		cout << "Error. Array no initialized\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";


}

void Show(int** array, int n, int m)
{
	if (array == NULL)
	{
		cout << "Error. Array no initialized\n";
		return;
	}

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

void DeleteFirstNegativeElement(int* array, int &n)
{
	if (array == NULL)
	{
		cout << "Error. Array no initialized\n";
		return;
	}

	int firstNegativeElementIdx = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			firstNegativeElementIdx = i;
			break;
		}
	}

	if (firstNegativeElementIdx != -1)
	{
		for (int i = firstNegativeElementIdx; i < n - 1; i++)
		{
			array[i] = array[i + 1];
		}

		n--;
	}
}

int** CreateMatrix(int n, int m)
{
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	return matrix;
}

int* CreateArray(int n)
{
	int* array = new int[n];
	return array;
}

int** AddColumn(int** array, int n, int &m, int idxCol)
{
	if (array == NULL)
	{
		cout << "Error. Array no initialized\n";
		return array;
	}

	if ((idxCol < 0) & (idxCol > 3))
	{
		cout << "Error. Incorrect column\n";
		return array;
	}
    m++;
	int** tempArray = CreateMatrix(n, m);
	for (int i = 0; i < idxCol; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tempArray[j][i] = array[j][i];
		}
	}

	for (int j = 0; j < n; j++)
	{
		tempArray[j][idxCol] = (rand() % 100) - 50;
	}

	for (i = idxCol + 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tempArray[j][i] = array[j][i - 1];
		}
	}

	return tempArray;
}
void main()
{
	int n;
	cout << "n= ";
	cin >> n;
	int k;
	int* array1 = NULL;
	do
	{
		cout << "1.Create array\n";
		cout << "2.Print array\n";
		cout << "3.Delete element\n";
		cout << "4.Exit\n";
		cin >> k;
		switch (k)
		{
		case 1:
		{
				  array1 = CreateArray(n);
				  Init(array1, n);
		}
			break;
		case 2:
		{
				  Show(array1, n);
		}
			break;
		case 3:
		{
				  DeleteFirstNegativeElement(array1, n);
		}
			break;
		}

	}while (k != 4);

	cout << "n= ";
	cin >> n;
	int m;
	cout << "m= ";
	cin >> m;
	int** array2 = NULL;
	do
	{
		cout << "1.Create matrix\n";
		cout << "2.Print matrix\n";
		cout << "3.Add column\n";
		cout << "4.Exit\n";
		cin >> k;
		switch (k)
		{
		case 1:
		{
				  array2 = CreateMatrix(n, m);
				  Init(array2, n, m);
		}
			break;
		case 2:
		{
				  Show(array2, n, m);
		}
			break;
		case 3:
		{
				  int idxCol;
				  cout << "Enter number column: ";
				  cin >> idxCol;
				  array2 = AddColumn(array2, n, m, idxCol);
		}
			break;
		}

	} while (k != 4);
}