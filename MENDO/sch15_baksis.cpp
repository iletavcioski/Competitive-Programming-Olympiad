#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int makscena=floor(10.0*n/9.0);
    int mincena=ceil(20.0*n/19.0);
    if(makscena>k)
        makscena=k;
 
    if(mincena%5!=0)
        mincena+=5-(mincena%5);
 
    if(makscena%5!=0)
        makscena-=(makscena%5);
 
        if(mincena>makscena)
            cout<<0<<endl;
        else
            cout<<(makscena-mincena)/5+1<<endl;
    return 0;
}