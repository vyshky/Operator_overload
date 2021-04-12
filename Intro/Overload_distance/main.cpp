#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab '\t'

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor0:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor1:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		this->integer = decimal;
		double buffer = decimal - integer;
		buffer *= 10;//Определяем сколько цифр взять после запятой
		int i = 0;

		this->numerator = buffer;
		this->denominator = buffer;

		while (this->denominator != 0)
		{
			this->denominator /= 10;
			i++;
		}

		this->denominator = Pow(10, i);
		cout << "Constructor double:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor2:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructors3:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//////////////////////////////////////////////////////////
	double get_integer()const
	{
		return integer;
	}
	double get_numerator()const
	{
		return numerator;
	}
	double get_denominator()const
	{
		return denominator;
	}
	void set_integer(double integerr)
	{
		this->integer = integer;
	}
	void set_numerator(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(double denominator)
	{
		this->denominator = denominator;
	}
	void set_denominator(int numerator)
	{
		/*if (numerator > 0)this->denominator = numerator;
		else if (numerator < 0) this->denominator =-numerator;
		else this->denominator = 1;*/
		if (numerator == 0)throw exception("Zero in denominator");//Бросаем исключения,с сообщением об ошибке
		this->denominator = numerator;
	}
	///////////////////////////////////////////////////////// Increment / Decrement
	Fraction& operator+=(const Fraction& other)
	{
		/*this->numerator += other.numerator;
		this->denominator += other.denominator;*/
		this->set_numerator(this->numerator + other.numerator);
		this->set_denominator(this->denominator + other.denominator);
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		/*this->numerator -= other.numerator;
		this->denominator -= other.denominator;*/
		this->set_numerator(this->numerator - other.numerator);
		this->set_denominator(this->denominator - other.denominator);
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		/*this->numerator *= other.numerator;
		this->denominator *= other.denominator;*/
		this->set_numerator(this->numerator * other.numerator);
		this->set_denominator(this->denominator * other.denominator);
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		/*this->numerator /= other.numerator;
		this->denominator /= other.denominator;*/
		this->set_numerator(this->numerator / other.numerator);
		this->set_denominator(this->denominator / other.denominator);
		return *this;
	}

	Fraction& operator++()
	{
		++this->numerator;
		++this->denominator;
		++this->integer;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		++* this;
		return old;
	}
	Fraction& operator--()
	{
		--this->numerator;
		--this->denominator;
		--this->integer;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		--* this;
		return old;
	}

	Fraction& operator()(double x, double y)
	{
		set_numerator(x);
		set_denominator(y);
		return *this;
	}

	//Type cast operatos:
	explicit operator int()const
	{
		return this->integer;
	}
	explicit operator double()const
	{
		return this->integer + (double)this->numerator / this->denominator;
	}

	////////////////////////////////////////////////////////

	void to_proper()   //Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	{
		if (this->integer > 0)
		{

		}
		this->integer = this->numerator / this->denominator;
		this->numerator = this->numerator % this->denominator;
	}

	void to_improper()   //Переводит правильную дробь в неправильную: 2(3/4) => 11/4 
	{
		this->numerator += this->integer * this->denominator;
	}

	void reduce()  //Сокращает дробь: 5/10 => 1/2;
	{
		if (this->numerator > this->denominator)
		{
			this->integer += this->numerator / this->denominator;
			this->numerator -= this->denominator;
		}
		for (int i = 2; i <= this->denominator; i++)
		{
			while (this->numerator % i == 0 && this->denominator % i == 0)
			{
				this->numerator /= i;
				this->denominator /= i;
			}
		}
	}
	int Pow(int x, int pow_x)
	{
		int buffer = x;
		while (pow_x > 1)
		{
			buffer *= x;
			--pow_x;
		}
		return buffer;
	}
};

///////////////////////////////////////////////////////// Операторы сравнения
bool operator==(const Fraction& left, const Fraction& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
	{
		return true;
	}
	else
		return false;*/
	return left.get_integer() == right.get_integer()
		&& left.get_numerator() == right.get_numerator()
		&& left.get_denominator() == right.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return left.get_integer() == right.get_integer()
		&& left.get_numerator() == right.get_numerator()
		&& left.get_denominator() == right.get_denominator();
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.get_integer() >= right.get_integer()
		&& left.get_numerator() >= right.get_numerator()
		&& left.get_denominator() >= right.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left >= right);
}
///////////////////////////////////////////////////////// +,-,*,/
Fraction& operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() + right.get_numerator());
	result.set_denominator(left.get_denominator() + right.get_denominator());
	return result;
}
Fraction& operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_integer(left.get_integer() - right.get_integer());
	result.set_numerator(left.get_numerator() - right.get_numerator());
	result.set_denominator(left.get_denominator() - right.get_denominator());
	return result;
}
Fraction& operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_integer(left.get_integer() * right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction& operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_integer(left.get_integer() / right.get_integer());
	result.set_numerator(left.get_numerator() / right.get_numerator());
	result.set_denominator(left.get_denominator() / right.get_denominator());
	return result;
}

ostream& operator<<(ostream& os, Fraction& obj)
{
	os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
	return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
	double integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}

#define TYPE_CONVERSION
///Main
int main()
{
	setlocale(LC_ALL, "Rus");
#ifdef TYPE_CONVERSION
	////Явное преобразование значения 43 в char:
	//cout << (char)43 << endl;//C-like style
	//cout << char(43) << endl;//Functional style

	////Неявные преобразования:
	//int a = 2; //no conversion
	//double b = 3.4;//no conversion
	//cout << a * b << endl; //Оператор * неявно преобразует переменную 'а' в тип double,
	//					   //чтобы вернуть результат в double  
	//double c = 4; // От меньшего к БОльшему
	//int d = c;    //От БОльшего к меньшему, без потери данных
	//int e = 2.5;  //От Большего к меньшему, с потерей данных

	Fraction A(6, 8000, 10000);
	//A(10, 5);
	A.reduce();
	cout << A << endl;
	int a = (int)A;
	cout << "a " << a << endl;
	double b = double(A);//
	cout << "b " << b << endl;
	int c = int(A);
	cout << "c " << c << endl;

	Fraction B = (Fraction)3; //Сonversion from int to Fraction
	//Преобразование значения '3' типа инт во Fraction
	//Это преобразование возможно благодаря конструктору с одним параметром
	//B.to_proper();
	cout << "B " << B << endl;

	Fraction C(5);
	cout << "C " << C << endl;
	Fraction D = Fraction(8);//Явно вызываем конструктор с одним параметром,
		  //он создает временный безимянный объект,а затем вызывается CopyСonstructor
	   //и инициализирует объект 'D' временным безимянным объектом.



	////////////////////////////////////////////////////////////////////// 
	//В классе Fraction добить конструктор с одним параметром типа double;
	//////////////////////////////////////////////////////////////////////
	Fraction E = 6.8666681;
	cout << endl << "Дробь " << E << endl;
	E.reduce();
	cout << "reduce " << E << endl;
	double F = double(E);
	cout << "Double " << F << endl << endl;
	//////////////////////////////////////////////////////////////////////
#endif // TYPE_CONVERSION


}
////////////////////////////




