#include<bits/stdc++.h>
using namespace std;
long long int n, t,sum=0;
long long int arr[1000005];
long long int wood(int s)
{
	sum=0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>s)
			sum+=arr[i]-s;
	}
	return sum;
}

int main()
{
	long long int mid,ans=-1;
	scanf("%lld %lld",&n,&t);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	long long int l=1,h=1000000000;
	
	
	while(l<=h)
	{
		mid=l+(h-l)/2;
		if(wood(mid)>=t)
		{
			l=mid+1;
			ans=max(mid,ans);
		}
		
		else
			h=mid-1;
	}

	printf("%lld\n",ans);
		
}