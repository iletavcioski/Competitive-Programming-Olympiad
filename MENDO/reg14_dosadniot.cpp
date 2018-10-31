#include<iostream>
using namespace std;
int main()
{
int n;
int brojac=0;
cin>>n;
for(int i=0;i<=1000000;i++){
brojac+=i;
if(brojac>=n)
{
cout<<i<<endl;
return 0;
}
}
return 0;
}