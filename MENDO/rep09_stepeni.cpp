#include<iostream>
#include<string>
using namespace std;
int main()
{
int n;
cin>>n;
int i=0;
string ss="";
 
while(1)
{
   ss+='1';
for(int j=0;j<i;j++)
ss+='0';
i++;
if(ss.size()>n+2)
break;
}
cout<<ss[n-1]<<" "<<ss[n]<<endl;
return 0;
}