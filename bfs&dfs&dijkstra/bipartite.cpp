#include<bits/stdc++.h>
using  namespace std;
#define max 2005
int v,e;
int graph[max][max];
int color[max];


bool bfs(int s)
{
	queue<int> q;
	color[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();

		q.pop();
		//cout<<u<<endl;
		for(int i=1;i<=v;i++)
		{
			if(i==u) continue;
			if(graph[u][i]&&color[i]==-1)
			{
				color[i]=1-color[u];
				q.push(i);
			}
			else if(graph[u][i]&&color[u]==color[i])
			{
				return false;
			}
		}

	}

	return true;
}

int main()
{
	int t,c=0;
	cin>>t;

	while(t--)
	{
		c++;
		cin>>v>>e;
		for(int i=1;i<=e;i++)
		{
			int v1,v2;
			cin>>v1>>v2;
			graph[v1][v2]=1;
			graph[v2][v1]=1;
		}
		for(int i=1;i<=v;i++)
		{
			color[i]=-1;
		}
		int f=0;
		for(int i=1;i<=v;i++){
			if(color[i]==-1)
			{
				if(!bfs(i)){
					f=1;
					break;
				}
			}
		}

		printf("Scenario #%d:\n",c);
		if(f==1)
		{
			cout<<"Suspicious bugs found!\n";
		}
		else
			cout<<"No suspicious bugs found!\n";


		memset(graph,0,sizeof(graph));
	}
	

}