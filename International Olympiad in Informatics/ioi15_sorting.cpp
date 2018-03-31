#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int> v;
vector<int> v1,v2;
vector<pair<int,int> >vkraj;
bool mozi(int vreme)
{
	vector<int> vec=v;
	for(int i=0;i<vreme;i++) 
	{
		swap(vec[v1[i]],vec[v2[i]]);
	}
	vector<pair<int,int> >zameni;
	for (int i = 0; i < n; i++)
	{
		while(vec[i]!=i)
		{
			zameni.push_back(make_pair(vec[i],vec[vec[i]]));
			swap(vec[i],vec[vec[i]]);
		}
	}
	while(zameni.size()<vreme)
		zameni.push_back(make_pair(0,0));
		if(zameni.size()>vreme) 
			return false;
		vec=v;
		vector<int> indexi(n,-1);
		for(int i=0;i<n;i++)
		{
			indexi[vec[i]]=i;
		}
		vector<pair<int,int> >kraj;
		for(int i=0;i<vreme;i++)
		{
			int x=v1[i];
			int y=v2[i];
			swap(indexi[vec[x]],indexi[vec[y]]);
			swap(vec[x],vec[y]);
			x=zameni[i].first;
			y=zameni[i].second;
			kraj.push_back(make_pair(indexi[x],indexi[y]));
			swap(vec[indexi[x]],vec[indexi[y]]);
			swap(indexi[x],indexi[y]);
		}
		vkraj=kraj;
		return true;
}
int main() 
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	cin>>m;
	for(int i=0;i<m;i++) 
	{
		int a,b;
		cin>>a>>b;
		v1.push_back(a);
		v2.push_back(b);
	}
	int l=0,r=m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(mozi(mid)) 
		{
			r=mid;
		}
		else 
			l=mid+1;
	}
	mozi(l);
	cout<<vkraj.size()<<endl;
	for (int i=0;i<vkraj.size();i++)
	{
		cout<<vkraj[i].first<<" "<<vkraj[i].second<<endl;
	}
	return 0;
}