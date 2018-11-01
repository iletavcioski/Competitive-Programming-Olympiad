#include<iostream>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
cout<<max((c-b-1),(b-a-1))<<endl;
return 0;
}