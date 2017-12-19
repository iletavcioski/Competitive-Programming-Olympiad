#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char mat[11][11];
bool vis[11][11];
vector<pair<int,int> > v;
int n,m;
void dfs(int x,int y)
{
    if(vis[x][y])
        return;
    vis[x][y]=true;
    v.push_back(make_pair(x,y));
    if(x+1<n&&mat[x][y]==mat[x+1][y])
        dfs(x+1,y);
    if(x-1>=0&&mat[x][y]==mat[x-1][y])
        dfs(x-1,y);
    if(y+1<m&&mat[x][y]==mat[x][y+1])
        dfs(x,y+1);
    if(y-1>=0&&mat[x][y]==mat[x][y-1])
        dfs(x,y-1);
}
bool mozi1(vector<pair<int,int> > v1)
{
    sort(v1.begin(),v1.end());
    if(v1[0].first==v1[1].first&&v1[2].first==v1[3].first&&v1[0].first+1==v1[2].first)
    {
        if(v1[0].second==v1[2].second&&v1[1].second==v1[3].second)
        {
            return true;
        }
    }
    return false;
}
bool mozi2(vector<pair<int,int> > v1)
{
    sort(v1.begin(),v1.end());
    if(v1[0].first==v1[1].first&&v1[1].first==v1[2].first&&v1[2].first==v1[3].first)
        return true;
    if(v1[0].second==v1[1].second&&v1[1].second==v1[2].second&&v1[2].second==v1[3].second)
        return true;
    return false;
}
bool mozi5(vector<pair<int,int> > v1)
{
    sort(v1.begin(),v1.end());
    if(v1[1].first==v1[2].first&&v1[2].first==v1[3].first)
        return true;
    if(v1[0].first==v1[1].first&&v1[1].first==v1[2].first)
        return true;
    if(v1[0].second==v1[2].second&&v1[2].second==v1[3].second)
        return true;
    if(v1[0].second==v1[1].second&&v1[1].second==v1[3].second)
        return true;
    return false;
}
bool mozi3(vector<pair<int,int> > v1)
{
    sort(v1.begin(),v1.end());
    if(v1[0].first==v1[1].first&&v1[0].second+1==v1[1].second)
    {
        if(v1[0].first+1==v1[3].first&&v1[0].second==v1[3].second)
        {
            if(v1[2].first==v1[3].first&&v1[2].second+1==v1[3].second)
                return true;
        }
    }
    if(v1[0].first+1==v1[1].first&&v1[0].second==v1[1].second)
    {
        if(v1[1].first==v1[2].first&&v1[1].second+1==v1[2].second)
        {
            if(v1[2].first+1==v1[3].first&&v1[2].second==v1[3].second)
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> kraj(6,0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&mat[i][j]!='.')
            {
                v.clear();
                dfs(i,j);
                if(mozi1(v))
                    kraj[1]++;
                else if(mozi2(v))
                    kraj[2]++;
                else if(mozi3(v))
                    kraj[3]++;
                else if(mozi5(v))
                    kraj[5]++;
                else
                    kraj[4]++;
            }
        }
    }
    for(int i=1;i<=5;i++)
        cout<<kraj[i]<<endl;
    return 0;
}