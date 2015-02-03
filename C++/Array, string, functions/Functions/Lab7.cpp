#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void Print(char* family, char* name = "Ivan", int age = 18)
{
	cout << "Family: " << family << " Name: " << name << " Age: " << age << "\n";
}

int maxParameter(int k, ...)
{
	int *p = &k; 
	int max = *p;
	for (; k != 0; k--)
	{
		if (*(++p) > max)
		{
			max = *p;
		}
	}
	
	return max;
}
template <class T>
void Init(T* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = (rand() % 100) - 50;
	}
}

template <class T>
void Show(T* array, int n)
{
	if (array == NULL)
	{
		cout << "Error. Array no initialized";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

int GetCountNegativeElement(int* array, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			count++;
		}
	}
	return count;
}

int GetCountNegativeElement(double* array, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			count++;
		}
	}
	return count;
}

template <class T>
int GetCountNegativeElement(T* array, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			count++;
		}
	}
	return count;
}

float function(float x)
{
	return 3*sin(sqrt(x)) + 0.35*x - 3.8;
}

float der(float x)
{
	return (3*cos(sqrt(x))) / (2*sqrt(x)) + 0.35;
}

typedef float(*func) (float);
void methodNewton(func f, func g,  float e)
{
	float x1 = 2;
	float x2 = 3;
	int i;

	i = 1;
	x2 = x1 - (f(x1) / g(x1));
	while (fabs(x2 - x1)>e)
	{
		x1 = x2;
		x2 = x1 - (f(x1) / g(x1));
		i++;
	}
	cout << "\n y= " << x2;
}

void main()
{
	Print("Ivanov", "Petr", 24);
	Print("Ivanov", "Ignat");
	Print("Ivanov");
	cout << maxParameter(3, 17, 45, 9) <<"\n"; 
	cout << maxParameter(6, 1, 2, 3, 4, 5, 6) << "\n";

	int n;
	cout << "n = ";
	cin >> n;
	int* array1 = new int[n];
	double* array2 = new double[n];
	Init(array1, n);
	Show(array1, n);
	cout << "Count negative elements: " << GetCountNegativeElement(array1, n) << "\n";

	Init(array2, n);
	Show(array2, n);
	cout << "Count negative elements: " << GetCountNegativeElement(array2, n) << "\n";

	methodNewton(function, der, 0.0001);


	getchar();
	getchar();
}

