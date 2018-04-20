#include <iostream>
using namespace std;
int s[1505][1505];
int a[1505][1505];
int b[1505][1505];
int c[1505][1505];
int d[1505][1505];
int e[1505][1505];
int f[1505][1505];
int n,m,k;
int g[1505];
int h[1505];
int fun(int x, int y)
{
    return s[x+k-1][y+k-1]-s[x-1][y+k-1]-s[x+k-1][y-1]+s[x-1][y-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>s[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    for(int i=k;i<=n;i++) 
    {
        for(int j=k;j<=m;j++) 
        {
            a[i][j]=max(a[i-1][j],a[i][j-1]);
            a[i][j]=max(a[i][j],fun(i-k+1,j-k+1));
        }
    }
    for(int i=k;i<=n;i++)
    {
        for(int j=m-k+1;j>0;j--) 
        {
            b[i][j]=max(b[i-1][j],b[i][j+1]);
            b[i][j]=max(b[i][j],fun(i-k+1,j));
        }
    }
    for(int i=n-k+1;i>0;i--) 
    {
        for(int j=k;j+k-1<=m;j++) 
        {
            c[i][j]=max(c[i+1][j],c[i][j-1]);
            c[i][j]=max(c[i][j],fun(i,j-k+1));
        }
    }
    for(int i=n-k+1;i>0;i--) 
    {
        for(int j=m-k+1;j>0;j--) 
        {
            d[i][j]=max(d[i+1][j],d[i][j+1]);
            d[i][j]=max(d[i][j],fun(i,j));
        }
    }
    for(int i=k;i<=n;i++) 
    {
        for(int j=1;j+k-1<=m;j++) 
        {
            g[i]=max(g[i],fun(i-k+1,j));
        }
    }
    for (int i=k;i<=m;i++) 
    {
        for(int j=1;j+k-1<=n;j++) 
        {
            h[i]=max(h[i],fun(j,i-k+1));
        }
    }
    for(int i=1;i<=n;i++) 
    {
        for(int j=i+k-1;j<=n;j++) 
        {
            e[i][j]=max(e[i][j-1],g[j]);
        }
    }
    for(int i=1;i<=m;i++) 
    {
        for (int j=i+k-1;j<=m;j++) 
        {
            f[i][j]=max(f[i][j-1],h[j]);
        }
    }
    int res=0;
    for(int i=k;i+k<=n;i++) 
    {
        for (int j=i+k;j+k<=n;j++) 
        {
            res=max(res,e[1][i]+e[i+1][j]+e[j+1][n]);
        }
    }
    for(int i=k;i+k<=m;i++) 
    {
        for(int j=i+k;j+k<=m;j++) 
        {
            res=max(res,f[1][i]+f[i+1][j]+f[j+1][m]);
        }
    }
    for(int i=k;i+k<=n;i++) 
    {
        for(int j=k;j+k<=m;j++) 
        {
            res=max(res,e[1][i]+c[i+1][j]+d[i+1][j+1]);
        }
    }
    for(int i=k;i+k<=n;i++) 
    {
        for(int j=k;j+k<=m;j++) 
        {
            res=max(res,e[i+1][n]+a[i][j]+b[i][j+1]);
        }
    }
    for(int i=k;i+k<=m;i++) 
    {
        for(int j=k;j+k<=n;j++)
        {
            res=max(res,f[1][i]+b[j][i+1]+d[j+1][i+1]);
        }
    }
    for(int i=k;i+k<=m;i++)
    {
        for(int j=k;j+k<=n;j++) 
        {
            res=max(res,f[i+1][m]+a[j][i]+c[j+1][i]);
        }
    }
    cout<<res<<endl;
    return 0;
}