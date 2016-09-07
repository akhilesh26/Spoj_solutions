#include<bits/stdc++.h>
using namespace std;
#define size 100005
long long int a[size];
class seg{
	public:
		int fm,sm;
}tree[4*size];

void build_tree(int s,int e,int node_no)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[node_no].fm=a[e];
		tree[node_no].sm=0;
		return;
	}
	else{
		int m=(e+s)/2;
		build_tree(s,m,node_no*2);
		build_tree(m+1,e,node_no*2+1);
	}
	tree[node_no].fm=max(tree[node_no*2].fm,tree[node_no*2+1].fm);
	tree[node_no].sm=max(min(tree[node_no*2].fm,tree[node_no*2+1].fm),max(tree[node_no*2].sm,tree[node_no*2+1].sm));

	return;
}

void update(int s,int e,int p,int val,int node_no)
{
	
	if(s>e)
	{
		return;
	}

	if(e==s)
	{
		tree[node_no].fm=val;
		
		return;
	}
	int m=(e+s)/2;
	if(p<=m)
	{
		update(s,m,p,val,node_no*2);
	}
	else{
		update(m+1,e,p,val,node_no*2+1);
	}

	tree[node_no].fm=max(tree[node_no*2].fm,tree[node_no*2+1].fm);
	tree[node_no].sm=max(min(tree[node_no*2].fm,tree[node_no*2+1].fm),max(tree[node_no*2].sm,tree[node_no*2+1].sm));

	return;

}

seg query(int s,int e,int l,int r,int node_no)
{
	seg fake;
	if(s>r||e<l)
	{
		fake.fm=0;
		fake.sm=0;
		return fake;
	}
	if(s>=l&&e<=r)
	{
		return tree[node_no];
	}
	else
	{
		int m=(s+e)/2;
		seg q1=query(s,m,l,r,node_no*2);
		seg q2=query(m+1,e,l,r,node_no*2+1);
		seg ret;
		ret.fm=max(q1.fm,q2.fm);
		ret.sm=max(min(q1.fm,q2.fm),max(q1.sm,q2.sm));

		return ret;
	}

}


int main()
{
	int n,nq;
	
	cin>>n;

	

	for(int i=1;i<=n;i++)
		cin>>a[i];

	build_tree(1,n,1);

	
	cin>>nq;
	int l,r,p,v;
	for(int i=1;i<=nq;i++)
	{
		char w;
		cin>>w;
		if(w=='U')
		{
			
			cin>>p>>v;
			update(1,n,p,v,1);
		}
		if(w=='Q')
		{
			
			cin>>l>>r;
			seg ans=query(1,n,l,r,1);
			cout<<ans.fm+ans.sm<<endl;
		}
	}
}