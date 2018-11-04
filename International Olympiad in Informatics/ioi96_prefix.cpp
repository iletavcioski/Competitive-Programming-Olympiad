#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	vector<string> v;
	string ss;
	while(1)
	{
		cin>>ss;
		if(ss==".")
			break;
		v.push_back(ss);
	}
	string sk="";
	string ssk;
    while(cin>>ssk){
        sk+=ssk;
    }
	string s="";
	
	vector<int> dp(sk.size()+1,0);
	dp[0]=1;
	for(int i=0;i<=sk.size();i++)
	{
		for(int j=0;j<v.size();j++)
		{
			if(i+v[j].size()<=sk.size())
			{
				if(dp[i]&&!dp[i+v[j].size()]&&(v[j]==sk.substr(i,v[j].size())))
					dp[i+v[j].size()]=1;
			}
		}
	}
	for(int i=dp.size()-1;i>=0;i--)
		if(dp[i]){
			cout<<i<<endl;
			return 0;
		}
	return 0;
}