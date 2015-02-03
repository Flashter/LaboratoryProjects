#include "stdafx.h"
#include <math.h>
#include <iostream>

using namespace std;
const double eps = 0.000001;

double function(double x)
{
	return 2 * x - cos(x);
}

double NewtonMethod(double a, double b)
{
	double oneDer, twoDer, x, Fx, d;
	oneDer = 2 + sin(a);
	twoDer = cos(a);
	if (oneDer*twoDer > 0)
	{
		x = b;
	}
	else x = a;
	do
	{
		Fx = function(x);
		oneDer = 2 + sin(x);
		x = x - Fx / oneDer;
		d = x - b;
		b = x;
	} while (abs(d) > eps);
	if ((x < a) | (x > b))
	{
		cout << "На данном отрезке нет корней \n";
		system("pause");
		exit(1);
	}
	return x;
}

int _tmain()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	cout << "Введите начало отрезка ";
	cin >> a;
	cout << "Введите конец отрезка ";
	cin >> b;

	cout << "Метод Ньютона: " << NewtonMethod(a, b) << "\n";

	system("PAUSE");
	return 0;
}