#include "stdafx.h"
#include <iostream>
using namespace std;

struct Date
{
	int day;
	char* month;
	int year;
};

Date CreateDate()
{
	Date temp;
	cout << "Enter day: ";
	cin >> temp.day;
	cout << "Enter month: ";
	temp.month = new char[10];
	cin >> temp.month;
	cout << "Enter year: ";
	cin >> temp.year;
	cout << "\n";
	return temp;
}

Date* CreateArrayDate(int n)
{
	return new Date[n];
}

void PrintDate(Date date)
{
	cout << "Day: " << date.day << " Month: " << date.month << " Year:" << date.year << "\n";
}

void PrintDate(Date* array, int n)
{
	if (array == NULL)
	{
		cout << "Error. Array wasn't initialize";
	}
	for (int i = 0; i < n; i++)
	{
		PrintDate(array[i]);
	}
	cout << "\n";
}

void Init(Date* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = CreateDate();
	}
}

Date* SearchDate(Date* array, int n, int &count)
{
	if (array == NULL)
	{
		cout << "Error. Array wasn't initialize";
	}
	int j = 0;
	Date* temp = new Date[n];
	for (int i = 0; i < n; i++)
	{
		if (!strcmp(array[i].month, "June") | !strcmp(array[i].month, "July") | !strcmp(array[i].month, "August"))
		{
			temp[j] = array[i];
			j++;
		}
	}

	count = j;
	return temp;
}

char* CreateString(int n)
{
	return new char[n];
}

char** CreateArrayString(int n, int m)
{
	char** temp = new char*[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = CreateString(m);
	}

	return temp;
}

void Init(char** str, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i << " string: ";
		cin >> str[i];
	}
}

void PrintString(char** str, int n, int m)
{
	if (str == NULL)
	{
		cout << "Error. String wasn't initialize";
	}
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << "\n";
	}
}

void DeleteString(char** str, int &n, int m, int idxStr)
{
	if ((idxStr < 0) | (idxStr > n))
	{
		cout << "Incorrect string number";
	}
	if (str == NULL)
	{
		cout << "Error. String wasn't initialize";
	}
	for (int i = idxStr; i < n - 1; i++)
	{
		str[i] = str[i + 1];
	}

	n--;
}

void main()
{
	int n;
	cout << "n =";
	cin >> n;
	Date* array = CreateArrayDate(n);
	Init(array, n); 
	PrintDate(array, n);
	int count = 0;
	Date* result = SearchDate(array, n, count);
	if (count == 0)
	{
		cout << "Objects not found\n";
	}
	else
	{
		PrintDate(result, count);
	}
	cout << "n = ";
	cin >> n;
	int m;
	cout << "m = ";
	cin >> m;
	char ** str = CreateArrayString(n, m);
	Init(str, n, m);
	PrintString(str, n, m);
	cout << "Enter number string: ";
	int strIdx;
	cin >> strIdx;
	DeleteString(str, n, m, strIdx);
	PrintString(str, n, m);
	cin >> n;
}

