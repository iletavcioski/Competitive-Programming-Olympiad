#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
map<string,int> m;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
string ss;
cin>>ss;
m[ss]++;
}
int brojac=0;
string kraj;
for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
{
if(it->second>brojac){
brojac=it->second;
kraj=it->first;
}
}
cout<<kraj<<endl;
return 0;
}