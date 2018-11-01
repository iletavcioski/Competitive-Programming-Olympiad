#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
int n;
cin>>n;
int brojac=0;
for(int i=0;i<n;i++)
{
string s1,s2;
cin>>s1>>s2;
sort(s1.begin(),s1.end());
sort(s2.begin(),s2.end());
if(s1==s2)
brojac++;
}
cout<<brojac<<endl;
return 0;
}