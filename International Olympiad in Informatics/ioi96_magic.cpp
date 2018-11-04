#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
int main()
{
//ifstream fin("msquare.in");
//ofstream fout("msquare.out");
	string s1="12345678";
	string s2="";
	map<string,bool> m;
	for(int i=0;i<8;i++)
	{
		int a;
		cin>>a;
		s2+=a+'0';
	}

	m[s1]=true;
	queue<string> qi;
	queue<string> qs;
	qi.push(s1);
	qs.push("");
	while(!qi.empty())
	{
		string topi=qi.front();
	qi.pop();
	string tops=qs.front();
	qs.pop();
	if(topi==s2)
	{
		cout<<tops.size()<<endl;;
		if(tops.size()){
		for(int i=0;i<tops.size();i++){
			cout<<tops[i]<<endl;
		}
		}
		
		return 0;
	}
	string s=topi;
	swap(s[0],s[7]);
	swap(s[1],s[6]);
	swap(s[2],s[5]);
	swap(s[3],s[4]);
	if(!m[s])
	{
		qi.push(s);
		qs.push(tops+'A');
m[s]=true;
	}
s=topi;
	swap(s[3],s[2]);
	swap(s[2],s[1]);
	swap(s[1],s[0]);
	swap(s[4],s[5]);
	swap(s[5],s[6]);
	swap(s[6],s[7]);
	if(!m[s])
	{
		qi.push(s);
		qs.push(tops+'B');
m[s]=true;
	}
	s=topi;
	swap(s[5],s[2]);
	swap(s[2],s[1]);
	swap(s[1],s[6]);
	if(!m[s])
	{
		qi.push(s);
		qs.push(tops+'C');
m[s]=true;
	}
	
	}

	return 0;
}