#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >v;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    int mat[3003][3003];
    for(int i=0;i<=3000;i++)
    {
        for(int j=0;j<=3000;j++)
            mat[i][j]=false;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> dp(3003,999999);
    queue<int> qi;
    qi.push(0);
    queue<int> qs;
    qs.push(0);
    queue<int> qp;
    qp.push(-1);
    int mm;
    cin>>mm;
    map<int,vector<pair<int,int> > > map;
    for(int i=0;i<mm;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        map[b].push_back(make_pair(a,c));
    }
    dp[0]=0;
    int maxi=9999999;
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        int topp=qp.front();
        qp.pop();
        int tops=qs.front();
        qs.pop();
        if(topi==n-1)
            maxi=min(maxi,tops);
        for(int i=0;i<v[topi].size();i++)
        {
            bool cc=true;
            for(int j=0;j<map[topi].size();j++)
            {
                if(map[topi][j].first==topp&&map[topi][j].second==v[topi][i])
                {
                    cc=false;
                    break;
                }
            }
            if(cc)
            {
                if(!mat[topi][v[topi][i]])
                {
                     
                    mat[topi][v[topi][i]]=true;
                    qp.push(topi);
                    qi.push(v[topi][i]);
                    qs.push(tops+1);
                }
            }
        }
    }
    if(maxi==9999999)
        cout<<"GRESHKA"<<endl;
    else
    cout<<maxi<<endl;
    return 0;
}