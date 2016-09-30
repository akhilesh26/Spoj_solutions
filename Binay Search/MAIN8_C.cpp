#include<bits/stdc++.h>
using namespace std;
int nb,np;
int box[1000005];

bool ispossible(int cpp)
{
	int temp=np; // take temparary no of people
	for(int i=1;i<=nb;i++)
	{
		temp-=box[i]/cpp;
		if(temp<1)
			return true;
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m=-100000000;
		int ans;
		cin>>nb>>np;
		for(int i=1;i<=nb;i++)
		{
			cin>>box[i];
			if(m<box[i])
			{
				m=box[i];
			}
		}
		int l=0,h=m;

		while(h>l)
		{
			int mid =l+(h-l+1)/2;
			if(ispossible(mid))
			{
				l=mid;
				
			}
			else
				h=mid-1;
		}
		cout<<l<<endl;
	}
}