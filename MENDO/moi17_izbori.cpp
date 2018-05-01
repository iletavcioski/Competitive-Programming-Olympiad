#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<vector<int> > v;
vector<vector<int> > b;
bool mat[31][31];
bool visi[31];
bool visi1[31];
int boja2;
ll komponenta;
void dfs(int x,vector<int> vv)
{
    if(x==b[boja2].size())
    {
        komponenta++;
        return;
    }
    dfs(x+1,vv);
    int mom=b[boja2][x];
    bool cc=false;
    for(int i=0;i<vv.size();i++)
    {
        if(!mat[mom][vv[i]])
            continue;
        for(int j=i+1;j<vv.size();j++)
        {
            if(mat[mom][vv[i]]&&mat[vv[i]][vv[j]]&&mat[vv[j]][mom]){
                cc=true;
            break;}
        }
    }
    if(!cc)
    {
        vv.push_back(mom);
        dfs(x+1,vv);
    }
}
void flood(int x,int boja)
{
    visi1[x]=boja;
    b[boja].push_back(x);
    for(int i=0;i<v[x].size();i++)
    {
        if(visi[v[x][i]]&&!visi1[v[x][i]])
            flood(v[x][i],boja);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        mat[a][b]=true;
        mat[b][a]=true;
    }
    vector<int> vec;
    b.insert(b.begin(),n+1,vec);
    v.insert(v.begin(),n+1,vec);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j])
                v[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(mat[i][j]&&mat[j][k]&&mat[k][i])
                    visi[i]=visi[j]=visi[k]=true;
            }
        }
    }
    int broj=0;
    for(int i=0;i<n;i++)
    {
        if(!visi[i])
        {
            broj++;
        }
    }
    ll brojac=(ll)((ll)1<<(ll)(broj));
    int br=1;
 
    for(int i=0;i<n;i++)
    {
        if(visi1[i])
            continue;
        if(!visi[i])
            continue;
        flood(i,br);
        br++;
    }
    for(int i=1;i<br;i++)
    {
        vector<int> vvv;
        boja2=i;
        komponenta=0;
        dfs(0,vvv);
        brojac*=komponenta;
    }
    cout<<brojac<<endl;
    return 0;
}