#include <vector>
#include <string>
using namespace std;
int n,k;
bool dpl[200005][105];
bool dpr[200005][105];
int psum[200005];
int black[200005];
int white[200005];
bool has_white(int a,int b)
{
    return psum[b]!=psum[a-1];
}
string solve_puzzle(string s,vector<int> c)
{
    int n=s.size();
    int k=c.size();
    s='#'+s;
    s+='_';
    n++;
    for(int i=1;i<=n;i++)
    {
        psum[i]=psum[i-1]+(s[i]=='_');
    }
    dpl[0][0]=1;
    for(int j=0;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='X')
                continue;
            dpl[i][j]=dpl[i-1][j];
            if(j>0)
            {
                if(i>=c[j-1]+1&&!has_white(i-c[j-1],i-1))
                {
                    dpl[i][j]=max(dpl[i][j],dpl[i-c[j-1]-1][j-1]);
                }
            }
        }
    }
    dpr[n+1][k]=1;
    for(int j=k;j>=0;j--)
    {
        for(int i=n;i>0;i--)
        {
            if(s[i]!='X')
                dpr[i][j]=dpr[i+1][j];
            if(j<k)
            {
                if(i+c[j]<=n&&!has_white(i,i+c[j]-1)&&s[i+c[j]]!='X')
                {
                    dpr[i][j]=max(dpr[i][j],dpr[i+c[j]+1][j+1]);
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(dpl[i][j]&&dpr[i+1][j]&&s[i]!='X')
            {
                white[i]=1;
            }
        }
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i<=n-c[j-1]-1;i++)
        {
            if(dpl[i][j-1]&&dpr[i+c[j-1]+2][j]&&!has_white(i+1,i+c[j-1])&&s[i]!='X'&&s[i+c[j-1]+1]!='X')
            {
                black[i+1]++;
                black[i+c[j-1]+1]--;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        black[i]+=black[i-1];
    }
    string res="";
    for(int i=1;i<n;i++)
    {
        if(s[i]=='_'||s[i]=='X')
            res+=s[i];
        else if(white[i]&&black[i])
            res+='?';
        else if(white[i])
            res+='_';
        else
            res+='X';
    }
    return res;
}