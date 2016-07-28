#include<bits/stdc++.h>
using namespace std;
int cv[10000];
int dis[10000];
int main()
{
	int i,j,k,n;
	
	for(i=2;i<10000;i++)
	{
		if(cv[i]==0)
		{
			for (j=i+i; j < 10000; j+=i)
			{
				cv[j]=1;
			}
		}
	}
	int x,y,t;
	cin>>t;
	while(t-->0)
	{
		cin>>x>>y;
		queue<int> q;
		int f=0;
		q.push(x);
		for(i=0;i<10000;i++)
			dis[i]=-1;
		dis[x]=0;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			if(x==y)
			{
				f=1;
				break;
			}
			int d1=x/1000,d2=(x%1000)/100, d3=(x%100)/10,d4=x%10;
			for(i=0;i<10;i++)
			{
				n=d1*1000+d2*100+d3*10+i;
				if(cv[n]==0&&dis[n]==-1)
				{

					q.push(n);
					dis[n]=dis[x]+1;
				}

			}
			for(i=0;i<10;i++)
			{
				n=d1*1000+d2*100+i*10+d4;
				if(cv[n]==0&&dis[n]==-1)
				{
					q.push(n);
					dis[n]=dis[x]+1;
				}
			}
			for(i=0;i<10;i++)
			{
				n=d1*1000+i*100+d3*10+d4;
				if(cv[n]==0&&dis[n]==-1)
				{

				
					q.push(n);
					dis[n]=dis[x]+1;
				}
			}
			for(i=1;i<10;i++)
			{
				n=i*1000+d2*100+d3*10+d4;
				if(cv[n]==0&&dis[n]==-1)
				{
					dis[n]=dis[x]+1;
					q.push(n);
				}
			}
		
		}
		if(f==1)
		{
			cout<<dis[y]<<endl;
		}
		else
			cout<<"Impossible\n";
		
	}


	



}

