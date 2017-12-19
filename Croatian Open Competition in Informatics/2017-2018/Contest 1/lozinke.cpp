#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const ll mod=10000000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<string> v;
    map<ll,int> m;
    ll b=31;
    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        v.push_back(ss);
        ll hash=0;
        for(int j=0;j<ss.size();j++)
        {
            ll d=ss[j]-'a'+1;
            hash=hash*b+d;
            hash%=mod;
        }
        m[hash]++;
    }
    ll brojac=0;
    for(int i=0;i<n;i++)
    {
        map<ll,bool> vi;
        for(int j=0;j<v[i].size();j++)
        {
            ll ha=0;
            for(int k=j;k<v[i].size();k++)
            {
                ll d=v[i][k]-'a'+1;
                ha=ha*b+d;
                ha%=mod;
                if(!vi[ha])
                {
                    vi[ha]=true;
                    brojac+=m[ha];
                }
            }
        }
        brojac--;
    }
    cout<<brojac<<endl;
    return 0;
}