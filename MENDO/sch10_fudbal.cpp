#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int maxi=0;
for(int i=0;i<n;i++)
{
int a,b,c;
cin>>a>>b>>c;
maxi=max(maxi,3*a+b);
}
cout<<maxi<<endl;
return 0;
}