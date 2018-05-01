#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
bool dp[21][1<<20];
int mat[21][21];
int v[21][21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n,m;
    cin>>n>>m;
    int N=n*m;
    int br=1;
    vector<int> vi(21,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            v[i][j]=br;
            br++;
        }
    }
    vector<vector<int> > v1,v2;
    vector<int> vec;
    v1.insert(v1.begin(),N+1,vec);
    v2.insert(v2.begin(),N+1,vec);
    int kraj=N;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]==1)
            {
                dp[v[i][j]][1<<(v[i][j]-1)]=true;
            }
            else
                {
                    vi[v[i][j]]=0;
                    kraj--;
                }
 
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mat[i][j]==1)
            {
                for(int k=i+1;k<=n;k++)
                {
                    if(mat[k][j])
                    v1[v[i][j]].push_back(v[k][j]);
                }
                for(int k=j+1;k<=m;k++)
                {
                    if(mat[i][k])
                    v2[v[i][j]].push_back(v[i][k]);
                }
                for(int k=i-1;k>=1;k--)
                {
                    if(mat[k][j])
                    v1[v[i][j]].push_back(v[k][j]);
                }
                for(int k=j-1;k>=1;k--)
                {
                    if(mat[i][k])
                    v2[v[i][j]].push_back(v[i][k]);
                }
            }
        }
    }
    
    for(int i=1;i<(1<<N);i++)
    {
        int bro=0;
        for(int j=0;j<N;j++)
        {
            if(i&(1<<j))
                bro++;
        }
        for(int j=1;j<=N;j++)
        {
            if(!vi[j])
                continue;
            if(dp[j][i])
            {
                if(kraj==bro)
                {
                    cout<<"DA"<<endl;
                    return 0;
                }
                if(bro%2)
                {
                    for(int ii=0;ii<v2[j].size();ii++)
                    {
                        int a=v2[j][ii]-1;
                        if(!(i&1<<a))
                        {
                            dp[v2[j][ii]][(i|(1<<a))]=true;
                        }
                    }
                }
                else
                {
                    for(int ii=0;ii<v1[j].size();ii++)
                    {
                        int a=v1[j][ii]-1;
                        if(!(i&1<<a))
                        {
                            dp[v1[j][ii]][(i|(1<<a))]=true;
                        }
                    }
                }
            }
        }
    }
    cout<<"NE"<<endl;
    return 0;
}