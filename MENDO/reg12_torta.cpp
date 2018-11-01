#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    int broj=1;
    while(1)
    {   
        if(n>i)
            n-=i;
        else
            break;
        broj++;
        if(broj<10)
            i++;
        else if(broj>=10&&broj<=99)
        i+=2;
        else if(broj>=100&&broj<=999)
        i+=3;
        else if(broj>=1000&&broj<=9999)
        i+=4;
        else if(broj>=10000&&broj<=99999)
        i+=5;
        else if(broj>=100000&&broj<=999999)
        i+=6;
        else if(broj>=1000000&&broj<=9999999)
        i+=7;
    }
    string ss="";
     broj=1;
    while((int)ss.size()<=n)
    {
    string sk="";
    int p=broj;
    while(p>0)
    {
        sk+=p%10+'0';
        p/=10;
    }
    reverse(sk.begin(),sk.end());
    broj++;
        ss+=sk;
    }
    cout<<ss[n-1]<<endl;
    return 0;
}