#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int n;
	char* str = new char[n];
	public:
		void set_n(int n)
		{
			this->n = n;
		}

};