// simple dfs is used
#include<bits/stdc++.h>
using namespace std;
int finald=0,r,c;
char matrix[100][100];
int visited[100][100];
void dfs(int ro,int co,int depth )
{
	finald=max(finald,depth);
	int xaxis[8]={1,1,1,0,0,-1,-1,-1};
	int yaxis[8]={-1,0,1,-1,1,-1,0,1};
	for(int i=0;i<8;i++)
	{
		int tempr=ro+xaxis[i];
		int tempc=co+yaxis[i];

		if((tempr>=0&&tempr<r)&&(tempc>=0&&tempc<c)&&!visited[tempr][tempc])
		{
			if(matrix[tempr][tempc]==matrix[ro][co]+1)
			{
				visited[tempr][tempc]=1;
				//printf("call for %d  %d\n", tempr,tempc);
				dfs(tempr,tempc,depth+1);
			}
		}
	}
}
int main()
{
	int i,j,k,t=0;
	
	while(++t>0)
	{
		cin>>r>>c;
		if(r==0||c==0)
			break;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>matrix[i][j];
				visited[i][j]=0;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(matrix[i][j]=='A')
				{
					visited[i][j]=1;
				//	printf("first call %d  %d\n", i,j);
					dfs(i,j,1);

				}
			}
		}
		printf("Case %d: %d\n",t,finald);
		finald=0;
	}
	
}