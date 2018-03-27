#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	int open_parenthesis=0;
	int last_magic_lenght=0;
	int magic_parenthesis=0;
	char ch;
	for(int i=0;i<n;i++)
	{

		cin>>ch;
		if(ch=='(')
			open_parenthesis++;
		else if(ch==')')
		{
			if(open_parenthesis>0)
				open_parenthesis--;
			else if(last_magic_lenght>0)
				last_magic_lenght--;
			else
			{
				printf("0\n");
				return 0;
			}
		}
		else
		{
			if(magic_parenthesis==0)
			{
				magic_parenthesis=1;
				last_magic_lenght=open_parenthesis;
				open_parenthesis=0;
			}
			else if(open_parenthesis>0||last_magic_lenght>0)
			{
				magic_parenthesis++;
				last_magic_lenght=last_magic_lenght-1+open_parenthesis;
				open_parenthesis=0;
			}
			else
			{
				printf("0\n");
				return 0;
			}
		}
	}
		printf("1\n");
		for(int i=0;i<m-1;i++)
			printf("1\n");
		printf("%d\n",last_magic_lenght);
	
	return 0;
}