#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int maxi=0;
int brojac=0;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
if(a==2)
maxi=max(maxi,brojac),brojac=0;
else
brojac++;
}
maxi=max(maxi,brojac);
cout<<maxi<<endl;
return 0;
}