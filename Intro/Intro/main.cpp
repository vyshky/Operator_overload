#include <iostream>
using namespace std;
#define tab '\t'

class Point //Тип данных Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}

	void set_y(double y)
	{
		this->y = y;
	}
	//Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefualtConstructors:\t" << this << endl;
	}*/
	//Point(double x)
	//{
	//	//Конструктор с одним параметр создает точку на прямой
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstuctor:\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructors:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
	}

	//Methods
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}



};
//Cтруктура - это тип данных , Сlass - это тип данных

//#define STRUCT

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef STRUCT

	int a;     // Объявляем переменную а типа int 
	Point A;  // Объявляем переменную а типа Point
				// Объявляем объект структуры Point
				// создаем экземпляра структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //Cоздаем указатель на Point . p -pointer на A
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STUCT

	Point A; //Объявляем объект класса Поинт/defualt constructor
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	Point B(2, 3);
	B.print();

	Point C = 5;//Single - argument constructer
	C.print();

	Point D = B; //Copy Constructor
	D.print();

	Point E; //Default constructor
	E = D;   //Copy Assignment
	E.print();
}
