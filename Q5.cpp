#include <iostream>
using namespace std;
int main()
{
        int x[4][3],t[4][1],y[4][2],i,j,p;
        float alpha,yin[4],e[4],dw[4][3],w[5][3];

        cout<<"Enter the learning rate(0-1):";
        cin>>alpha;
        cout<<"\n";

        for(i=0;i<=2;i++)
        {
                w[0][i]=0.1;
        }

        for(p=1;p<=4;p++)
        {
		x[p][2]=1;
                y[p][0]=0;
		yin[p]=0;
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
		yin[p]=x[p][0]*w[p-1][0]+x[p][1]*w[p-1][1]+w[p-1][2];
		
		for(i=0;i<=1;i++)
		{
			dw[p][i]=alpha*(t[p][1]-yin[p])*x[p][i];
			w[p][i]=w[p-1][i]+dw[p][i];
		}
		dw[p][2]=alpha*(t[p][1]-yin[p]);
		w[p][2]=w[p-1][2]+dw[p][2];
		e[p]=(t[p][1]-yin[p])*(t[p][1]-yin[p]);
        	
	}
	
	for(p=1;p<=4;p++)
	{
		cout<<e[p];
	//	cout<<yin[p];
		for(i=0;i<=2;i++)
		{
		//	cout<<w[p][i]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
