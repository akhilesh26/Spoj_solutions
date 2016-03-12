#include<bits/stdc++.h>
using namespace std;
char str[1000009],rstr[1000009],pd[1000009];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		
		int n=strlen(str);
		int m=n;
		int c=0;
		while(m>=0)
		{
			rstr[c]=str[m-1];
			c++;
			m--;

		}
		//condition for all 9-------------------------------------------------------------------
		int f=0;
		for(int i=0;i<n;i++)
		{
			//cout<<str[i]-'0'<<endl;
			if(str[i]-'0'!=9)
			{
				f=1;
			}
		}
		if(f==0)
		{
			pd[0]='1';
			for(int i=1;i<n;i++)
				pd[i]='0';
			pd[n]='1';
			pd[n+1]='\0';
			cout<<pd<<endl;
			
			
		}
		
		//otherwise-----------------------------------------------------------------
		else
		{
			strcpy(pd,str);
			//if number is pal-----------------------------------------------------------------------------
			if(!strcmp(str,rstr))
			{
				// even no of digits-----------------------------------------
				if(n%2==0)
				{
					int x=n/2;
					if(str[x]=='9'&&str[x-1]=='9')
					{
						int i=0,j=1;
						do
						{
							str[x+i]='0';
							str[x-j]='0';
							i++;
							j++;
							str[x+i]++;
							str[x-j]++;
						}
						while(str[x+i]==':'&&str[x-j]==':');
						cout<<str<<endl;
					}
					else
					{
						str[x]++;
						str[x-1]++;
						cout<<str<<endl;
					}

					
				}
				else
				{
					// odd no of digits---------------------------------------
					int x=n/2;
					if(str[x]=='9')
					{	int i=0;
						do
						{
							str[x+i]='0';
							str[x-i]='0';
							i++;
							str[x+i]++;
							str[x-i]++;
						}
						while(str[x+i]==':'&&str[x-i]==':');
						cout<<str<<endl;
					}
					else
					{
						str[x]++;
						cout<<str<<endl;
					}
				}


			}
			else
			{
				// no is not pal----------------------------------------------------no is not pal
				
				if(n%2==0)
				{
					// even num. of digits ---------------------------
					int x=n/2;
					int y=x;
					for(int i=x;i<n;i++)
					{
						pd[i]=str[--y];
					}
					
					if(strcmp(str,pd)>0)
					{
						if(str[x]=='9'&&str[x-1]=='9')
						{
							int i=0,j=1;
							do
							{
								pd[x+i]='0';
								pd[x-j]='0';
								i++;
								j++;
								pd[x-j]++;
								pd[x+i]=pd[x-j];
							}
							while(pd[x+i]==':'&&pd[x-j]==':');
							cout<<pd<<endl;
						}
						else
						{
							pd[x]++;
							pd[x-1]++;
							cout<<pd<<endl;
						}	
					}
					else
					{
						cout<<pd<<endl;
					}
				}
				else
				{
					//odd no. of digits-------------------------------odd no. of digits-
					int x=n/2;
					int y=x;
					for(int i=x+1;i<n;i++)
					{
						pd[i]=str[--y];
					}
					
					if(strcmp(str,pd)>0)
					{

						if(str[x]=='9')
						{
							int i=0;
							do
							{
								pd[x+i]='0';
								pd[x-i]='0';
								i++;
								
								pd[x-i]++;
								pd[x+i]=pd[x-i];
							}
							while(pd[x+i]==':'&&pd[x-i]==':');
							cout<<pd<<endl;
						}
						else
						{
							pd[x]++;
							cout<<pd<<endl;
						}
					}
					else
					{
						cout<<pd<<endl;
					}
				}
			}
		}
	}
}