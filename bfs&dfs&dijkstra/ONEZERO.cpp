#include <bits/stdc++.h>

using namespace std;

int done[20005];

int checkDivisibility(string x, int rem, int num){
	int len = x.length();
	return ((rem*10) + (x[len - 1] - '0'))%num;
}

string findMultiple(int x){
	queue <string> q;
	queue <int> q1;
	string cur = "1";
	int cur2, rem, i;
	q.push(cur);
	q1.push(0);

	for(i = 0; i < x; i++)
		done[i] = 0;

	while(1){
		cur = q.front();
		cur2 = q1.front();
		q.pop();
		q1.pop();

		rem = checkDivisibility(cur, cur2, x);
		if(rem == 0)
			return cur;

		if(!done[rem]){
			q.push(cur + "0");
			q1.push(rem);
			q.push(cur + "1");
			q1.push(rem);
			done[rem] = 1;
		}
		
	}
		return cur;
}

int main(){
	int t, i = 0, x;
	scanf("%d", &t);
	while(i < t){
		scanf("%d", &x);
		cout << findMultiple(x) << "\n";
		i++;
	}
}
