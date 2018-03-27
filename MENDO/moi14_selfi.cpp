#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int cifri[]={0,1,2,5,8};
vector<int> v1,v2,vec;
bool compare(vector<int> &v)
{
    
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]>v[i])
            return false;
        else if(v1[i]<v[i])
            break;
    }
    for(int i=0;i<v2.size();i++)
    {
        if(v2[i]>v[i])
            break;
        else if(v2[i]<v[i])
            return false;
    }
    return true;
}
int prevrti(vector<int> v)
{
    int brojac=0;
    if(v1.size()%2==1)
    {
        int broj=1;
        v.push_back(0);
        for(int i=v.size()-2;i>=0;i--)
        {
            broj++;
            if(v[i]==5)
                v.push_back(2);
            else if(v[i]==2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if(compare(v))
            brojac++;
        while(broj--)
            v.pop_back();
        broj=1;
        v.push_back(1);
        for(int i=v.size()-2;i>=0;i--)
        {
            broj++;
            if(v[i]==5)
                v.push_back(2);
            else if(v[i]==2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if(compare(v))
            brojac++;
        while(broj--)
            v.pop_back();
        broj=1;
        v.push_back(8);
        for(int i=v.size()-2;i>=0;i--)
        {
            broj++;
            if(v[i]==5)
                v.push_back(2);
            else if(v[i]==2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if(compare(v))
            brojac++;
        return brojac;
    }
    else
    {
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i]==5)
                v.push_back(2);
            else if(v[i]==2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if(compare(v))
            return true;
        else
            return false;
    }
}
int rek(int x)
{
    int brojac=0;
    if(x==0)
    {
        brojac+=prevrti(vec);
    }
    else
    {
        int pocetok;
        if(vec.empty())
            pocetok=1;
        else
            pocetok=0;
        for(;pocetok<5;pocetok++)
        {
            vec.push_back(cifri[pocetok]);
            brojac+=rek(x-1);
            vec.pop_back();
        }
    }
    return brojac;
}
int brojcifri(ll x)
{
    if(x==0)
        return 1;
    int brojac=0;
    while(x>0)
    {
        brojac++;
        x/=10;
    }
    return brojac;
}
int main()
{
    ll a,b;
    ll dp[19];
    ll brojac=0;
    cin>>a>>b;
    dp[2]=4;
    for(int i=3;i<19;i++)
        if(i%2==0)
            dp[i]=dp[i-2]*5;
        else
            dp[i]=dp[i-1]*3;
    
    int cifria,cifrib;
    cifria=brojcifri(a);
    cifrib=brojcifri(b);
    for(int i=cifria+1;i<cifrib;i++)
        brojac+=dp[i];
    if(cifria!=cifrib)
    {
        while(cifria--)
        {
            v1.push_back(a%10);
            v2.push_back(9);
            a/=10;
        }
        reverse(v1.begin(),v1.end());
        brojac+=rek(v1.size()/2);
        v1.clear();
        v2.clear();
        v1.push_back(1);
        while(cifrib--)
        {
            v1.push_back(0);
            v2.push_back(b%10);
            b/=10;
        }
        v1.pop_back();
        reverse(v2.begin(),v2.end());
        brojac+=rek(v2.size()/2);
    }
    else
    {
        while(cifria--)
        {
            v1.push_back(a%10);
            v2.push_back(b%10);
            a/=10;
            b/=10;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        brojac+=rek(cifrib/2);
    }
    cout<<brojac<<endl;
    return 0;
}