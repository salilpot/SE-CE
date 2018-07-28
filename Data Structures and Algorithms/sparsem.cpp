#include<iostream>
using namespace std;
#define MAX 10
class Matrix
{
	private:
		int R;
		int C;
		int T;
	public:
		void GetData(){
			cout<<"Enter number of rows in matrix:";
			cin>>R;
            cout<<"Enter number of columns in matrix:";
			cin>>C;
			cout<<"Enter number of non zero terms in matrix:";
			cin>>T;
		}
	friend class Sparse;
};

class Sparse
{
private:
	int s[MAX][3];
	Matrix M;
public:
	void GetMatrix(){
		M.GetData();
		s[0][0]=M.R;
		s[0][1]=M.C;
		s[0][2]=M.T;
		cout<<"Enter matrix in format:row<space>coloumn<space>term..."<<endl;
		for(int i=1;i<=M.T;i++)
		{
             cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
	}
	void DisplayMatrix(){
		//The first line always contains number of rows,columns and number of terms.
		for(int i=0;i<=M.T;i++)
		{
             cout<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<endl;
		}
	}
	void AddMatrix(Sparse M1,Sparse M2){
		int i=1,j=1;
		static int k=1;
        if((M1.M.R==M2.M.R) && (M1.M.C==M2.M.C)){
        	s[0][0]=M1.M.R;
        	s[0][1]=M1.M.C;
        	while(i<=M1.M.T && j<=M2.M.T){
        		if(M1.s[i][0]==M2.s[j][0]){. //If rows and cols are equal.
        			if(M1.s[i][1]==M2.s[j][1]){
        				s[k][0]=M1.s[i][0];
        				s[k][1]=M1.s[i][1];
        				s[k][2]=M1.s[i][2]+M2.s[j][2];
        				i++;
        				j++;
        				k++;
        			}
                    if(M1.s[i][1]>M2.s[j][1]) //If rows in M1 are greater than that in M2.
        		    {
	        			s[k][0]=M2.s[j][0];
	        			s[k][1]=M2.s[j][1];
	        			s[k][2]=M2.s[j][2];
	        			j++;
	        			k++;
        		    }
        		   if(M1.s[i][1]<M2.s[j][1])  //If rows in M2 are greater than that in M1.
        		   {
	        			s[k][0]=M1.s[i][0];
	        			s[k][1]=M1.s[i][1];
	        			s[k][2]=M1.s[i][2];
	        			i++;
	        			k++;
        		   }
        		}
        		else if(M1.s[i][0]>M2.s[j][0]){ //Else check for columns.
        			s[k][0]=M2.s[j][0];
        			s[k][1]=M2.s[j][1];
        			s[k][2]=M2.s[j][2];
        			j++;
        			k++;
        		}
        		else
        		{
        			s[k][0]=M1.s[i][0];
        			s[k][1]=M1.s[i][1];
        			s[k][2]=M1.s[i][2];
        			i++;
        			k++;
        		}
        	}
        	while(i<=M1.M.T)                //Entering all the remaining terms of M1.
        	{
        		s[k][0]=M1.s[i][0];
        		s[k][1]=M1.s[i][1];
        		s[k][2]=M1.s[i][2];
        		i++;
        		k++;
        	}
        	while(j<=M2.M.T)                //Entering all the remaining terms of M2.
        	{
        		s[k][0]=M2.s[j][0];
        		s[k][1]=M2.s[j][1];
        		s[k][2]=M2.s[j][2];
        		j++;
        		k++;
        	}
        }
        else{
        	cout<<"Addition not possible..."<<endl;
        }
        s[0][2]=k-1;
        M.T=k-1;
	}
	void Transpose()
	{
		Sparse M4;
		int i,j,k;
		M4.s[0][0]=M.C;                    //Exchange number of rows and cols here.
		M4.s[0][1]=M.R;
		M4.s[0][2]=M.T;
		k=1;
		for(i=1;i<=M.C;i++){               //First check for the columns
			for(j=1;j<=M.T;j++){           //Then traverse all the terms of the matrix and store them in resultant transpose.
				if(i==s[j][1]){
                   M4.s[k][0]=i;
				   M4.s[k][1]=s[j][0];
				   M4.s[k][2]=s[j][2];
				   k++;
				}
			}
		}
		M4.M.T=k-1;
		M4.DisplayMatrix();
	}
};

int main()
{
	Sparse M1,M2,M3;
	M1.GetMatrix();
	M1.DisplayMatrix();
	M2.GetMatrix();
	M2.DisplayMatrix();
	M3.AddMatrix(M1,M2);
	cout<<"Addition is:"<<endl;
	M3.DisplayMatrix();
	cout<<"Transpose of Matrix 1 is:"<<endl;
	M1.Transpose();
	return 0;
}