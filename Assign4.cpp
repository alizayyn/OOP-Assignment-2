#include<iostream>
#include<math.h>
using namespace std;

class ComplexNumber{

private:
	int  real;
	int imaginary;
public:

	ComplexNumber(int, int); //with default arguments
	~ComplexNumber(); //Does Nothing.
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();

};

ComplexNumber::ComplexNumber(int r=0, int i=0)
{
	real = r;
	imaginary = i;
}
ComplexNumber::~ComplexNumber()
{
}
void ComplexNumber::Input()
{
	cout << "Enter Real part: "; cin >> real;
	cout << "Enter Imaginary part: "; cin >> imaginary ;
}
void ComplexNumber::Output()
{
	if (imaginary >0)
	{
		cout << real << "+" << imaginary << "i";
	}
	else if (imaginary == 0)
	{
		cout << real;
	}
	else
	{
		cout << real << imaginary << "i";
	}
  
}
bool ComplexNumber::IsEqual(ComplexNumber c2) 
{
	bool check;

	int c1r = real;
	int c1i = imaginary;
	int c2r = c2.real;
	int c2i = c2.imaginary;
	if (c1r == c2r && c1i == c2i)
	{
		check = 1;
	}
	else
	{
		check = 0;
	}

	return check;
}
ComplexNumber ComplexNumber::Conjugate()
{
	int i= imaginary ;
	i *= -1;
	ComplexNumber con(real,i);
	return con;
}

ComplexNumber ComplexNumber::Add(ComplexNumber c2)
{
	
	int c1r = real;
	int c1i = imaginary;
	int c2r = c2.real;
	int c2i = c2.imaginary;
	int rs = c1r + c2r;
	int is = c1i + c2i;
	ComplexNumber sum(rs, is);
	return sum;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber c2)
{

	int c1r = real;
	int c1i = imaginary;
	int c2r = c2.real;
	int c2i = c2.imaginary;
	int rd = c1r - c2r;
	int id = c1i - c2i;
	ComplexNumber diff(rd, id);
	return diff;
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber c2)
{

	int c1r = real;
	int c1i = imaginary;
	int c2r = c2.real;
	int c2i = c2.imaginary;
	int r = c1r * c2r+ (c1i * c2i) * (-1);
	int im = (c1r * c2i)+(c2r*c1i);
	ComplexNumber pdct(r,im);
	return pdct;
}

float ComplexNumber::Magnitude()
{
	float mag;
	mag= sqrt((real*real)+(imaginary*imaginary));
		return mag;
}

int main()
{

	ComplexNumber c1,c2,result;
	cout << "Enter c1: \n";
	c1.Input();
	cout << endl;
	cout << "Enter c2: \n";
	c2.Input();
	cout << endl;
	cout << "c1 = "; c1.Output();
	cout << endl;
	cout << "c2 = "; c2.Output();
	cout <<endl<< endl;
	bool check = c1.IsEqual(c2);
	if (check)
	{
		cout << "c1 is Equal to c2. \n";
	}
	else
	{
		cout << "c1 is NOT Equal to c2. \n";
	}
	cout << endl << endl;
	result = c1.Conjugate();
	cout << "Conjugate of c1:\t"; result.Output();
	cout << endl;
	cout << endl ;
	result = c2.Conjugate();
	cout << "Conjugate of c2:\t"; result.Output();
	cout << endl;
	cout << endl ;
	result = c1.Add(c2);
	cout << "c1 + c2 :\t"; result.Output();
	cout << endl;

	result = c1.Subtract(c2);
	cout << "c1 - c2 :\t"; result.Output();
	cout << endl;
	
	result = c1.Multiplication(c2);
	cout << "c1 x c2 :\t"; result.Output();
	cout << endl;
	cout << endl << endl;
	
	cout << "Magnitude of c1: ";cout<<c1.Magnitude();
	cout << endl;
	cout << endl;
	
	cout << "Magnitude of c2: "; cout<<c2.Magnitude();
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}