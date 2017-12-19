#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    vector<pair<int,ll> > v1,v2;
    vector<vector<ll> > d;
    vector<ll> vec;
    d.insert(d.begin(),41,vec);
    vector<int> s;
    map<int,int> m;
    ll brojac=0;
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<pair<int,ll> > v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        ll c=(ll)b*1LL;
        v.push_back(make_pair(a,(ll)c));
        
    }
    int a1=n/2;
    int a2=n-a1;
    for(int i=1;i<(1<<a2);i++)
    {
        int mini=-1;
        int poc=1e9+1;
        ll broj1=0;
        int bb=-1;
        bool cc=true;
        for(int j=0;j<a2;j++)
        {
            if(i&(1<<j))
            {
                if(bb==-1)
                    bb=j+a1;
                int z=j+a1;
                if(v[z].first>=mini)
                {
                    mini=v[z].first;
                    poc=min(poc,mini);
                    broj1+=v[z].second;
                }
                else
                {
                    cc=false;
                    break;
                }
            }
        }
        if(cc)
        {
            d[bb].push_back(broj1);
            if(broj1>=k)
                brojac+=((ll)1);
        }
    }
    for(int i=0;i<n;i++)
        sort(d[i].begin(),d[i].end());
    for(int i=1;i<(1<<a1);i++)
    {
        int mini=-1;
        int poc=1e9+1;
        ll broj1=0;
        bool cc=true;
        for(int j=0;j<a1;j++)
        {
            if(i&(1<<j))
            {
                if(v[j].first>=mini)
                {
                    mini=v[j].first;
                    poc=min(poc,mini);
                    broj1+=v[j].second;
                }
                else
                {
                    cc=false;
                    break;
                }
            }
        }
        if(cc)
        {
            if(broj1>=k)
                brojac+=((ll)1);
            for(int j=0;j<n;j++)
            {
                if(mini<=v[j].first)
                {
                    ll gg=k-broj1;
                    int aa=d[j].end()-lower_bound(d[j].begin(),d[j].end(),gg);
                    ll kk=(ll)aa*1LL;
                    brojac+=kk;
                }
            
            }
        }
    }
    cout<<brojac<<endl;
    return 0;
}