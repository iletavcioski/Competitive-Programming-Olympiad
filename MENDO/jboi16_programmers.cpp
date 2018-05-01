#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    int n,m; 
    cin>>n;
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),n+5,vec);
    queue<int> qi;
    int boja[50005];
    memset(boja,0,sizeof(boja));
    int na_pocetok=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            na_pocetok++;
            qi.push(i);
            boja[i]=1;
        }
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
  
    for(int i=1;i<=n;i++)
    {
        if (v[i].size()==0) 
            boja[i]=0;
    }
  
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop(); 
        if(boja[topi]==1)
        {
            for(int i=0;i<v[topi].size();i++)
            {
                if(boja[v[topi][i]]==0)
                {
                    boja[v[topi][i]]=2;
                    qi.push(v[topi][i]);
                }
                if(boja[v[topi][i]]==1)
                {
                    boja[v[topi][i]]=3;
                    qi.push(v[topi][i]);
                }
            }
        }
        if(boja[topi]==2)
        {
            for(int i=0;i<v[topi].size();i++)
            {
                if(boja[v[topi][i]]==0)
                {
                    boja[v[topi][i]]=1;
                    qi.push(v[topi][i]);
                }
                if(boja[v[topi][i]]==2)
                {
                    boja[v[topi][i]]=3;
                    qi.push(v[topi][i]);
                }
            }
        }
        if(boja[topi]==3)
        {
            for(int i=0;i<v[topi].size();i++)
            {
                if(boja[v[topi][i]]!=3)
                {
                    boja[v[topi][i]]=3;
                    qi.push(v[topi][i]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(boja[i]==3)
            qi.push(i);
    }
    bool visited[50005];
    memset(visited,0,sizeof(visited));
    while(!qi.empty())
    {
        int topi=qi.front();
        qi.pop();
        visited[topi]=true;
        for(int i=0;i<v[topi].size();i++)
        {
            if(!visited[v[topi][i]])
            {
                qi.push(v[topi][i]);
                boja[v[topi][i]]=3;
                visited[v[topi][i]]=true;
            }
        }
    }
    int edinici=0,dvojki=0,trojki=0;
    for (int i=1;i<=n;i++)
    {
        if(boja[i]==1) 
            edinici++;
        if(boja[i]==2) 
            dvojki++;
        if(boja[i]==3) 
            trojki++;
    }
    cout<<max(trojki+max(edinici,dvojki),na_pocetok)<<endl;
    return 0;
}