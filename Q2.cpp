#include <iostream>
using namespace std;
int main()
{
	int x[4][3],dw[4][3],w[5][3],y[4][1],i,j,p; //Comment1
	for(i=0;i<=2;i++)
	{
		w[0][i]=0;
	}
	for(p=1;p<=4;p++)
	{
		x[p][2]=1;
	}
	for(p=1;p<=4;p++)
	{
		cout<<"Enter the input Pattern number "<<p<<" : \n";
		for(i=0;i<=1;i++)
		{
			cout<<"x"<<i+1<<":";
			cin>>x[p][i];
		}
		cout<<"Enter the corresponding output \n";
		cin>>y[p][1];
		dw[p][2]=y[p][1];
		for(i=0;i<=2;i++)
		{
			if(i<=1)
			{
				dw[p][i]=x[p][i]*y[p][1];
			}			
			w[p][i]=w[p-1][i]+dw[p][i];
		}
	}
	cout<<"\n";
	cout<<"  Inputs  "<<"      "<<"Wgt-Changes"<<"  "<<"Weights"<<"\n";
	cout<<" x1 x2  b   y   dw1 dw2 dw3  w1 w2  b"<<"\n";
	for(p=1;p<=4;p++)
	{
		cout<<" ";
		for(i=0;i<=2;i++)
		{
			if(x[p][i]>=0)
			{
				cout<<" ";
			}
			cout<<x[p][i]<<" ";
		}
                if(y[p][1]>=0)
                {
                        cout<<" ";
                }
		cout<<" "<<y[p][1]<<"   ";		

		for(i=0;i<=2;i++)
                {
                        if(dw[p][i]>=0)
                        {
                                cout<<" ";
                        }

                        cout<<dw[p][i]<<"  ";
                }
                cout<<" ";
		for(i=0;i<=2;i++)
                {
                        if(w[p][i]>=0)
                        {
				
                                cout<<" ";
                        }
			
                        cout<<w[p][i]<<" ";
                }
		cout<<"\n";	
	}	
return 0;
}
