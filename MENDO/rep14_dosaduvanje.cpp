#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> v;
    vector<vector<ll> > vk;
    vk.insert(vk.begin(),31,v);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int b=n/2;
    if(n%2)
        b++;
    ll res=0;
    for(int i=0;i<(1<<b);i++)
    {
        int broj=0;
        ll brojac=0;
        ll maxi=0;
        for(int j=0;j<b;j++)
        {
            if(i&(1<<j))
            {
                maxi=max(maxi,v[j]);
                broj++;
                brojac+=v[j];
            }
        }
        if(broj==m&&(brojac-maxi)>maxi)
            res++;
        vk[broj].push_back(brojac);
    }
    for(int i=0;i<m;i++)
    {
        sort(vk[i].begin(),vk[i].end());
    }
    int b1=n/2;
    for(int i=1;i<(1<<b1);i++)
    {
        int broj=0;
        ll brojac=0;
        ll maxi=0;
        for(int j=0;j<b1;j++)
        {
            if((i&(1<<j))&&b+j<n){
            broj++;
            brojac+=v[b+j];
            maxi=max(maxi,v[b+j]);
            }
        }
        brojac-=maxi;
        ll bb=maxi-brojac;
        if(m-broj>=0&&vk[m-broj].size())
        res+=vk[m-broj].end()-upper_bound(vk[m-broj].begin(),vk[m-broj].end(),bb);
    }
    cout<<res<<endl;
    return 0;
}