#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int I,J;
int lazy[400001];
vector<int> v;
void query(int l,int r,int p)
{
	if(l==r)
	{
		v[l]+=lazy[p];
		lazy[p]=0;
		return;
	}
	if(lazy[p])
	{
		lazy[2*p]+=lazy[p];
		lazy[2*p+1]+=lazy[p];
		lazy[p]=0;
	}
	if(I>r||I<l)
		return;
	query(l,(l+r)/2,2*p);
	query((l+r)/2+1,r,2*p+1);
}
void update(int l,int r,int p)
{
	if(lazy[p])
	{
		if(l!=r)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
			lazy[p]=0;
		}
	}
	if(l>=I&&r<=J)
	{
		lazy[p]++;
		return;
	}
	if(l>J||r<I)
		return;
	update(l,(l+r)/2,2*p);
	update((l+r)/2+1,r,2*p+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	vector<int> kraj;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	//for(int i=0;i<n;i++)
	//	cout<<v[i]<<" ";
	for(int i=0;i<m;i++)
	{
		char a;
		cin>>a;
		if(a=='F')
		{
			int x,y;
			cin>>x>>y;
			int poc=n+1;
			int l=0,r=n-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				I=mid;
				query(0,n-1,1);
				if(v[mid]>=y)
				{
					r=mid-1;
					poc=min(poc,mid);
				}
				else
				{
					l=mid+1;
				}
			}
			if(poc==n+1)
				continue;
			I=min(n-1,poc+x-1);
			x=I-poc+1;
			query(0,n-1,1);
			int val=v[I];
			int kraj=-1;
			l=0,r=n-1;
			//cout<<endl;
			bool cc=false;
			if(I==n-1)
			{
				I=poc,J=n-1;
				update(0,n-1,1);
				continue;
			}
			while(l<=r)
			{
				int mid=(l+r)/2;
				I=mid;
				//cout<<mid<<endl;
				query(0,n-1,1);
				//cout<<v[mid]<<endl;
				if(v[mid]>=val)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
					kraj=max(kraj,mid);
				}
			}
			I=poc,J=kraj;
			int br1=kraj-poc+1;
			br1=x-br1;
			update(0,n-1,1);
			l=0,r=n-1;
			int kraj2=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				I=mid;
				query(0,n-1,1);
				if(v[mid]>val)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
					kraj2=max(kraj2,mid);
				}
			}
			int poc2=kraj2-br1+1;
			I=poc2,J=kraj2;
			update(0,n-1,1);
			//cout<<poc<<" "<<kraj<<" "<<poc2<<" "<<kraj2<<endl;
		}
		else
		{
			int x,y;
			cin>>x>>y;
			int l=0,r=n-1;
			int mini=n+1;
			int maxi=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				I=mid;
				query(0,n-1,1);
				if(v[mid]>=x)
				{
					r=mid-1;
					mini=min(mini,mid);
				}
				else
				{
					l=mid+1;
				}
			}
			l=0,r=n-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				I=mid;
				query(0,n-1,1);
				if(v[mid]<=y)
				{
					l=mid+1;
					maxi=max(maxi,mid);
				}
				else
				{
					r=mid-1;
				}
			}
			//cout<<"\n";
			/*for(int j=0;j<n;j++)
			{
				I=j;
				query(0,n-1,1);
				cout<<v[j]<<" ";
			}
			cout<<endl;*/
			if(maxi==-1||mini==n+1)
			{
				kraj.push_back(0);
			}
			else
			{
				kraj.push_back(maxi-mini+1);
			}
		}
	}
	for(int i=0;i<kraj.size();i++)
	{
		cout<<kraj[i]<<"\n";
	}
	return 0;
}