#include<iostream>
#include<vector>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
vector<int> v(10,0);
for(int i=n;i<=k;i++)
{
     int p=i;
while(p>0)
{
v[p%10]++;
p/=10;
}
}
cout<<v[0];
for(int i=1;i<=9;i++)
cout<<" "<<v[i];
cout<<endl;
return 0;
}