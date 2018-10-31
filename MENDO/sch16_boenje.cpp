#include<iostream>
#include<vector>
using  namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int r1=m/3;
    int y1=m/3;
    int g1=m/3;
    if(m%3==1)
        r1++;
    if(m%3==2)
    {
        r1++;
        y1++;
    }
    int y2=m/3;
    int g2=m/3;
    int r2=m/3;
    if(m%3==1)
        y2++;
    if(m%3==2)
    {
        y2++;
        g2++;
    }
    int g3=m/3;
    int r3=m/3;
    int y3=m/3;
    if(m%3==1)
        g3++;
    if(m%3==2)
    {
        g3++;
        r3++;
    }
    int k=n/3;
    int r=0,y=0,g=0;
    r+=k*r1;
    r+=k*r2;
    r+=k*r3;
    y+=k*y1;
    y+=k*y2;
    y+=k*y3;
    g+=k*g1;
    g+=k*g2;
    g+=k*g3;
    if(n%3==1){
        r+=r1;
        y+=y1;
        g+=g1;
    }
    if(n%3==2)
    {
        r+=r1;
        y+=y1;
        g+=g1;
        r+=r2;
        y+=y2;
        g+=g2;
 
    }
    cout<<r<<" "<<y<<" "<<g<<endl;
    return 0;
}