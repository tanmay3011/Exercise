#include <iostream>
using namespace std;
int main()
{
        int x[4][4],dw[4][2],w[4][5][2],t[4][2],i,j,p;
        
	for(p=1;p<=4;p++)
	{
		for(i=1;i<=2;i++)
        	{
                	w[0][p][i]=0;
        	}
	}
        
        for(p=1;p<=4;p++)
        {
                cout<<"Enter the input Pattern number "<<p<<" : \n";
                for(i=0;i<=3;i++)
                {
                        cout<<"s"<<i+1<<":";
                        cin>>x[p][i];
                }
                cout<<"Enter the corresponding output \n";
		for(i=1;i<=2;i++)
		{
			cout<<"t"<<i<<":";
                	cin>>t[p][i];
		}
        }

	k=1;
	while(k<=4)
	{
		for(p=1;p<=2;p++)
		{
			for(i=1;i<=4;i++)
        		{
                		dw[i][p]=x[k][i]*t[k][p];
                		w[i][p]=w[i-1][p]+dw[i][p];
        		}
        	}
		w[0][1]=w[
		k++;
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

