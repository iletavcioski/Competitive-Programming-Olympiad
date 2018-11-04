#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
//ifstream fin("lamps.in");
//ofstream fout("lamps.out");
	int n;
	cin>>n;
	vector<int> v1;
	vector<int> v2;
	int c;
	cin>>c;
if(c>=4)
	{
		if(c%2==0)
			c=4;
		else
			c=5;
	}
	while(1)
	{
		int a;
		cin>>a;
		if(a==-1)
			break;
		v1.push_back(a);
	}
	while(1)
	{
		int a;
		cin>>a;
		if(a==-1)
			break;
		v2.push_back(a);
	}
	string ss="";
	for(int i=0;i<n;i++)
		ss+='1';
	queue<string> qi;
	qi.push(ss);
	queue<int> qs;
	qs.push(0);
	map<string,bool> m;
	int brojac=0;
	vector<string> v;
	while(!qi.empty())
	{
		int tops=qs.front();
		string topi=qi.front();
		qi.pop();
		qs.pop();
		if(tops==c)
		{
			v.push_back(topi);
			continue;
		}
		if(tops!=brojac)
		{
			brojac=tops;
			m.clear();
		}
		string tt=topi;
		string t1=topi;
		string t2=topi;
		string t3=topi;
		for(int i=0;i<n;i++)
		{
			string tt=topi;
			if(i%2)
			{
				if(tt[i]=='1')
					tt[i]='0';
				else
					tt[i]='1';
			}
			else
			{
				
				if(t1[i]=='1')
					t1[i]='0';
				else
					t1[i]='1';
			}
			
				if(t2[i]=='1')
					t2[i]='0';
				else
					t2[i]='1';
		}
		if(!m[tt])
		{
			qi.push(tt);
			qs.push(tops+1);
			m[tt]=true;
		}
		if(!m[t2])
		{
			qi.push(t2);
			qs.push(tops+1);
			m[t2]=true;
		}
		if(!m[t1])
		{
			qi.push(t1);
			qs.push(tops+1);
			m[t1]=true;
		}
		for(int i=1;i<=n;i+=3)
		{
			if(t3[i-1]=='1')
				t3[i-1]='0';
			else
				t3[i-1]='1';
		}
		if(!m[t3])
		{
			qi.push(t3);
			qs.push(tops+1);
			m[t3]=true;
		}
	}
	sort(v.begin(),v.end());
	bool cc=false;
	for(int i=0;i<v.size();i++)
	{
		bool c1=true;
		bool c2=true;
		for(int j=0;j<v1.size();j++)
		{
			if(v[i][v1[j]-1]=='0'){
				c1=false;
				break;
			}
		}
		for(int j=0;j<v2.size();j++)
		{
			if(v[i][v2[j]-1]=='1'){
				c2=false;
				break;
			}
		}
			if(c1&&c2){
				cout<<v[i]<<endl;
				cc=true;
			}
	}
		if(!cc)
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
	return 0;
}