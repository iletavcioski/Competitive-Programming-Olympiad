#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    static int dp[303][303];
    static int dp1[303][303];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=1e9;
            dp1[i][j]=-1;
        }
    }
    
    static int dist[303][303];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            dist[i][j]=0;
            for(int k=i;k<=j;k++)
                dist[i][j]+=min(abs(v[k]-v[i]),abs(v[j]-v[k]));
        }
    }
    for(int i=0;i<n;i++)
    {
        dist[i][n]=0;
        for(int j=i;j<n;j++)
        {
            dist[i][n]+=abs(v[j]-v[i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[i][1]=0;
        for(int j=0;j<=i;j++)
        {
            dp[i][1]+=abs(v[j]-v[i]);
        }
        dp1[i][1]=-1;
    }
    for(int j=2;j<=k;j++)
    {
        for(int i=0;i<n;i++)
        {
            dp1[i][j]=-1;
            int brojac=0;
            int maxi=1e9;
            int maxxi2=-1;
            int koe=-1;
            for(int ii=i-1;ii>=0;ii--)
            {
                if(maxi>dp[ii][j-1]+dist[ii][i])
                {
                    maxi=dp[ii][j-1]+dist[ii][i];
                koe=ii;
                }
                else if(maxi==dp[ii][j-1]+dist[ii][j])
                {
                    koe=min(koe,ii);
                }
            }
            if(maxi==1e9)
            {
                dp[i][j]+=0;
                dp1[i][j]=-1;
            }
            else
            {
            dp[i][j]=maxi;
            dp1[i][j]=koe;
            }
        }
    }
    int maxi=1e9;
    int index1=-1,index2=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]+=dist[i][n];
            if(maxi>dp[i][j])
            {
                maxi=dp[i][j];
                index1=i;
                index2=j;
            }
        }
    }

    cout<<maxi<<endl;
    vector<int> vkraj;
    while(index1!=-1&&index2!=0)
    {
        vkraj.push_back(index1);
        index1=dp1[index1][index2];
        index2--;
    }
    sort(vkraj.begin(),vkraj.end());
    for(int i=0;i<vkraj.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<v[vkraj[i]];
    }
    cout<<endl;
    return 0;
}