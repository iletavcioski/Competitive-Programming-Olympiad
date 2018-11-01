#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int k=n;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
k-=(a+1);
if(k<=0){
cout<<i+1<<endl;
return 0;
}
}
return 0;
}