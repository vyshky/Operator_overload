#include<iostream>
using namespace std;
#define tab '\t'

double distance_fo(const Point& A, const Point& B);
class Point
{
public:
	double x;
	double y;
	double distance_to(const Point& B)
	{
		return sqrt((pow((this->x - B.x), 2) + pow((this->y - B.y), 2)));
	}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Точка создана " << this << endl;
	}
	~Point()
	{
		cout << this << tab << "Точка уничтожена" << endl;
	}	
	void print()const
	{
		cout << this << tab << "X = " << x << tab << "Y = " << y << endl << endl;
	}
};

int main()
{
	setlocale(0, "rus");
	
	Point A(0, 10);
	Point B(10, 10);
	Point C;

	A.print();
	B.print();
	cout << "Растояние между точками : " << distance_fo(A, B) << endl;
	cout << endl << "---------------------------------" << endl;
	cout << "Растояние до точки : " << C.distance_to(B) << endl<<endl;
	return 0;
}

double distance_fo(const Point& A, const Point& B)
{
	return sqrt((pow((A.x - B.x), 2) + pow((A.y - B.y), 2)));
}


