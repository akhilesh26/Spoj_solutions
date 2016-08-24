
// longest path in the tree using simple dfs

#include<bits/stdc++.h>
using namespace std;
#define initial 0
#define waiting 1
#define visited 2
int adj[10005][10005],status[10005],depth[10005];
int n;
void dfs(int v,int d)
{
	depth[v]=d;
	status[v]=waiting;
	for(int i=1;i<=n;i++)
	{
		if(adj[v][i]==1&&status[i]==initial)
		{
			dfs(i,d+1);
		}
	}
	status[v]=visited;
	return;
}
int give_max()
{
	int maxd=depth[1];
	int v_maxd=1;

	for(int i=1;i<=n;i++){

		if(maxd<=depth[i]){
			maxd=depth[i];
			v_maxd=i;

		}
		//printf("%d %d\n", i ,depth[i]);
	}

	//cout<<v_maxd<<endl;
	//cout<<maxd<<endl;
	return v_maxd;
}

int main(){

	int i,j,k,u,v;
	cin>>n;
	for(i=1;i<n;i++){
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	for (i=1;i<=n;i++){

		status[i]=initial;
		depth[i]=initial;
	}
	dfs(1,0);

	int s=give_max();

	for (i=1;i<=n;i++){

		status[i]=initial;
		depth[i]=initial;
	}

	

	dfs(s,0);
	
	s=give_max();

	cout<<depth[s]<<endl;

}