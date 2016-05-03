#include <iostream>
using namespace std;
#include "MyComplex.h"

MyComplex MyComplex::add(const MyComplex& rhs) const
{
	/*
	MyComplex temp;
	temp.rp_ = rp_ + rhs.rp_;
	temp.ip_ = ip_ + rhs.ip_;
	*/
	/*
	MyComplex temp(rp_ + rhs.rp_, ip_ + rhs.ip_);
	return temp;
	*/
	return MyComplex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}
// does not work; remove this
#if 0
MyComplex MyComplex::operator+(const MyComplex& rhs) const
{
	return MyComplex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}
#endif
// is this ok? NO
// 4 errors
// why?
MyComplex operator+(const MyComplex& lhs, const MyComplex& rhs)
{
	return MyComplex(lhs.rp_ + rhs.rp_, lhs.ip_ + rhs.ip_);
}
ostream& operator<<
		(ostream& o, const MyComplex& c)
{
	return o << "(" << c.rp_ << "," << c.ip_ << ")\n";
}

