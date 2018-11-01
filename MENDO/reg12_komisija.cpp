#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
int n;
cin>>n;
int k;
cin>>k;
vector<int> v;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
v.push_back(a);
}
sort(v.begin(),v.end());
cout<<v[n-k]-v[n-k-1]<<endl;
return 0;
}