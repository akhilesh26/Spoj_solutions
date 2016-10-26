#include <bits/stdc++.h>
#define MAX 1010

using namespace std;
char graph[MAX][MAX];
int done[MAX][MAX], dist[MAX][MAX];
int firstStageX, firstStageY;

int find(int rx, int ry, int x, int y){
	stack <int> q1, q2;
	int i, j, curX, curY;

	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			done[i][j] = 0;
			dist[i][j] = 0;
		}
	}

	q1.push(rx);
	q2.push(ry);
	done[rx][ry] = 1;
	dist[rx][ry] = 0;

	while(!q1.empty()){
		curX = q1.top();
		q1.pop();
		curY = q2.top();
		q2.pop();

		if(curX - 1 >= 0){
			if(graph[curX - 1][curY] == '.' && !done[curX - 1][curY]){
				q1.push(curX - 1);
				q2.push(curY);
				done[curX - 1][curY] = 1;
				dist[curX - 1][curY] = dist[curX][curY] + 1;
			}
		}

		if(curX + 1 < x){
			if(graph[curX + 1][curY] == '.' && !done[curX + 1][curY]){
				q1.push(curX + 1);
				q2.push(curY);
				done[curX + 1][curY] = 1;
				dist[curX + 1][curY] = dist[curX][curY] + 1;
			}
		}

		if(curY - 1 >= 0){
			if(graph[curX][curY - 1] == '.' && !done[curX][curY - 1]){
				q1.push(curX);
				q2.push(curY - 1);
				done[curX][curY - 1] = 1;
				dist[curX][curY - 1] = dist[curX][curY] + 1;
			}
		}

		if(curY + 1 <  y){
			if(graph[curX][curY + 1] == '.' && !done[curX][curY + 1]){
				q1.push(curX);
				q2.push(curY + 1);
				done[curX][curY + 1] = 1;
				dist[curX][curY + 1] = dist[curX][curY] + 1;
			}
		}
	}

	int max = 0;
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			if(dist[i][j] > max){
				max = dist[i][j];
				firstStageX = i;
				firstStageY = j;
			}
		}
	}

	return max;
}

int main(){
	int t, p = 0, x, y, i, j, ans, flag;
	scanf("%d", &t);

	while(p < t){
		scanf("%d %d", &y, &x);

		for(i = 0; i < x; i++){
			scanf("%s", graph[i]);
		}

		flag = 0;
		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				if(graph[i][j] == '.'){
					find(i, j, x, y);
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}

		if(flag == 0)
			printf("Maximum rope length is 0\n");

		else {
			ans = find(firstStageX, firstStageY, x, y);
			printf("Maximum rope length is %d.\n", ans);	
		}

		++p;
	}

	return 0;
}
