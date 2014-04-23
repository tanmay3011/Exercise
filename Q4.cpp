#include <iostream>
using namespace std;
int main()
{
        int x[4][3],dw[4][3],w[5][3],t[4][1],y[4][2],i,j,p;
	float theta,alpha;

	cout<<"Enter the threshold value(0-1):";
	cin>>theta;
	cout<<"\n";

        cout<<"Enter the learning rate(0-1):";
        cin>>alpha;
        cout<<"\n";


        for(i=0;i<=2;i++)
        {
                w[0][i]=0;			
        }

        for(p=1;p<=4;p++)
        {
                x[p][2]=1;
		y[p][0]=0;
        }

        for(p=1;p<=4;p++)
        {
                cout<<"Enter the input Pattern number "<<p<<" : \n";
                for(i=0;i<=1;i++)
                {
                        cout<<"x"<<i+1<<":";
                        cin>>x[p][i];
                }
                cout<<"Enter the corresponding target \n";
                cin>>t[p][1];
	}

	cout<<"\n";
        cout<<"  Inputs  "<<"Tar Ni/p Ci/p  "<<"Wgt-Changes"<<"  "<<"Weights"<<"\n";
        cout<<" x1 x2  1  t   yin   y   dw1 dw2 dw3  w1 w2  b"<<"\n";

	for(int k=0;k<=9;k++)
	{
		for(p=1;p<=4;p++)
		{
			y[p][0]=0;	
			for(i=0;i<=1;i++)
			{	
				y[p][0]=y[p][0]+x[p][i]*w[p-1][i];	
			}
			y[p][0]=y[p][0]+w[p-1][2];
		
			if(y[p][0]>theta)
			{
				y[p][1]=1;
			}
			else if(y[p][0]==0)
			{
				y[p][1]=0;
			}
			else
			{
				y[p][1]=-1;
			}

			if(y[p][1]!=t[p][1])
			{
                		for(i=0;i<=2;i++)
                		{
                        		dw[p][i]=alpha*x[p][i]*t[p][1];
	                        	w[p][i]=w[p-1][i]+dw[p][i];
	               		}
			}
			else
			{
				for(i=0;i<=2;i++)
                        	{
                                	dw[p][i]=0;
                                	w[p][i]=w[p-1][i]+dw[p][i];
                        	}
			}
        	}
        	
        
	
		cout<<"EPOCH "<<k+1<<"\n";
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
                	if(t[p][1]>=0)
                	{
                        	cout<<" ";
                	}
               		cout<<t[p][1]<<"   ";

			if(y[p][0]>=0)
                	{
                        	cout<<" ";
                	}
                	cout<<y[p][0]<<"   ";

			if(y[p][1]>=0)
                	{
                        	cout<<" ";
                	}
                	cout<<y[p][1]<<"   ";

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
		
		for(i=0;i<=2;i++)
		{
			w[0][i]=w[4][i];
		}
	}
return 0;
}

