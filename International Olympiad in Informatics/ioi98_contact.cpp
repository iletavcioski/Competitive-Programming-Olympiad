#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
//ifstream fin("contact.in");
//ofstream fout("contact.out");
struct Izbor
{
	string b;
	int c;
	int t;
};
bool compare(const Izbor &x,const Izbor &y)
{
	if(x.c!=y.c)
		return x.c>y.c;
	if(x.c==y.c)
		return x.t>y.t;
}
int main()
{

	int a,b,n;
	cin>>a>>b>>n;
	string ss="";
cin>>ss;
		vector<Izbor> vkraj;
	int mat[13][5000];
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<5000;j++)
			mat[i][j]=0;
	}
	for(int i=ss.size()-2;i>=0;i--)
	{
		int broj=0;
		for(int j=0;j<12;j++)
		{
			if(i-j<0)
				break;
			if(ss[i-j]=='1')
				broj+=pow(2.00,j);
			mat[j+1][broj]++;
		}
	}
	vector<pair<int,pair<int,int> > > v;
	for(int i=a;i<=b;i++)
	{
		for(int j=0;j<5000;j++)
		{
			v.push_back(make_pair(mat[i][j],make_pair(j,i)));
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int po=-1;
	int brojac=0;
	vector<pair<int,int> > vk;
	for(int i=0;i<v.size();i++)
	{
		
		if(v[i].first!=po){
			
			if(po!=-1){
				brojac++;
			if(brojac>n)
				break;
			cout<<po;
			sort(vk.begin(),vk.end());
		
			for(int j=0;j<vk.size();j++)
			{
				
		string s="";
		int p=vk[j].first;
		while(p>0)
		{
			s+=((p%2)+'0');
			p/=2;
		}
		while(s.size()<vk[j].second)
			s+='0';
		reverse(s.begin(),s.end());
		Izbor g;
		g.b=s;
		g.c=s.size();
		g.t=vk[j].first;
		vkraj.push_back(g);
				
			}

			sort(vkraj.begin(),vkraj.end(),compare);
			for(int ii=0;ii<vkraj.size();ii++)
			{
					cout<<" "<<vkraj[ii].b;
			}
			cout<<endl;
			}
			vkraj.clear();
			vk.clear();
			po=v[i].first;
			vk.push_back(make_pair(v[i].second.first,v[i].second.second));
			
		}
		else
			vk.push_back(make_pair(v[i].second.first,v[i].second.second));
		
	}
	return 0;
}