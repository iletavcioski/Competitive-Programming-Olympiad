#include<iostream>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
int bb=min(a,b);
if(bb%2==1)
bb--;
cout<<bb*bb<<endl;
return 0;
}