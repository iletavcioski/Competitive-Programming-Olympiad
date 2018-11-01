#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
string ss;
cin>>ss;
int k;
cin>>k;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
string s1;
cin>>s1;
if(ss==s1)
{
cout<<fixed<<setprecision(5);
cout<<k+(k*0.05)<<endl;
return 0;
}
}
cout<<fixed<<setprecision(5);
cout<<k+(k*0.18)<<endl;
return 0;
return 0;
}