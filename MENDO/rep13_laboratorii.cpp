#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int pat[1<<21];
int patbitmask[1<<21];
bool visi[1<<21];
int n,m;
vector<vector<int> >v;
int novabitmaska(int x,int bitmask1)
{
    int bitmask=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]!=x&&(bitmask1&(1<<v[i][j])))
            {
                bitmask|=(1<<i);
            }
        }
    }
    return bitmask;
}
int main()
{
    cin>>n>>m;
    vector<int> vec;
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(m>=n)
    {
        cout<<-1<<endl;
        return 0;
    }
    queue<int> qs;
    queue<int> qb;
    int bit=(1<<n)-1;
    qb.push(bit);
    qs.push(0);
    while(!qb.empty())
    {
        int topb=qb.front();
        qb.pop();
        int tops=qs.front();
        qs.pop();
        if(topb==0)
        {
            cout<<tops<<endl;
            vector<int> vkraj;
            for(int i=topb;i!=bit;i=patbitmask[i])
            {
                vkraj.push_back(pat[i]);
            }
            reverse(vkraj.begin(),vkraj.end());
            for(int i=0;i<vkraj.size();i++)
            {
                cout<<vkraj[i]+1;
                if(i==vkraj.size()-1)
                    cout<<endl;
                else
                    cout<<" ";
            }
            return 0;
        }
        for(int i=0;i<n;i++)
        {   
            int topbb=novabitmaska(i,topb);
            if(!visi[topbb])
            {
                visi[topbb]=true;
                qs.push(tops+1);
                qb.push(topbb);
                pat[topbb]=i;
                patbitmask[topbb]=topb;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}