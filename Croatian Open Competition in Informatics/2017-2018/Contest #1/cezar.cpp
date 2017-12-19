#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v(12,0);
    for(int i=2;i<=11;i++)
    {
        int b=4;
        if(i==10)
            b=16;
        v[i]=b;
    }
    int n;
    cin>>n;
    int bro=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v[a]--;
        bro+=a;
    }
    int c=21-bro;
    c=max(c,0);
    int k1=0,k2=0;
    for(int i=2;i<=11;i++)
    {
        if(i<=c)
            k1+=v[i];
        else if(i>c)
            k2+=v[i];
    }
    if(k1>k2)
    {
        cout<<"VUCI"<<endl;
    }
    else
        cout<<"DOSTA"<<endl;
    return 0;
}