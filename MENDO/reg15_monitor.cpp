#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<int> mat1(n+3,0);
    vector<int> mat2(m+3,0);
    vector<int> dp1(n+3,0);
    vector<int> dp2(m+3,0);
    int kk;
    cin>>kk;
    for(int i=0;i<kk;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int cc;
        cin>>cc;
        if(cc==1)
        {
            mat2[a]=true;
        }
        else
        {
            mat1[b]=true;
        }
    }
    dp1[0]=0;
    dp2[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp2[i]=dp2[i-1];
        if(mat2[i-1])
        {
            dp2[i]++;
        }
    }
 
    for(int i=1;i<=m;i++)
    {
        dp1[i]=dp1[i-1];
        if(mat1[i-1])
        {
            dp1[i]++;
        }
    }
 
    int maxi=999999;
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=1;j<=m-k+1;j++)
        {
            maxi=min(maxi,(dp2[i+k-1]-dp2[i-1])+(dp1[j+k-1]-dp1[j-1]));
        }
    }
 
 
    cout<<maxi<<endl;
    return 0;
}