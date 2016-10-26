#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void * a, const void * b)
{

	int x = abs(*(int *)a), y = abs(*(int *)b);
   	return (x-y);

}

int main(){
	int n, i = 0, x, j;
	scanf("%d", &n);
	int in, out;
	int max, present;
	while(i < n){
		max = 0, present = 0;
		scanf("%d", &x);
		int arr[2*x];

		for( j = 0; j<(2*x); j+=2){
			scanf("%d %d", &in, &out);
			arr[j] = in;
			arr[j+1] = -out;
		}

		qsort(arr, 2*x, sizeof(int), cmpfunc);

		for(j = 0; j<(2*x); j++){
			if(arr[j] < 0)
				present--;
			else
				present++;

			if(present > max)
				max = present;
		}
		printf("%d\n", max);
		i++;
	}
	return 0;
}
