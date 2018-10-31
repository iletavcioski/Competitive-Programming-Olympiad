#include<iostream>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int zbir=a+b+c;
int brojac=0;
while(1)
{
if(zbir%3==0)
{
cout<<brojac<<endl;
return 0;
}
brojac++;
zbir++;
}
return 0;
}