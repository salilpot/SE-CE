#include<iostream>
using namespace std;
class Complex
{
private:
	double Re;
	double Im;

public:
    //Complex()
    //{
    	//int i,r;
    	//Re=r;
    	//Im=i;
    //}
	void Input()
	{
	    cout<<"Enter real part of complex number:";
	    cin>>Re;
	    cout<<"Enter imaginary part of complex number:";
	    cin>>Im;
	}
	void PrintAdd()
	{
		cout<<"Addition is:"<<Re<<"+i"<<"("<<Im<<")"<<endl;
	}

    void PrintSub()
	{
		cout<<"Subtraction is:"<<Re<<"+i"<<"("<<Im<<")"<<endl;
	}

    void PrintMul()
	{
		cout<<"Multiplication is:"<<Re<<"+i"<<"("<<Im<<")"<<endl;
	}

	void PrintDiv()
	{
		cout<<"Division is:"<<Re<<"+i"<<"("<<Im<<")"<<endl;
	}

	Complex operator + (Complex const &obj1)
	{
		Complex Res1;
		Res1.Re = Re + obj1.Re;
		Res1.Im = Im + obj1.Im;
	    return Res1;
	}
	Complex operator - (Complex const &obj2)
	{
		Complex Res2;
		Res2.Re = Re - obj2.Re;
		Res2.Im = Im - obj2.Im;
		return Res2;
	}
	Complex operator * (Complex const &obj2)
	{
		Complex Res3;
		Res3.Re = (Re*obj2.Re) - (Im*obj2.Im);
		Res3.Im = (Re*obj2.Im) + (Im*obj2.Re);
		return Res3;
	}
	
	Complex operator / (Complex C2)
	{
		Complex Res4;
        double mod=(C2.Re*C2.Re + C2.Im*C2.Im);
        Res4.Re = ((Re*C2.Re) + (Im*C2.Im))/(mod);
        Res4.Im = ((Im*C2.Re) - (Re*C2.Im))/(mod);
        return Res4;
	}
};

int main()
{
	Complex C1,C2,C3,C4,C5,C6;
	C1.Input();
	C2.Input();
	C3 = C1 + C2;
	C4 = C1 - C2;
	C5 = C1 * C2;
	C6 = C1 / C2;
	C3.PrintAdd();
	C4.PrintSub();
	C5.PrintMul();
    C6.PrintDiv();
 	return 0;
}