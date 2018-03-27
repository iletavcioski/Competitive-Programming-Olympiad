#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll ft[200010];
ll ft2[200002];
void update(int x,ll val)
{
    int i=x;
    if(i==0)
        return;
    while(i<=200000)
    {
        ft[i]+=val;
        i+=(i&-i);
    }
}
ll query(int x)
{
    int i=x;
    ll broj=0;
    while(i>0)
    {
        broj+=ft[i];
        i-=(i&-i);
    }
    return broj;
}
void update1(int x,ll val)
{
    int i=x;
    if(i==0)
        return;
    while(i<=200000)
    {
        ft2[i]+=val;
        i+=(i&-i);
    }
}
ll query1(int x)
{
    int i=x;
    ll broj=0;
    while(i>0)
    {
        broj+=ft2[i];
        i-=(i&-i);
    }
    return broj;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int Q;
    cin>>Q;
    unordered_map<int,int> m;
    vector<int> v;
    vector<int> vk;
    for(int i=0;i<Q;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        vk.push_back(a);
    }
    vector<ll> vec(200002,-1);
    sort(v.begin(),v.end());
    int j=1;
    for(int i=0;i<v.size();i++)
    {
        if(!i)
            m[v[i]]=j,j++;
        else if(v[i]!=v[i-1])
            m[v[i]]=j,j++;
    }
    for(int i=0;i<Q;i++)
        vk[i]=(m[vk[i]]);
    ll brojac=0;
    for(int i=Q-1;i>=0;i--)
    {
        update1(vk[i],query(vk[i]-1));
        update(vk[i],1);
        brojac+=query1(vk[i]-1);
    }
    cout<<brojac<<endl;
    return 0;
}