#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int dp[2][(1<<(2*n))];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<(1<<(2*n));j++)
            dp[i][j]=1000000;
    }
    int bitmask=0;
    int brojac=0;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        brojac+=a;
        int b;
        cin>>b;
        for(int j=0;j<b;j++)
        {
            int aa;
            cin>>aa;
            aa--;
            if((bitmask&(1<<aa))==0)
                bitmask|=(1<<aa);
            else
            {
                if((bitmask&(1<<(n+aa)))==0)
                    bitmask|=(1<<(n+aa));
            }
        }
    }
    vector<vector<int> > v;
    vector<int> vec;
    v.insert(v.begin(),303,vec);
    vector<int> c;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int b;
        cin>>b;
        c.push_back(b);
        int bb;
        cin>>bb;
        for(int j=0;j<bb;j++)
        {
            int a;
            cin>>a;
            a--;
            v[i].push_back(a);
        }
    }
    int broj=0;
    dp[0][bitmask]=brojac;
    for(int i=0;i<k;i++)
    {
        int sled=(broj+1)%2;
        for(int j=0;j<(1<<(2*n));j++)
        {
            int bit=j;
            dp[sled][bit]=min(dp[sled][bit],dp[broj][bit]);
            for(int l=0;l<v[i].size();l++)
            {
                if((bit&(1<<v[i][l]))==0)
                    bit|=(1<<v[i][l]);
                else
                {
                    if((bit&(1<<(n+v[i][l])))==0)
                        bit|=(1<<(n+v[i][l]));
                }
            }
            dp[sled][bit]=min(dp[sled][bit],dp[broj][j]+c[i]);
        }
        broj=(broj+1)%2;
    }
    cout<<dp[broj][(1<<(2*n))-1]<<endl;
    return 0;
}