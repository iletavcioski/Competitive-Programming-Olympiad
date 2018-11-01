#include<iostream>
using namespace std;
int main()
{
int px,py,a,b,tx,ty;
cin>>px>>py>>a>>b>>tx>>ty;
if(tx>px&&ty>py&&tx<(px+a)&&ty<(py+b))
cout<<"vnatre"<<endl;
else if((tx==px||ty==py||tx==(px+a)||ty==(py+b))&&(tx>=px&&ty>=py&&tx<=(px+a)&&ty<=(py+b)))
cout<<"strana"<<endl;
else
cout<<"nadvor"<<endl;
return 0;
}