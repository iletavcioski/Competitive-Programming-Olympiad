#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
int maxi=0;
int maxx;
for(int i=n;i<=m;i++)
{
    int brojac=0;
for(int j=1;j<=i;j++)
{
if(i%j==0)
brojac++;
}
if(brojac>maxi)
{
maxi=brojac;
maxx=i;
}
}
cout<<maxx<<" "<<maxi<<endl;
return 0;
}