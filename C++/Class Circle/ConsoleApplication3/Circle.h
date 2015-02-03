/////////////////////////////////////////////////////////////////////////////
// ���������� ����������������
// ������������ ������ �3. ������� 3. �������
// ��������� �.�., ��.3301, 2013�.
// 
// ������� ���������� � ������������ ������, http://aco.ifmo.ru
// ����������� ����
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "stdafx.h"

using namespace std;
#if !defined CIRCLE
#define CIRCLE
/////////////////////////////////////////////////////////////////////////////
// �������� ������ "����������"
class Circle
{
private:
	// ������ ����������
	double radius;

	// ���������� ������ ���������� 
	double centerX, centerY;

public:
	friend ostream& operator << (ostream& a, const Circle& circle);
	friend istream& operator >> (istream& stream, Circle& circle);
	// ����������� �� ���������
	Circle()
	{
		Circle::radius = 0;
		Circle::centerX = 0;
		Circle::centerY = 0;
	}

	// ������ �����������
	// radius - ������ ����������
	// x, y - ���������� ������ ����������
	Circle(double radius, double x, double y)
	{
		Circle::radius = radius;
		Circle::centerX = x;
		Circle::centerY = y;
	}

	// ����������� �����������
	Circle(const Circle& circle)
	{
		Circle::radius = circle.radius;
		Circle::centerX = circle.centerX;
		Circle::centerY = circle.centerY;
	}

	//����������
	~Circle()
	{


	}

	// ��������� �������
	double GetRadius() const
	{
		return radius;
	}

	// ������������ �������
	void SetRadius(double radius)
	{
		this->radius = radius;
	}

	// ��������� ���������� � ������ ����������.
	double GetCenterX() const
	{
		return centerX;
	}

	// ������������ ���������� � ������
	void SetCenterX(double x)
	{
		this->centerX = x;
	}

	// ��������� ���������� Y ������ ����������.
	double GetCenterY() const
	{
		return centerY;
	}

	// ������������ ���������� � ������
	void SetCenterY(double y)
	{
		this->centerY = y;
	}

	// ������� ���������� �� ���������� dx, dy
	void Move(double dx, double dy)
	{
		this->centerX = this->centerX + dx;
		this->centerY = this->centerY + dy;
	}

	// �������� ������� ����������
	double GetArea() const
	{
		return atan(1) * 4 * (this->radius * this->radius);
	}

	// �������� ����� ���� ����������
	double GetArcLength() const
	{
		return 2 * atan(1) * 4 * this->radius;
	}


	// ���������, �������� �� ����� � ������������ �, y � ����������
	bool IsBelongsCircle(double x, double y) const
	{
		if (x*x + y*y < this->radius)
		{
			return true;
		}

		return false;
	}

	// �������� ������� ���������� � n ���
	void Scale(double n)
	{
		this->radius = this->radius * n;
	}

	// �������� ����� ����������
	Circle* Clone()
	{
		return new Circle(this->radius, this->centerX, this->centerY);
	}

	// �������� ���������� � ������
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

	// ������� ���������� �� ���������� � �������
	void Show()
	{
		double rad = Circle::GetRadius();
		double x = Circle::GetCenterX();
		double y = Circle::GetCenterY();
		std::cout << "������: " << rad << "  X: " << x << "  Y: " << y << "\n";
	}

	// ������� ���������� � �����������, ��������� �� �������
	static Circle* Create()
	{
		double radius;
		cout << "������� ������: ";
		cin >> radius;
		double x;
		cout << "������� �: ";
		cin >> x;
		double y;
		cout << "������� Y: ";
		cin >> y;

		return new Circle(radius, x, y);
	}

	// ���������� ��������� ��� ��������������� ����������
	void operator*= (double a)
	{
		this->Scale(a);
	}

	//���������� ��������� ��� ����������� ����������
	Circle operator= (Circle circle)
	{
		this->SetCenterX(circle.centerX);
		this->SetCenterY(circle.centerY);
		this->SetRadius(circle.radius);
	}

	//���������� ��������� ��� �������� ���� ����������� �� ���������
	bool operator== (Circle circle)
	{
		if (this->Equals(circle))
		{
			return true;
		}

		return false;
	}

	// ���������� ��������� ��� �������� ���� ����������� �� �����������
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

