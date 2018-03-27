#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int maxi,mini;
};
node segtree[4*1000001];
vector<int> v;
int I,J;
void build(int l,int r,int p)
{
	if(l==r)
	{
		segtree[p].maxi=v[l];
		segtree[p].mini=v[l];
		return;
	}
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
	segtree[p].maxi=max(segtree[2*p].maxi,segtree[2*p+1].maxi);
	segtree[p].mini=min(segtree[2*p].mini,segtree[2*p+1].mini);
}
int querymax(int l,int r,int p)
{
	if(l>J||r<I)
		return -1;
	if(l>=I&&r<=J)
		return segtree[p].maxi;
	return max(querymax(l,(l+r)/2,2*p),querymax((l+r)/2+1,r,2*p+1));
}
int querymin(int l,int r,int p)
{
	if(l>J||r<I)
		return 1000000000;
	if(l>=I&&r<=J)
		return segtree[p].mini;
	return min(querymin(l,(l+r)/2,2*p),querymin((l+r)/2+1,r,2*p+1));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m,c;
	cin>>n>>m>>c;
	bool cc=false;
	for(int i=0;i<=2*n;i++)
	{
		segtree[i].maxi=-1;
		segtree[i].mini=1e9;
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	build(0,n-1,1);
	for(int i=0;i<n;i++)
	{
		I=i,J=i+m-1;
		if(J>=n)
			break;
		if((querymax(0,n-1,1)-querymin(0,n-1,1))<=c)
		{
			cc=true;
			cout<<i+1<<"\n";
		}
	}
	if(!cc)
	{
		cout<<"NONE"<<endl;
	}
	return 0;
}