//Fractional Knapsack
#include<bits/stdc++.h>
using namespace std;
void KnapSack(int wt[],int val[],int n,int W)
{
    double u[n];
    int vsum=0,sum=0;
    for(int i=0;i<n;i++)
    {
        u[i]=(double)val[i]/(double)wt[i];
        vsum+=val[i];
        sum+=wt[i];

    }
    if(W>=sum)
    {
        cout<<vsum;
        W=0;
        return ;
    }
    double max=0.0000;int pos;double value=0.0;
 while(W!=0)
	{
		max=0;
		for(int i=0;i<n;i++)
		{
            if(max<u[i])
			{
				max=u[i];
				pos=i;
			}

		}
		
		
		if(wt[pos]<=W)
		{
			value+=(double)val[pos];
			W=W-wt[pos];
			wt[pos]=0;
			u[pos]=0;
		}
		
		else if(W!=0 && W<wt[pos])
		{
		     value+=(double)(u[pos]*W);
		     wt[pos]=wt[pos]-W;
			 W=0;
			 u[pos]=0;
		}
    }
		
    cout<<std::fixed;
    cout<<std::setprecision(4)<<value;
}
int main()
{
    cout<<"Enter the number of items";

    int n;
    cin>>n;
    cout<<"Enter the weights and the values";
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i]>>val[i];
    int W;
    cout<<"Enter the weight of the knapsack";
    cin>>W;
    KnapSack(wt,val,n,W);
    return 0;
}

