#include<bits/stdc++.h>
using namespace std;
#define size 1000005
long long int  tree[4*size];
long long int lazy[4*size];

void lazy_update(int s,int e,int node_no)
{
	tree[node_no]+=((e-s+1)*lazy[node_no]);
	//printf("%d  %d\n", node_no,tree[node_no]);
	if(e>s)
	{
		lazy[node_no*2]+=lazy[node_no]; 
		lazy[node_no*2+1]+= lazy[node_no];
	}
    
  lazy[node_no] = 0;
}

void set_lazy(int s,int e,int nv,int node_no)
{
	if(e>s)
	{
		lazy[node_no*2]+=nv;
		lazy[node_no*2+1]+=nv;
	}
}

void update(int s,int e,int l,int r,int nv,int node_no)
{
	if(lazy[node_no]>0)
	{
		lazy_update(s,e,node_no);
	}
	if(s>r||e<l)
		return;
	else if(s>=l && e<=r)
	{
		tree[node_no]+=((long long)(e-s+1)*nv);
		set_lazy(s,e,nv,node_no);
		//lazy_update(s,e,node_no);
	}
	else
	{
		int m=(s+e)/2;

		update(s,m,l,r,nv,node_no*2);
		update(m+1,e,l,r,nv,node_no*2+1);

		tree[node_no]=(tree[node_no*2]+tree[node_no*2+1]);
	}

}

long long int query(int s,int e,int l,int r,int node_no)
{
	if(lazy[node_no]>0)
	{
		lazy_update(s,e,node_no);
	}
	//printf("%d %d %d %d\n",s,e, l,r );
	if(s>r||e<l){
		return 0;
	}
	else if(s>=l && e<=r){
		//cout << node_no << " " << tree[node_no] << endl;
		return (long long) tree[node_no];
	}
	
		int m=(s+e)/2;
		long long int q1 =  query(s,m,l,r,node_no*2);
		long long int q2 = query(m+1,e,l,r,node_no*2+1);
		return q1+q2;
	
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));

		int n,nq,f,l,r,v;
		cin>>n>>nq;
		

		for(int i=0;i<nq;i++)
		{
			cin>>f>>l>>r;
			if(f==0)
			{
				cin>>v;
				update(1,n,l,r,v,1);
			}
			if(f==1)
			{
				cout<<query(1,n,l,r,1)<<endl;
				
				
			}
		}
	}
}