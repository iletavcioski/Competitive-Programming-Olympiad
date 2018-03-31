#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Izbor 
{
	int vrednost,a,b;
};
bool compare(const Izbor &x,const Izbor &y)
{
	return x.vrednost<y.vrednost;
}
int p[202];
int d[202];
bool cc=false;
int dsu(int a)
{
	if(p[a]==-1)
		return a;
	else
		return dsu(p[a]);
}
void dsu1(int a,int b)
{
	if(p[a]!=b)
	{
		int c=p[a];
		p[a]=b;
		dsu1(c,b);
	}
}
vector<vector<int> >v;
int bb;
bool visi[202];
void dfs(int x)
{
	if(visi[x])
		return;
	visi[x]=true;
	bb++;
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<Izbor> vec;
	vector<int> vecc;
	v.insert(v.begin(),n+1,vecc);
	for(int i=0;i<m;i++)
	{
		vector<Izbor> vv;
		int mst=0;
		Izbor g;
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		g.vrednost=c;
		if(!cc)
		{
		v[a].push_back(b);
		v[b].push_back(a);
		}
		g.a=a;
		g.b=b;
		vec.push_back(g);
		sort(vec.begin(),vec.end(),compare);
		for(int ii=0;ii<n;ii++)
		{
			p[ii]=-1;
			d[ii]=0;
			visi[ii]=false;
		}
		int j=0;
		while(j<vec.size())
		{
			g=vec[j];
			int a=g.a;
			int b=g.b;
			j++;
			a=dsu(a);
			b=dsu(b);
			if(a==b&&a!=-1)
			{
				continue;
			}
			else
			{
				vv.push_back(g);
				mst+=g.vrednost;
				v[g.a].push_back(g.b);
				v[g.b].push_back(g.a);
				if(d[a]<d[b])
				{
					p[b]=a;
					dsu1(g.b,a);
				}
				else if(d[a]>d[b])
				{
					p[a]=b;
					dsu1(g.a,b);
				}
				else
				{
					p[a]=b;
					dsu1(g.a,b);
					d[b]++;
				}
			}
		}
		bb=0;
		if(!cc)
		dfs(0);
		if(bb==n||cc)
		{
			cc=true;
			cout<<mst<<endl;
		}
		else
			cout<<-1<<endl;
		vec=vv;
	}
	return 0;
}