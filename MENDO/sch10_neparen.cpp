#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int m;
cin>>m;
int brojac=0;
for(int i=n;i<=m;i++)
if(i%2==1)
brojac+=i;
cout<<brojac<<endl;
return 0;
}