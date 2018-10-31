#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector<int> v(6,0);
for(int i=0;i<4;i++)
{
int a;
cin>>a;
v[a]++;
}
cout<<4-max(v[0],v[5])<<endl;
return 0;
}