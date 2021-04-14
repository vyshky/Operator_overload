#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab '\t' 

class String
{
	int n;
	char* str = new char[n];

public:
	String()
	{
		n = 0;
		cout << "Constructor default:\t\t" << this << endl;
	}	
	~String()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	void set_n(int n)
	{
		this->n = n;
	}
	int get_n()
	{
		return n;
	}
	char get_str()
	{
		for (int i = 0; str[i]; i++)
		{
			cout << this->str[i];
		}
		cout << endl;
		return 0;
	}
	void set_str()
	{
		cin.getline(this->str, this->n);
	}
	String& operator=(const String& other)
	{

	}

};
int main()
{
	String A;
	A.set_n(20);
	A.set_str();
	A.get_str();

	


	B.get_str();


	return 0;
}