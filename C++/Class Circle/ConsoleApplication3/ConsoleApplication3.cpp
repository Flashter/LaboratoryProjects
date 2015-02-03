
#include "stdafx.h"
#include "Circle.h"
using std::ostream;
using namespace std;
//Тестовое приложение
int _tmain()
{
	setlocale(LC_ALL, "Russian");

	Circle* circle1 = Circle::Create();
	circle1->Show();
	cout << *circle1;
	cout << "Площадь: " << circle1->GetArea() << "\n";
	cout << "Длина дуги: " << circle1->GetArcLength() << "\n";
	cout << "Входит ли в эту окружность точка (0, 0): " << (circle1->IsBelongsCircle(0, 0) ? "Да" : "Нет") << "\n";
	circle1->Move(10, 10);
	cout << "Передвигаем на dx=10, dy=10" << "\n";
	circle1->Show();
	circle1->Scale(2);
	cout << "Увеличиваем в два раза\n";
	circle1->Show();

	Circle circle2;
	cin >> circle2;
	circle2.Show();
	cout << "Создаем копию. Её данные:\n";
	Circle* cloneCircle2 = circle2.Clone();
	cloneCircle2->Show();
	getchar();
	getchar();
	return 0;
}

// Перегрузка оператора для вывода окружности на экран
ostream& operator << (ostream& stream, const Circle& circle)
{
	stream << "Радиус: " << circle.GetRadius() << "  X: " << circle.GetCenterX() << "  Y: " << circle.GetCenterY() << "\n";
	return stream;
}

// Перегрузка оператора для ввода окружности с экрана
istream& operator >> (istream& stream, Circle& circle)
{
	cout << "Введите через пробел радиус, и координаты х и y центра окружности: ";
	double radius, x, y;
	stream >> radius >> x >> y;
	circle.SetRadius(radius);
	circle.SetCenterX(x);
	circle.SetCenterY(y);
	return stream;
}


