/////////////////////////////////////////////////////////////////////////////
// Прикладное программирование
// Лабораторная работа №3. Вариант 3. Матрица
// Гаврилина О.А., гр.3301, 2013г.
// 
// Кафедра Прикладной и компьютерной оптики, http://aco.ifmo.ru
// Университет ИТМО
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "stdafx.h"

using namespace std;
#if !defined CIRCLE
#define CIRCLE
/////////////////////////////////////////////////////////////////////////////
// Описание класса "Окружность"
class Circle
{
private:
	// Радиус окружности
	double radius;

	// Координаты центра окружности 
	double centerX, centerY;

public:
	friend ostream& operator << (ostream& a, const Circle& circle);
	friend istream& operator >> (istream& stream, Circle& circle);
	// Конструктор по умолчению
	Circle()
	{
		Circle::radius = 0;
		Circle::centerX = 0;
		Circle::centerY = 0;
	}

	// Полный конструктор
	// radius - радиус окружности
	// x, y - коориднаты центра окружности
	Circle(double radius, double x, double y)
	{
		Circle::radius = radius;
		Circle::centerX = x;
		Circle::centerY = y;
	}

	// Конструктор копирования
	Circle(const Circle& circle)
	{
		Circle::radius = circle.radius;
		Circle::centerX = circle.centerX;
		Circle::centerY = circle.centerY;
	}

	//Деструктор
	~Circle()
	{


	}

	// Получение радиуса
	double GetRadius() const
	{
		return radius;
	}

	// Присваивание радиуса
	void SetRadius(double radius)
	{
		this->radius = radius;
	}

	// Получение координаты Х центра окружности.
	double GetCenterX() const
	{
		return centerX;
	}

	// Присваивание координаты Х центра
	void SetCenterX(double x)
	{
		this->centerX = x;
	}

	// Получение координаты Y центра окружности.
	double GetCenterY() const
	{
		return centerY;
	}

	// Присваивание координаты Х центра
	void SetCenterY(double y)
	{
		this->centerY = y;
	}

	// Перенос окружности на расстояние dx, dy
	void Move(double dx, double dy)
	{
		this->centerX = this->centerX + dx;
		this->centerY = this->centerY + dy;
	}

	// Получить площадь окружности
	double GetArea() const
	{
		return atan(1) * 4 * (this->radius * this->radius);
	}

	// Получить длину дуги окружности
	double GetArcLength() const
	{
		return 2 * atan(1) * 4 * this->radius;
	}


	// Проверить, попадает ли точка с координатами х, y в окружность
	bool IsBelongsCircle(double x, double y) const
	{
		if (x*x + y*y < this->radius)
		{
			return true;
		}

		return false;
	}

	// Изменить размеры окружности в n раз
	void Scale(double n)
	{
		this->radius = this->radius * n;
	}

	// Получить копию окружности
	Circle* Clone()
	{
		return new Circle(this->radius, this->centerX, this->centerY);
	}

	// Сравнить окружность с данной
	bool Equals(Circle circle)
	{
		if ((centerX == this->centerX) &&
			(centerY == this->centerY) &&
			(radius == this->radius))
		{
			return true;
		}

		return false;
	}

	// Вывести информацию об окружности в консоль
	void Show()
	{
		double rad = Circle::GetRadius();
		double x = Circle::GetCenterX();
		double y = Circle::GetCenterY();
		std::cout << "Радиус: " << rad << "  X: " << x << "  Y: " << y << "\n";
	}

	// Создать окружность с параметрами, заданными на консоли
	static Circle* Create()
	{
		double radius;
		cout << "Введите радиус: ";
		cin >> radius;
		double x;
		cout << "Введите Х: ";
		cin >> x;
		double y;
		cout << "Введите Y: ";
		cin >> y;

		return new Circle(radius, x, y);
	}

	// Перегрузка оператора для масштабирования окружности
	void operator*= (double a)
	{
		this->Scale(a);
	}

	//Перегрузка оператора для копирования окружности
	Circle operator= (Circle circle)
	{
		this->SetCenterX(circle.centerX);
		this->SetCenterY(circle.centerY);
		this->SetRadius(circle.radius);
	}

	//Перегрузка оператора для проверки двух окружностей на равенство
	bool operator== (Circle circle)
	{
		if (this->Equals(circle))
		{
			return true;
		}

		return false;
	}

	// Перегрузка оператора для проверки двух окружностей на неравенство
	bool operator!= (Circle circle)
	{
		if (this->Equals(circle))
		{
			return false;
		}

		return true;
	}

};

/////////////////////////////////////////////////////////////////////////////
#endif //defined CIRCLE

