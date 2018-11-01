#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
int n;
cin>>n;
int zbir=0;
vector<int> v;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
v.push_back(a);
zbir+=a;
}
int brojac=99999;
int mini=-1;
double kk=zbir/n;
for(int i=0;i<n;i++)
{
  if(abs(v[i]-kk)<brojac)
{
brojac=abs(v[i]-kk);
mini=v[i];
}
}
cout<<mini<<endl;
return 0;
}