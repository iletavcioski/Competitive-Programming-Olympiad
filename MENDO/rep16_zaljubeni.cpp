#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n,u,d,l;
    cin>>m>>n>>u>>d>>l;
    int min1=9999999,min2=999999;
    for(int i=0;i<l;i++)
    {
        int a;
        cin>>a;
        if(m>=a)
        min1=min(min1,(m-a)*d);
        else
            min1=min(min1,(a-m)*u);
        if(n>=a)
        min2=min(min2,(n-a)*u);
        else
            min2=min(min2,(a-n)*d);
    }
    int kk;
    if(m>=n)
        kk=(m-n)*d;
    else
        kk=(n-m)*u;
    cout<<min((min1+min2),kk)<<endl;
    return 0;
}