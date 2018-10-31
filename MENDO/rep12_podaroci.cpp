#include<iostream>
#include<vector>
using namespace std;
int main()
{
int n;
cin>>n;
vector<int> v;
int zbir=0;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
v.push_back(a);
zbir+=a;
}
if(zbir%n!=0){
cout<<"GRESHKA"<<endl;
return 0;
}
int k=zbir/n;
int brojac=0;
for(int i=0;i<n;i++)
{
     brojac+=max(v[i]-k,0);
}
cout<<brojac<<endl;
return 0;
}