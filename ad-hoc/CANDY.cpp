#include <bits/stdc++.h>

int main(){
	int n, i, sum, ans;
	while(1){
		scanf("%d", &n);
		if(n == -1)
			break;

		sum = 0;
		int arr[n];

		for(i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}

		if(sum % n != 0){
			printf("-1\n");
			continue;
		}

		sum = sum/n;
		ans = 0;
		for(i = 0; i < n; i++){
			if(arr[i] < sum)
				ans += (sum - arr[i]);
		}

		printf("%d\n", ans);

	}
}
