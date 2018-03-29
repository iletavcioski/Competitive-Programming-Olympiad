#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0||n==1)
	{
		cout<<"NOT POSSIBLE"<<endl;
		return 0;
	}
	string ss;
	cin>>ss;
	int j=ss.size()/2;
	set<string> s;
	int i=0;
	string s1="";
	string s2;
	while(i<ss.size()/2&&j<ss.size())
	{
		if(ss[i]==ss[j])
		{
			s1+=ss[i];
			j++,i++;
		}
		else
			j++;
		if(s1.size()==ss.size()/2)
		{
			s.insert(s1);
			break;
		}
 
	}
	 i=ss.size()-1;
	 j=ss.size()/2;
	while(i>=0&&j>=0)
	{
		if(ss[i]==ss[j])
		{
			s2+=ss[i];
			j--,i--;
		}
		else
			j--;
		if(s2.size()==ss.size()/2)
		{
			reverse(s2.begin(),s2.end());
			s.insert(s2);
			break;
		}
 
	}
	if(s.size()==1)
		cout<<*s.begin()<<endl;
	else if(s.size()==0)
		cout<<"NOT POSSIBLE"<<endl;
	else
		cout<<"NOT UNIQUE"<<endl;
    return 0;
}