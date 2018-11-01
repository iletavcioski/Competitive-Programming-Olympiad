#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
if(n==2)
{
   if(m%400==0||(m%4==0&&m%100!=0))
    cout<<29<<endl;
else
cout<<28<<endl;
}
else if(n==4||n==6||n==9||n==11)
cout<<30<<endl;
else
cout<<31<<endl;
return 0;
}