#include <iostream>
#include <Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab '\t' 

class String
{
	int n = 16;
	char* str = new char[n];
public:
	String()
	{
		cout << "Constructor default:\t\t" << this << endl;
	}
	String(const char* str)
	{
		strcpy_s(this->str, this->n, str);
		cout << "Constructor default:\t\t" << this << endl;
	}
	~String()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	String& operator+=(String& right)
	{
		int len_l = this->Lenght();
		int len_r = right.Lenght();
		this->n += len_r;
		for (int i = 0; i < len_r; i++)
		{
			//this->set_str(i, this->get_str(i));
			this->set_str(i + len_l, right.get_str(i));
		}
		this->set_str(len_l + len_r, 0);
		return *this;
	}

	String& operator = (String& obj)
	{		
		strcpy_s(this->str, this->n, obj.str);
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this; // Передаем по значению
	}

	/////////////////////////////////////// 
	//GET
	///////////////////////////////////////
	char get_str(int i)const
	{
		return str[i];
	}
	int get_n()const
	{
		return n;
	}
	char get_str()const
	{
		return *str;
	}
	//////////////////////////////////////
	//SET
	////////////////////////////////////// 
	void set_str(int i, char str)
	{
		this->str[i] = str;
	}
	void set_str()
	{
		cin.getline(this->str, this->n);
	}
	void set_n(int n)
	{
		this->n = n;
	}
	void copy_str(char* str)
	{
		strcpy_s(this->str, this->n, str);
	}
	//////////////////////////////////////
	//LENGHT
	/////////////////////////////////////
	int Lenght()
	{
		int i = 0;
		for (; str[i]; i++);
		return i;
	}
};

/////////////////////////////////
String& operator+(String& left, String& right)
{
	String X;
	int len_l = left.Lenght();
	int len_r = right.Lenght();
	int n = len_l + len_r;

	for (int i = 0; i < len_l; i++)
	{
		X.set_str(i, left.get_str(i));
		X.set_str(i + len_r, right.get_str(i));
	}
	X.set_str(len_l + len_r, 0);
	return X;
}


ostream& operator<<(ostream& os, const String& obj)
{
	for (int i = 0; obj.get_str(i); i++)
	{
		os << obj.get_str(i);
	}
	return os;
}

istream& operator>>(istream& is, String& obj)
{
	char* str = new char[20];
	SetConsoleCP(1251);
	is.getline(str, obj.get_n());
	obj.copy_str(str);
	SetConsoleCP(866);
	delete[] str;
	return is;
}

int main()
{
	setlocale(LC_ALL, "rus");

	String A("He llo");
	cout << "A() : " << A << endl << endl << endl;

	cout << "Введите А " << endl;
	cin >> A;
	cout << "A : " << A << endl << endl << endl;

	String B("BBB");
	
	
	cout << "B = A B : " << B << endl << endl << endl;

	cout << "Введите B " << endl;
	cin >> B;
	cout << endl << endl << endl;

	String C = B + A;
	cout << "C = B + A : " << C << endl << endl << endl;

	cout << "A : " << A << endl << endl << endl;
	String D;
	D = C;
	cin >> D;
	cout << "D = C : " << D << endl << endl << endl;
	cout << "D = C : " << C << endl << endl << endl;

	C += D;
	cout << "C += D : " << C << endl << endl << endl;

	return 0;
}