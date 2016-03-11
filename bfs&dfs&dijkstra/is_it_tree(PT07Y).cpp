#include<bits/stdc++.h>
using namespace std;
# define initial 1
# define waiting 2 
# define visited 3
# define max 10005
int n,e;
int count1=0;
int state[max];
vector<int> graph[max];
void dfs_visit(int v)
{
	
	state[v]=waiting;
	count1++;
	for(int i=0;i<graph[v].size();i++)
	{
		int nxt=graph[v][i];
		if(state[nxt]==initial)
			dfs_visit(nxt);
	}
	
	state[v]=visited;
	
}
int main()
{
	//printf("Enter the number of vertex and edges\n");
	scanf("%d%d",&n,&e);
	int x,y;
	for(int i=1;i<=e;i++)
	{
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	
	}
	for(int i=1;i<=n;i++)
	{
		state[i]=initial;
	}
	dfs_visit(1);
	
	if(e==n-1&&count1==n)
		printf("YES\n");
	else{
		printf("NO\n");
	}
	

}