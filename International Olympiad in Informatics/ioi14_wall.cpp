#include <iostream>
using namespace std;
const int inf=1000000006;
int segmax[8000000];
int segmin[8000000];
int array[4000000];
int I,J,value,type;
void merge(int x,int y)
{
	segmin[y]=min(segmin[x],segmin[y]);
	segmin[y]=max(segmin[y],segmax[x]);
	segmax[y]=max(segmax[x],segmax[y]);
	segmax[y]=min(segmin[x],segmax[y]);
}
void update(int l,int r,int p)
{
	if(l>J||r<I)
		return;
	if(l>=I&&r<=J)
	{
		if(type==1)
		{
			segmax[p]=max(segmax[p],value);
			segmin[p]=max(segmin[p],value);
		}
		else
		{
			segmax[p]=min(segmax[p],value);
			segmin[p]=min(segmin[p],value);
		}
		return;
	}
	if(l!=r)
	{
		merge(p,2*p);
		merge(p,2*p+1);
		segmin[p]=inf;
		segmax[p]=0;
	}
	update(l,(l+r)/2,2*p);
	update((l+r)/2+1,r,2*p+1);
}
void lowering(int l,int r,int p)
{
	if(l==r)
	{
		array[l]=min(segmin[p],segmax[p]);
		return;
	}
	merge(p,2*p);
	merge(p,2*p+1);
	lowering(l,(l+r)/2,2*p);
	lowering((l+r)/2+1,r,2*p+1);
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<4*n;i++)
	{
		segmax[i]=0;
		segmin[i]=inf;
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d %d",&type,&I,&J,&value);
		update(0,n-1,1);
	}
	lowering(0,n-1,1);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",array[i]);
	}
	return 0;
}