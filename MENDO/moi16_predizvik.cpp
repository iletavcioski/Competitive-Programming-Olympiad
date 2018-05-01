#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
int euclid(ll a,ll b)
{
    if(!b)
        return a;
    a%=b;
    return euclid(b,a);
}
bool proveri(ll a,ll b)
{
    ll x=sqrt(a*a+b*b);
    if(x*x==a*a+b*b)
    {
        if(euclid(a,b)==1)
            return true;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<ll,int> > v1,v2;
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),300,vec);
    int mat[202][202];
    memset(mat,0,sizeof(mat));
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(a%2)
            v1.push_back(make_pair(a,i+1));
        else
            v2.push_back(make_pair(a,i+1));
    }
 
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(proveri(v1[i].first,v2[j].first))
            {
                mat[v1[i].second][v2[j].second]+=100000;
                v[v1[i].second].push_back(v2[j].second);
                v[v2[j].second].push_back(v1[i].second);
            }
        }
    }
    int s=0;
    int t=200;
    for(int i=0;i<v1.size();i++)
    {
        mat[s][v1[i].second]++;
        v[s].push_back(v1[i].second);
        v[v1[i].second].push_back(s);
    }
    for(int i=0;i<v2.size();i++)
    {
        mat[v2[i].second][t]++;
        v[v2[i].second].push_back(t);
        v[t].push_back(v2[i].second);
    }
    int brojac=0;
    while(1)
    {
        queue<int> qi;
        qi.push(s);
        queue<int> qm;
        qm.push(99999);
        vector<int> par(300,-1);
        int flow;
        while(!qi.empty())
        {
            int topi=qi.front();
            qi.pop();
            int topm=qm.front();
            qm.pop();
            if(topi==t)
            {
                flow=topm;
                break;
            }
            for(int i=0;i<v[topi].size();i++)
            {
                if(mat[topi][v[topi][i]]!=0&&par[v[topi][i]]==-1)
                {
                    qi.push(v[topi][i]);
                    qm.push(min(topm,mat[topi][v[topi][i]]));
                    par[v[topi][i]]=topi;
                }
            }
        }
        if(par[t]==-1)
            break;
        int y=t;
        brojac+=flow;
        while(y!=s)
        {
            mat[par[y]][y]-=flow;
            mat[y][par[y]]+=flow;
            y=par[y];
        }
    }
    cout<<brojac*2<<endl;
    return 0;
}