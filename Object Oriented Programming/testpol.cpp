#include <iostream>
using namespace std;

class Polynomial
{
private:
	 int a[100];
	 int n;
	 int deg[100];
public:
	 void ADD(Polynomial P0,Polynomial P2)
	 {
		 int i,j,k;
		 i=0;j=0;k=0;
		 while(i<P0.n && j<P2.n){
		 	if(P0.deg[i]==P2.deg[j]){
		 		a[k]=P0.a[i]+P2.a[j];
		 		deg[k]=P0.deg[i];
		 		i++;
		 		j++;
		 		k++;
		 	}
		 	else if(P0.deg[i]>P2.deg[j])
		 	{
		 		a[k]=P0.a[i];
		 		deg[k]=P0.deg[i];
		 		i++;k++;
		 	}
		 	else{
		 		a[k]=P2.a[j];
		 		deg[k]=P2.deg[j];
		 		j++;k++;
		 	}
		 }
		 while(i<P0.n){
		 	a[k]=P0.a[i];
		 	deg[k]=P0.deg[i];
		 	i++;k++;
		 }
		 while(j<P2.n){
		 	a[k]=P2.a[j];
		 	deg[k]=P2.deg[j];
		 	j++;k++;
		 }
		 n=k;
	 }

	 void MULTIPLY(Polynomial P0,Polynomial P2)
	 {
          int k,next,flag;
          int ex,co;
          int j,i;

          i=next=0;
          while(i<P0.n){
          	j=0;
          	while(j<P2.n){
          		ex=P0.deg[i] + P2.deg[j];
          		co=P0.a[i]*P2.a[j];
          		k=0;
          		flag=0;
          		while(k<next && !flag){
          			if(deg[k]==ex){
          				flag=1;
          				break;
          			}
          		    else{
          		    	k++;
          		    }
          	}
          	if(flag==1){
          		a[i]=a[i]+co;
          	}
          	else{
          		deg[next]=ex;
          		a[next]=co;
          		next++;
          	}
          	j++;
          }
          i++;
        }
        n=next;
	 }

	 void EVALUATE()
	 {
	 	float sum,x;
	 	cout<<"Enter value of x for evaluation:";
	 	cin>>x;
	 	for(int i=0;i<n;i++){
	 		sum+=a[i]*POWER(x,deg[i]);
	 	}
	 	cout<<"Value of polynomial for x="<<x<<"is:"<<sum<<endl;
	 }

	 float POWER(float x,int p)
	 {
	 	if(p==0){
	 		return 1;
	 	}
	 	else
            return x*POWER(x,p-1);
	 }
	 friend istream& operator >> (istream& ,Polynomial&);
	 friend ostream& operator << (ostream& ,Polynomial&);
};

istream& operator >> (istream& in ,Polynomial &P){
	cout<<"Enter number of terms in polynomial:";
	in>>P.n;
	cout<<"Enter co-efficients and their degree in descending order:"<<endl;
	for(int i=0; i<P.n; i++){
		in>>P.a[i]>>P.deg[i];
	}
	return in;
}

ostream& operator << (ostream& out ,Polynomial &P1){
	for(int i=0; i< P1.n; i++){
		if(i!=P1.n-1){ 
		   cout<<P1.a[i]<<"x^"<<P1.deg[i]<<"+";
	    }
	    else{
	    	cout<<P1.a[i]<<"x^"<<P1.deg[i];
	    }
	}
	cout<<endl;
	return out;
}

int main() {
    Polynomial P0,P2,P3,P4;
    int choice;
    char ch;
    cin>>P0;
    cout<<P0;
    cin>>P2;
    cout<<P2;
    do{
    	cout<<"Enter choice:\n1.Add Polynomials\n2.Multiply Polynomials\n3.Evaluate Polynomial 1\n4.Evaluate Polynomial 2\n";
        cin>>choice;
        switch(choice){
        	case 1:{
        		cout<<"Addition is:"<<endl;
        		P3.ADD(P0,P2);
        		cout<<P3;
        		break;
        	}
        	case 2:{
        		cout<<"Multiplication is:"<<endl;
        		P4.MULTIPLY(P0,P2);
        		 cout<<P4;
        		break;
        	}
        	case 3:{
        		cout<<P0;
                P0.EVALUATE();
                break;
        	}
        	case 4:{
        		cout<<P2;
                P2.EVALUATE();
                break;
        	}
        	default:{
        		cout<<"Invalid input.Please try again.";
        		break;
        	}
        }
        cout<<"Want to try again?(Y/y):";
        cin>>ch;
    }while(ch=='Y'|| ch=='y');
 return 0;
}
