
#include "stdafx.h"
#include "Circle.h"
using std::ostream;
using namespace std;
//�������� ����������
int _tmain()
{
	setlocale(LC_ALL, "Russian");

	Circle* circle1 = Circle::Create();
	circle1->Show();
	cout << *circle1;
	cout << "�������: " << circle1->GetArea() << "\n";
	cout << "����� ����: " << circle1->GetArcLength() << "\n";
	cout << "������ �� � ��� ���������� ����� (0, 0): " << (circle1->IsBelongsCircle(0, 0) ? "��" : "���") << "\n";
	circle1->Move(10, 10);
	cout << "����������� �� dx=10, dy=10" << "\n";
	circle1->Show();
	circle1->Scale(2);
	cout << "����������� � ��� ����\n";
	circle1->Show();

	Circle circle2;
	cin >> circle2;
	circle2.Show();
	cout << "������� �����. Ÿ ������:\n";
	Circle* cloneCircle2 = circle2.Clone();
	cloneCircle2->Show();
	getchar();
	getchar();
	return 0;
}

// ���������� ��������� ��� ������ ���������� �� �����
ostream& operator << (ostream& stream, const Circle& circle)
{
	stream << "������: " << circle.GetRadius() << "  X: " << circle.GetCenterX() << "  Y: " << circle.GetCenterY() << "\n";
	return stream;
}

// ���������� ��������� ��� ����� ���������� � ������
istream& operator >> (istream& stream, Circle& circle)
{
	cout << "������� ����� ������ ������, � ���������� � � y ������ ����������: ";
	double radius, x, y;
	stream >> radius >> x >> y;
	circle.SetRadius(radius);
	circle.SetCenterX(x);
	circle.SetCenterY(y);
	return stream;
}


