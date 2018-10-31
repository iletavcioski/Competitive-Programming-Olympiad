#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
if(m>n){
cout<<"NE MOZE"<<endl;
return 0;
}
int a=(n-m)/2+m;
int b=(n-m)/2;
if(a+b==n&&a-b==m)
cout<<a<<" "<<b<<endl;
else
cout<<"NE MOZE"<<endl;
return 0;
}