#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int size,i,j,k,m,n,x;
  	char ch;
  	long int q,r;
  	cin>>size;
  	long long int A[size][size],B[size][size],v,sum;

  	for(i=0;i<size;i++)
  		{	
    	for(j=0;j<size;j++)
    		{
      		cin>>A[i][j];
    		}
  		}

  	for(i=0;i<size;i++)
  		{
    	for(j=0;j<size;j++)
    		{
      		cin>>B[i][j];
    		}
  		}

sum=0;
for(i=0;i<size;i++)
  		{
  			for(j=0;j<size;j++)
  			{
  				for(k=0;k<size;k++)
  				{
  					sum=sum+(A[i][k]*B[k][j]);
  				}
  			}
  		}


  	cin>>q;
  	for(r=0;r<q;r++)
  	{
  		cin>>ch>>m>>n>>v;


  		if(ch=='A')
  		{
  			for(x=0;x<size;x++)
  			{
  				sum=sum-(A[m][n]*B[n][x])+(v*B[n][x]);
  			}
  		}
  		else if(ch=='B')
  		{
  			for(x=0;x<size;x++)
  			{
  				sum=sum-(B[m][n]*A[x][m])+(v*A[x][m]);
  			}
  		}
  		
  		if(ch=='A')
  		{
  			A[m][n]=v;
  		}
  		else if(ch=='B')
  		{
  			B[m][n]=v;
  		}

  		cout<<sum<<"\n";
  	}
return 0;
}