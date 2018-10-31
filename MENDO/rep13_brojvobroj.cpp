#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    string s1="";
    if(k==0)
        s1="0";
    while(k)
    {
        s1+=((k%10)+'0');
        k/=10;
    }
    reverse(s1.begin(),s1.end());
    int brojac=0;
 
    for(int i=n;i<=m;i++)
    {
        int p=i;
        string ss="";
        while(p)
        {
        ss+=((p%10)+'0');
        p/=10;
        }
        reverse(ss.begin(),ss.end());
        if(ss.find(s1)!=-1)
            brojac++;
    }
    cout<<brojac<<endl;
    return 0;
}