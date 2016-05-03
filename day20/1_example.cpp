#include <iostream>
using namespace std;
#include "MyComplex.h"
class MyNum
{
	public:
	MyNum(int val) : val_(val) { }
	friend ostream& operator<<(ostream& o, const MyNum& n);
//	MyNum square() const
//	{
//		return val_ * val_;
//	}
	friend MyNum square(const MyNum& x);
	private:
	int val_;
};
ostream& operator<<(ostream& o, const MyNum& n)
{
	return o << n.val_ << "\n";
}
MyNum square(const MyNum& x)
{
	return x.val_ * x.val_;
}
int main()
{
	MyComplex c1(3.3, 4.4);
	c1.disp();
	MyComplex c2(6.6);
	c2.disp();
	// becomes a fn declaration; C legacy!!
	// MyComplex c3();
	MyComplex c3;
	c3.disp();

	c3 = c1.add(c2);
	c3.disp();
#if 0
	c3 = c1 + c2; // c1.operator+(c2)
	c3.disp();

	c3 = c1 + 7.8; // c1.operator+(7.8);
	// c1.operator+(MyComplex(7.8))
	// step 5 of matching arguments to parameters
	// - single argument constructor
	c3.disp();

	c3 = 1.2 + c1; 
	c3.disp();
#endif
// MyComplex operator+(const MyComplex& lhs, const MyComplex& rhs);
	c3 = c1 + c2; 
	// operator+(c1, c2)
	c3 = c1 + 7.8;  
	// operator+(c1, 7.8)
	// operator+(c1, MyComplex(7.8))
	c3 = 1.2 + c1; 
	//	operator+(1.2, c1)
	//	operator+(MyComplex(1.2), c1)

	cout << c3; // friend of MyComplex
	// overload insertion or put-to operator
	// member of MyComplex :
	// usage : c3 >> cout   ???
	// cannot support cascading
	// cout << c3 << "hello " << c1; // ok
	// c3 >> "hello" >> cout;  // NO

	cout << "\n";

	MyNum m(10);
//	cout << m.square() << "\n";

	cout << square(m) << "\n";
}












