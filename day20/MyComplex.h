#ifndef MYCOMPLEX
#define MYCOMPLEX
class MyComplex
{
	public:
	//explicit 
	MyComplex(double rp = 0.0, double ip = 0.0 )
	: rp_(rp), ip_(ip)
	{
	}
	void disp() const
	{
		cout << "(" << rp_ << "," << ip_ << ")\n";
	}
	MyComplex add(const MyComplex&) const;
	//MyComplex operator+(const MyComplex&) const;
	friend MyComplex operator+(const MyComplex& lhs, const 			MyComplex& rhs);	
	friend ostream& operator<<
		(ostream& o, const MyComplex& c);
	private:
	double rp_;
	double ip_;
};
// suppress single arg ctor
//	use keyword explicit
//	explicit : is  a rule
//	not using explicit : is an exception


// declare the function outside the class
// not a member fn; therefore has no this pointer
// therefore requires two explicit parameterss

// is this interface ok? will the client compile?
// yes
// we have to provide an implementation for this

// friend function of a class
//		defines another interface
//		can access any member of the class to which
//			it is a friend
//	seldom have friends
//	have friends only when required
//	- posn of operand is not right
//	- binary operator not requiring an object
//	- convention demands

#endif
