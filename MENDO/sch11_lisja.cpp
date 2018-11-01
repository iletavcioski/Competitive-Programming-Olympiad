#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<pair<int,int> > v;
for(int i=0;i<30;i++)
{
int a,b;
cin>>a>>b;
v.push_back(make_pair(b,a));
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
cout<<v[0].second<<" noemvri"<<endl;
}