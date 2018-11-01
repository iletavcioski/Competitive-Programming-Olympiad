#include<iostream>
using namespace std;
int main()
{
    int br1=0;
    int br2=0;
    int b1=0;
    int b2=0;
    for(int i=0;i<3;i++)
    {
        int a,b;
        cin>>a>>b;
        b1=max(b1,a);
        b2=max(b2,b);
        int a1=a;
        int a2=b;
        int bb=0;
        while(a>0)
        {
            bb+=a%10;
            a/=10;
        }
        if(a1%bb==0)
            br1+=2,br2--;
        bb=0;
        while(b>0)
        {
            bb+=b%10;
            b/=10;
        }
        if(a2%bb==0)
            br2+=2,br1--;
         
    }
    if(br1>br2)
    {
        cout<<br1<<" "<<br2<<endl;
        cout<<"Stefan"<<endl;
    }
    else if(br1<br2)
    {
        cout<<br1<<" "<<br2<<endl;
        cout<<"Ana"<<endl;
    }
    else if(br1==br2)
    {
        cout<<br1<<" "<<br2<<endl;
        if(b1>b2)
            cout<<"Stefan"<<endl;
        else
            cout<<"Ana"<<endl;
    }
    return 0;
}