#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v1;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v1.push_back(a);
	}
	vector<int> v;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	queue<int> qi;
	vector<int> visi(n+5,-1);
	for(int i=0;i<2*m;i++)
	{
		int a;
		cin>>a;
		qi.push(a);
	}
	ll brojac=0;
	queue<int> cheka;
	while(!qi.empty())
	{
		if(!cheka.empty())
		{
			int topi=cheka.front();
			bool cc=false;
			for(int i=0;i<n;i++)
			{
				if(visi[i]==-1)
				{
					brojac+=v1[i]*v[topi-1];
					visi[i]=topi;
					cc=true;
					break;
				}
			}
			if(cc)
				cheka.pop();
		}
		int topi=qi.front();
		qi.pop();
		if(topi>0)
		{
			bool cc=false;
			for(int i=0;i<n;i++)
			{
				if(visi[i]==-1)
				{
					brojac+=v1[i]*v[topi-1];
					visi[i]=topi;
					cc=true;
					break;
				}
			}
			if(!cc)
				cheka.push(topi);
		}
		else
		{
			topi*=-1;
			for(int i=0;i<visi.size();i++)
			{
				if(visi[i]==topi)
				{
					visi[i]=-1;
					break;
				}
			}
		}
	}
	cout<<brojac<<endl;
	return 0;
}