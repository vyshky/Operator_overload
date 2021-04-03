#include <iostream>
using namespace std;
#define tab '\t'

//#define STRUCT
//#define CONSTRUCKTOR_CHECK
//#define ASSIGNMENT_CHECK
//#define STREAMS

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
		cout << "Destructor:\t\t" << this << endl;
	}
	//Copy Operators    (=) ,A = B
	Point& /*предаем по ссылке чтобы  лишный раз не копировался объект */ operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this; // Передаем по значению
	}
	Point& operator+=(const Point& other)
	{
		/*this->x += other.x;
		this->y += other.x;*/
		this->set_x(this->x + other.x);
		this->set_y(this->y + other.y);
		return *this;
	}
	// Increment/Decrement
	Point& operator++() //Prefix increment
	{
		++this->x;
		++this->y;
		return *this;
	}
	Point operator++(int) //Postfix inrement
	{
		Point old = *this;
		/*this->x++;
		this->y++;*/
		++* this; //вызвали префиксный инкремент Prefix increment
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
	//Methods
	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};
//Cтруктура - это тип данных , Сlass - это тип данных



Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
	{
		return true;
	}
	else
		return false;*/

	return left.get_x() == right.get_x() && left.get_y() == right.get_y();

}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}
ostream& operator<<(ostream& os, Point& obj)
{
	os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
	return os;
}

istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}
void main()
{
	setlocale(LC_ALL, "Russian");
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

#ifdef CONSTRUCKTOR_CHECK
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
	E = D;   //Copy Assignment	Перед присваиваем отчищает память.
	E.print();
#endif // CONSTRUCKTOR_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

#ifdef STREAMS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	//A.print();
	//B.print();
	/*Point C = A + B;
	C.print();
	A.print();
	B.print();*/
	/*A += B;
	A.print();	*/
	Point D = A++;
	A.print();
	D.print();

	//cout << A << tab << B << endl;
	//cout << "Введите координаты точки: "; cin >> A;
	//cout << "Вы ввели : " << A << endl;

	//(ostream)-cout  (Point)A
	//(istream)-cin  
#endif // STREAMS

	Point A(2, 3);
	Point B(3, 4);	
	cout << (A == B) << endl;
	//cout << (A != B) << endl;

	cout << A << endl;
	/*A.set_x(33);
	A.set_y(44);*/

	A(33, 44);	
	cout << A << endl;
}
