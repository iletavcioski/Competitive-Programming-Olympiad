#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int k;
cin>>k;
int brojac=0;
for(int i=n;i<=k;i++)
if((i/1000)<((i/100)%10)&&((i/100)%10)<((i/10)%10)&&((i/10)%10)<(i%10))
brojac++;
cout<<brojac<<endl;
return 0;
}