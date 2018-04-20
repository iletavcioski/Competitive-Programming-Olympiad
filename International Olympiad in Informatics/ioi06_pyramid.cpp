#include <iostream>
#include <deque>
using namespace std;
int n,m,a,b,c,d;
int s[1005][1005];
int x[1005][1005];
int y[1005][1005];
int xo[1005][1005];
int yox[1005][1005];
int yoy[1005][1005];
int f1(int p, int q)
{
    return s[p+a+2-1][q+b+2-1]-s[p+a+2-1][q-1]-s[p-1][q+b+2-1]+s[p-1][q-1];
}
int f2(int p, int q)
{
    return s[p+c-1][q+d-1]-s[p+c-1][q-1]-s[p-1][q+d-1]+s[p-1][q-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>m>>n>>b>>a>>d>>c;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>s[i][j];
            s[i][j]+=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
        }
    }
    a-=2;
    b-=2;
    for(int i=1;i+c-1<=n;i++) 
    {
        deque<int> dq,p;
        for(int j=1;j+d-1<=m;j++) 
        {
            int piv=f2(i,j);
            if(!p.empty()&&p.front()==j-b+d-1)
            {
                dq.pop_front();
                p.pop_front();
            }
            while(!dq.empty()&&dq.back()>piv)
            {
                dq.pop_back();
                p.pop_back();
            }
            dq.push_back(piv);
            p.push_back(j);
            if(j>b-d)
            {
                x[i][j-b+d]=dq.front();
                xo[i][j-b+d]=p.front();
            }
        }
    }
    for(int i=1;i<m-b+d;i++) 
    {
        deque<int> dq,p;
        for(int j=1;j+c-1<=n;j++) 
        {
            int piv=x[j][i];
            if(!p.empty()&&p.front()==j-a+c-1)
            {
                dq.pop_front();
                p.pop_front();
            }
            while(!dq.empty()&&dq.back()>piv) 
            {
                dq.pop_back();
                p.pop_back();
            }
            dq.push_back(piv);
            p.push_back(j);
            if(j>a-c)
            {
                y[j-a+c][i]=dq.front();
                yox[j-a+c][i]=p.front();
                yoy[j-a+c][i]=xo[p.front()][i];
            }
        }
    }
    int r1=-1e9;
    int r1p=0;
    int r1q=0;
    for(int i=2;i<=n-a;i++) 
    {
        for(int j=2;j<=m-b;j++) 
        {
            if(r1<(f1(i-1,j-1)-y[i][j]))
            {
                r1=f1(i-1,j-1)-y[i][j];
                r1p=i,r1q=j;
            }
        }
    }
    cout<<r1q-1<<" "<<r1p-1<<endl;
    cout<<yoy[r1p][r1q]<<" "<<yox[r1p][r1q]<<endl;
    return 0;
}