#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	scanf("%d%d",&a,&b);
	int mini=a,maxi=b,best=1e9;
	best=b-a+1;
	for(int i=0;i<n-2;i++)
	{
		scanf("%d",&a);
		int a1=mini;
		mini=max(b,2*b-maxi);
		maxi=min(2*b-a1,a);
		a1=max(a1,max(2*b-maxi,0));
		if(mini>a)
			best=0;
		best=min(best,max(maxi-mini+1,0));
		swap(a,b);
	}
	cout<<best<<endl;
	return 0;
}