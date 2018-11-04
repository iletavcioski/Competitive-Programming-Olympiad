#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=50;
bool mat[55][55];
bool ncmat[55][55];
int v[55];
bool dfs(int x,int cel,int n)
{
    if(x==cel)
		return false;
    if(v[x])
	{
        return (v[x]==1);
    }
    v[x]=(cel==n?2:1);
    bool res=false;
    for(int i=0;i<N;i++)
	{
		if(mat[x][i]) 
			res|=dfs(i,cel,n);
	}
    return res;
}
int main()
{
    for(int i=0;i<N;i++)
	{
        for(int j=0;j<N;j++)
		{
            mat[i][j]=false;
            ncmat[i][j]=false;
        }
	}
    int t,n=0;
    cin>>t;
    while(t!=-1)
	{
        if(n!=t) 
			mat[n][t]=1;
        cin>>t;
        if(t==-2)
		{
            n++;
            cin>>t;
        }
    }
    n++; 
    for(int i=0;i<N;i++)
	{
        for(int j=0;j<N;j++)
		{
            ncmat[i][j]=mat[i][j];
		}
	}
	vector<int> unavoidable;
    queue<int> qi;
    int u[101];
    memset(u,0,sizeof(u));
    qi.push(0);
    int cc=0;
    while(!qi.empty())
	{
        int topi=qi.front();
        qi.pop();
        if(u[topi]) 
			continue;
        u[topi]=true;
        for(int i=0;i<N;i++)
		{
            if(!u[i]&&ncmat[i][topi]) 
				ncmat[i][topi]=0;
            cc-=ncmat[i][topi];
        }
        if(!cc&&topi&&topi<n-1)
		{
            unavoidable.push_back(topi);
            cc=0;
        }
        for(int i=0;i<N;i++)
		{
            if(ncmat[topi][i])
			{
                cc++;
                qi.push(i);
            }
        }
    }
    vector<int> split;
    for(int i=0;i<unavoidable.size();i++)
	{
        memset(v,0,sizeof(v));
        dfs(0,unavoidable[i],n-1);
        if(!dfs(unavoidable[i],n-1,n-1)) 
			split.push_back(unavoidable[i]);
    }
    cout<<unavoidable.size();
    for(int i=0;i<unavoidable.size();i++) 
		cout<<" "<<unavoidable[i];
    cout<<endl;
	cout<<split.size();
    for(int i=0;i<split.size();i++) 
		cout<<" "<<split[i];
    cout<<endl;
    return 0;
}