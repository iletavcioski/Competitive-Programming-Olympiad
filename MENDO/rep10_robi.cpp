#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int>x,y;
vector<int> mozi(int a,int b)
{
    vector<int> vec;
    int maxi=999999;
    for(int i=0;i<x.size();i++)
    {
        maxi=min(abs(a-x[i])+abs(b-y[i]),maxi);
    }
    for(int i=0;i<x.size();i++)
    {
        if((abs(a-x[i])+abs(b-y[i]))==maxi)
        {
            vec.push_back(i);
        }
    }
    return vec;
}
int rek(int rx,int cx,int ry,int cy)
{
    vector<int> a,b,c,d;
    if(ry<rx||cy<cx)
        return 0;
    a=mozi(rx,cx);
    b=mozi(rx,cy);
    c=mozi(ry,cx);
    d=mozi(ry,cy);
    if((a==b&&a==c&&a==d)||(rx==ry && cx==cy))
    {
        if(a.size()==1) 
            return 0;
        else
            return ((ry-rx+1)*(cy-cx+1));
    }
    else
    {
        int r=(rx+ry)/2;
        int c=(cx+cy)/2;
        return rek(rx,cx,r,c)+rek(rx,c+1,r,cy)+rek(r+1,cx,ry,c)+rek(r+1,c+1,ry,cy);
    }
}
int main()
{
    int h,v;
    cin>>h>>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        x.push_back(a);
        int b;
        cin>>b;
        y.push_back(b);
    }
    cout<<rek(1,1,h,v)<<endl;
    return 0;
}