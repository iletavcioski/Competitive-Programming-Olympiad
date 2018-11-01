#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int maxi=0;
int mini=99999;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
string znak;
cin>>znak;
if(znak=="DA")
{
mini=min(mini,a);
}
else
maxi=max(maxi,a);
}
cout<<maxi+1<<" "<<mini-1<<endl;
return 0;
}