#include<stdio.h>
int main()
{
 long long int test;
 long long int n,k;
 scanf("%lld",&test);
 
 while(test--!=0)
 {
  scanf("%lld",&n);
  k = (3*n)%11;
  if(k<0)
  k+=11;
  
  printf("%lld\n",k);
 }
 
 return 0;
 } 
