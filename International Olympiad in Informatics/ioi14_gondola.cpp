#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000009;
ll stepen(ll x,ll y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    ll broj=stepen(x,y/2);
    ll brojac=broj*broj;
    brojac%=mod;
    if(y%2)
        brojac*=x;
    brojac%=mod;
    return brojac;
}
bool valid(int n, vector<int> seq)
{
    vector<int> v=seq;
    map<int,int> m;
    v.push_back(v[0]);
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
        if(m[v[i]]==2)
            return false;
        if(v[i]<n&&(v[i+1]!=v[i]+1&&v[i+1]<=n))
            return false;
        if(v[i]==n&&(v[i+1]!=1&&v[i+1]<=n))
            return false;
    }
    
    return true;
}
vector<int> replacement(int n, vector<int> seq)
{
    
    if(!valid(n,seq))
    {
        vector<int> v;
        cout<<"d"<<endl;
        return v;
    }
    
    vector<int> poc;
    for(int i=0;i<n;i++)
        poc.push_back(i+1);
    vector<pair<int,int> > vk;
    for(int i=0;i<n;i++)
    {
        if(seq[i]<=n)
        {
            poc[i]=seq[i];
            int j=i+1;
            int b=seq[i];
            while(1)
            {
                b++;
                if(b==n+1)
                    b=1;
                if(j==n)
                    j=0;
                if(j==i)
                    break;
                poc[j]=b;
                j++;
            }
            break;
        }
    }
   
    int br=n+1;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(seq[i]>n)
        {
            vk.push_back(make_pair(seq[i],poc[i]));
        }
    }
    sort(vk.begin(),vk.end());
    for(int i=0;i<vk.size();i++)
    {
        
        //cout<<kk.x<<" "<<kk.val<<endl;
        v.push_back(vk[i].second);
        for(int ii=br;ii<vk[i].first;ii++)
            v.push_back(ii);
        br=vk[i].first+1;
        
    }
    return v;
}
ll count(int n, vector<int> seq)
{
    if(!valid(n,seq))
        return 0;
    ll brojac=1;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(seq[i]>n)
            v.push_back(seq[i]);
    }
    if(v.size()==0)
        return 1;
    if(v.size()==n)
        brojac=(ll)n;
    sort(v.begin(),v.end());
    int pret=n;
    int br=v.size();
    for(int i=0;i<v.size();i++)
    {
        brojac*=stepen((ll)br,(ll)(v[i]-pret-1));
        brojac%=mod;
        br--;
        pret=v[i];
    }
    return brojac;
}
int main()
{
    int t;
    cin>>t;
    int n;
    cin>>n;
    vector<int> k;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        k.push_back(a);
    }
    if(t>=1&&t<=3)
    {
        cout<<valid(n,k)<<endl;
    }
    else if(t>=4&t<=6)
    {
        vector<int> v;
        v=replacement(n,k);
        cout<<v.size();
        for(int i=0;i<v.size();i++)
            cout<<" "<<v[i];
        cout<<endl;
    }
    else
    {
        cout<<count(n,k)<<endl;
    }
    return 0;
}