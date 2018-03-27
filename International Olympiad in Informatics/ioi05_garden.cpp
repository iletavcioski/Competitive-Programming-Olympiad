#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m,t,k;
int dp[252][252];
int x[252][252];
int y[252][252];
int p[252],q[252],r[252],s[252];
int f(int p,int q,int r,int s)
{
    return dp[r][s]-dp[p-1][s]-dp[r][q-1]+dp[p-1][q-1];
}
void solve_x(int p,int q)
{
    int l=1;
    int maxi=1e9;
    for (int i=p;i>0;i--) 
	{
        while(f(i,l+1,p,q)>=k) 
			l++;
        if(f(i,l,p,q)>=k) 
			maxi=min(maxi,(q-l+p-i+2)*2);
    }
    x[p][q]=maxi;
}
void solve_y(int p,int q)
{
    int r=m;
    int maxi=1e9;
    for(int i=p;i<=n;i++) 
	{
        while(f(p,q,i,r-1)>=k) 
			r--;
        if(f(p,q,i,r)>=k) 
			maxi=min(maxi,(r-q+i-p+2)*2);
    }
    y[p][q]=maxi;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>t>>k;
	for(int i=0;i<=250;i++)
	{
		p[i]=1e9,q[i]=1e9,r[i]=1e9,s[i]=1e9;
		for(int j=0;j<=250;j++)
		{
			x[i][j]=1e9;
			y[i][j]=1e9;
		}
	}
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		dp[a][b]++;
	}
	for(int i=1;i<=n;i++) 
	{
        for(int j=1;j<=m;j++) 
		{
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			solve_x(i,j);
			solve_y(i,j);
		}
	}
	for(int i=1;i<=n;i++) 
	{
        p[i]=*min_element(x[i]+1,x[i]+m+1);
        q[i]=*min_element(y[i]+1,y[i]+m+1);
        for(int j=1;j<=m;j++) 
		{
            r[j]=min(r[j],x[i][j]);
            s[j]=min(s[j],y[i][j]);
        }
    }
	for(int i=2;i<=n;i++) 
	{
        p[i]=min(p[i],p[i-1]);
    }
    for(int i=n-1;i>0;i--) 
	{
        q[i]=min(q[i],q[i+1]);
    }
    for(int i=2;i<=m;i++) 
	{
        r[i]=min(r[i],r[i-1]);
    }
    for(int i=m-1;i>0;i--) 
	{
        s[i]=min(s[i],s[i+1]);
    }
    int maxi=1e9;
    for(int i=1;i<n;i++) 
	{
        maxi=min(maxi,p[i]+q[i+1]);
    }
    for(int i=1;i<m;i++) 
	{
        maxi=min(maxi,r[i]+s[i+1]);
    }
    if(maxi>=1e9)
		cout<<"NO"<<endl;
    else 
		cout<<maxi<<endl;
	return 0;
}