#include<bits/stdc++.h>
using namespace std;
#define size 100005



long long int a[size];

class segment {
	public:
		long long int sum;
		long long int mini;
}tree[4*size];


void bouil_tree(int s,int e,int node_no)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[node_no].sum=a[s];
		tree[node_no].mini=a[s];
		return;
	}
	else
	{
		int m=(s+e)/2;
		bouil_tree(s, m, node_no*2);
		bouil_tree(m+1, e, node_no*2+1);
	}
	tree[node_no].sum=tree[node_no*2].sum+tree[node_no*2+1].sum;
	tree[node_no].mini=min(tree[node_no*2].mini,tree[node_no*2+1].mini);
}

segment query(int s,int e,int l,int r,int node_no)
{
	//cout<<"call for "<<node_no<<endl;
	segment ret;

	if(s>r||e<l)
	{
		ret.sum = 0;
		ret.mini=1000000000;
		return ret;
	}	
	if(s>=l&&e<=r)
	{
		return tree[node_no];
	}
	int m=(s+e)/2;
	segment  q1=query(s,m,l,r,node_no*2);
	segment q2=query(m+1,e,l,r,node_no*2+1);
	ret.sum = q1.sum+q2.sum;
	ret.mini = min(q1.mini,q2.mini);
	return ret;

}


void update(int s,int e,int p, int value ,int node_no)
{
	//cout<<"update for "<<node_no<<endl;
	if(s>e)
		return ;
	
	if(e==s)
	{
		tree[node_no].sum+=value;
		tree[node_no].mini+=value;
		return;
	}
	int m=(e+s)/2;
	if(p<=m)
	{
		update(s,m,p,value,node_no*2);
	}
	else{
		update(m+1,e,p,value,node_no*2+1);
	}
	tree[node_no].sum=tree[node_no*2].sum+tree[node_no*2+1].sum;
	tree[node_no].mini=min(tree[node_no*2].mini,tree[node_no*2+1].mini);
	return;
}
int main()
{
	
	
	
		int n,nq,l,r,v,p;
		char w[10];
		cin>>n;
		
		for(int i=1;i<=n;i++)
			cin>>a[i];

		bouil_tree(1,n,1);

		cin>>nq;

		for(int i=0;i<nq;i++)
		{
			scanf("%s",w);
			
			if(strcmp(w,"GROW")==0)
			{
				cin>>v>>p;
				update(1,n,p+1,v,1);
			}
			if(strcmp(w,"EAT")==0)
			{
				cin>>v>>p;
				update(1,n,p+1,-v,1);
						
			}
			if(strcmp(w,"COUNT")==0)
			{
				
				cin>>l>>r;
				segment ans=query(1,n,l+1,r+1,1);
				cout<<ans.sum-ans.mini<<endl;
			}
			
		}
	
}