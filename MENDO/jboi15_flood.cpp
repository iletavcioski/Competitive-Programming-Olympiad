#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll mat[22][22];
int matt[22][22];
char ma[22][22];
ll brojac;
vector<int> v1,v2;
int vv[303][11];
int bb;
int n,m,k;
int ccc;
int izvori;
void dfs(int x,int y)
{
    if(mat[x][y]==brojac)
        return;
    else
        mat[x][y]=brojac;
    bb++;
    if(x+1<m&&matt[x+1][y]<=matt[x][y])
    {
          
        dfs(x+1,y);
    }
    if(x-1>=0&&matt[x-1][y]<=matt[x][y])
    {
        
        dfs(x-1,y);
    }
    if(y+1<m&&matt[x][y+1]<=matt[x][y])
    {
         
        dfs(x,y+1);
    }
    if(y-1>=0&&matt[x][y-1]<=matt[x][y])
    {
        
        dfs(x,y-1);
    }
}
pair<int,int> bi(int bitmask)
{
    bb=0;
    int bbb=0;
    for(int i=0;i<10;i++)
    {
        if((bitmask&(1<<i)))
        {
            bbb++;
            dfs(v1[i],v2[i]);
        }
    }
    int c=m*m;
    int kk=(m*m)-ccc;
    return make_pair(ccc-bb+kk,(izvori-bbb));
}
int main()
{
    for(int i=0;i<303;i++)
    {
        for(int j=0;j<11;j++)
            vv[i][j]=0;
    }
    for(int i=0;i<22;i++)
    {
        for(int j=0;j<22;j++)
            mat[i][j]=0;
    }
    cin>>n>>k>>m;
    for(int i=0;i<n;i++)
    {
          izvori=0;
        for(int ii=0;ii<m;ii++)
        {
            for(int jj=0;jj<m;jj++)
            {
                cin>>ma[ii][jj];
                if(ma[ii][jj]=='L')
                {
                    matt[ii][jj]=99;
                    v1.push_back(ii);
                    v2.push_back(jj);
                    izvori++;
                }
                else
                    matt[ii][jj]=ma[ii][jj]-'0';
            }
        }
        bb=0;
        brojac++;
        for(int j=0;j<v1.size();j++)
        {
            dfs(v1[j],v2[j]);
        }
   
        int ccc=bb;
           
        int c=v1.size();
        for(int j=0;j<(1<<c);j++)
        {
            brojac++;
            pair<int,int> mm=bi(j);
            vv[i][mm.second]=max(vv[i][mm.second],mm.first);
        }
        v1.clear();
        v2.clear();
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }*/
    int dp[303][3003];
    for(int j=0;j<302;j++){
    for(int i=0;i<3003;i++)
        dp[j][i]=0;
    }
    int maxi=0;
    queue<int> qt;
   
    queue<int> qj;
    qt.push(0);
    qj.push(0);
    while(!qj.empty())
    {
        int topj=qj.front();
        qj.pop();
        int topt=qt.front();
        qt.pop();
        if(topt==n+1)
            continue;
        for(int ii=0;ii<=10;ii++)
        {
            if((topj+ii)<=k)
            {
                if(dp[topt+1][topj+ii]<dp[topt][topj]+vv[topt][ii])
                {
                    dp[topt+1][topj+ii]=dp[topt][topj]+vv[topt][ii];
                    qt.push(topt+1);
                    qj.push(topj+ii);
                }
            }
        }
    }
    for(int ii=0;ii<=300;ii++){
    for(int i=0;i<3003;i++)
        maxi=max(maxi,dp[ii][i]);
    }
    cout<<maxi<<endl;
    return 0;
}