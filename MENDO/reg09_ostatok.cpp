#include<iostream>
#include<set>
using namespace std;
int main()
{
set<int> ss;
for(int i=0;i<10;i++)
{
int a;
cin>>a;
ss.insert(a%42);
}
cout<<ss.size()<<endl;
return 0;
}