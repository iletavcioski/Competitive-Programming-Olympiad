#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int>fenwicktree(100001,0);
int n;
void update(int x,int val)
{
	for(int i=x;i<100001;i+=(i&-i))
		fenwicktree[i]+=val;
}
int query(int x)
{
	int brojac=0;
	for(int i=x;i>0;i-=(i&-i))
		brojac+=fenwicktree[i];
	return brojac;
}
int binarysearch(int val)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(query(mid)<=val)
			l=mid+1;
		else
			r=mid-1;
	}
	return r;
}
int main()
{
        ios_base::sync_with_stdio(false);
	vector<int> dp(100001,0);
	set<int> ss;
	int c,r;
	cin>>n>>c>>r;
	vector< pair<int,int> >intervali;
	vector< pair<int,int> >bst;
	pair<int,int> p=make_pair(0,0);
	intervali.insert(intervali.begin(),n+c+3,p);
	bst.insert(bst.begin(),n+c+3,p);
	int k[100001];
	int s[100001];
	int e[100001];
	for(int i=1;i<=n;i++)
	{
		if(i<n)
        {
            cin>>k[i];
			dp[i]=k[i];
        }
		dp[i]=dp[i-1]+(dp[i]>r);
		intervali[i]=make_pair(i,i);
		bst[i]=make_pair(0,i);
		update(i,1);
		ss.insert(i);
	}
	for(int i=1;i<=c;i++)
	{
		cin>>s[i]>>e[i];
		s[i]++;
		e[i]++;
	}
	for(int i=1;i<=c;i++)
	{
		int node=n+i;
		int x=binarysearch(s[i]-1)+1;
		int y=binarysearch(e[i]);
		int mozi=dp[y-1]-dp[x-1];
		if(mozi)
		{
			bst[node]=make_pair(0,node);
		}
		else
		{
			bst[node]=make_pair(-1,node);
			int j=x;
			while(j<=y)
			{
				int index=intervali[j].second;
				if(bst[node].first<bst[index].first)
					bst[node]=bst[index];
				j=intervali[j].first+1;
			}
			bst[node].first++;
		}
		intervali[x]=make_pair(y,node);
		set<int>::iterator it=ss.find(x);
		for(;*it<=y&&it!=ss.end();)
		{
			set<int>::iterator it1=it;
			it++;
			update(*it1,-1);
			ss.erase(it1);
		}
		ss.insert(x);
		update(x,1);
	}
	int maxi=-1;
	int pozicija=9999999;
	for(int i=1;i<=n+c;i++)
	{
		if(maxi<bst[i].first)
		{
			maxi=bst[i].first;
			pozicija=bst[i].second;
		}
		else if(maxi==bst[i].first)
		{
			if(bst[i].second<pozicija)
			{
				pozicija=bst[i].second;
			}
		}
	}
	cout<<pozicija-1<<endl;
	return 0;
}