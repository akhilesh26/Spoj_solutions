#include<stdio.h>

int main()
{
	float a,b;
	int n, card;

	while(1)
	{	b=0;
		card=1;
		scanf("%f",&a);
		if(a==0)
			break;

		while(a>b)
		{
			card++;
			b += 1.0/card;
			
		}

		printf("%d card(s)\n",card-1);
	}
}