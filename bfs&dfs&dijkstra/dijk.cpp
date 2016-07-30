#include<bits/stdc++.h>
using namespace std;
vector< pair<int, int> > adj[10001];
int v,e,dis[10001];
bool status[10001];

int dijk(int s,int d)
{

	auto comp = [] (int &a, int &b) -> bool { return dis[a] > dis[b]; };
	priority_queue<int,vector<int>, decltype(comp) > pq (comp);

	dis[s]=0;
	pq.push(s);

	while(!pq.empty())
	{
		s = pq.top();
		pq.pop();
		status[s] = true;
		//cout << s << endl;
		for(int i=0; i<adj[s].size(); i++)
		{
			int v = adj[s][i].first;
			int w = adj[s][i].second;
			//cout << w << " " << v << endl;
			if(status[v] == false && dis[s] + w < dis[v])
			{
				dis[v] = dis[s] + w;
				pq.push(v);
			}
		}
	}

	return dis[d];
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		cin >> v >> e;
		
		fill(status, status+10000, false);
		fill(dis, dis+10000,1000000);

		for(int i = 1; i<=10000; i++)
			adj[i].clear();

		while(e--)
		{
			int a,b,c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
		}

		int s, d;
		cin >> s >> d;
		int ans = dijk(s,d);

		if(ans>=1000000)
			printf("NO\n");
		else
			printf("%d\n",ans);
	}
}

