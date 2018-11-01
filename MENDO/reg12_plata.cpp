#include<iostream>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
if(c-b==b-a)
cout<<c+(b-a)<<endl;
else
cout<<c*(b/a)<<endl;
 
return 0;
}