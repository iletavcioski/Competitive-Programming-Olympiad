#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N,M,L,K,P;
vector<vector<int> > v;
int brojac=0;
int dp[10005];
void funkcija(int K,int L)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=K;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            dp[v[i][j]]++;
        }
    }
    for(int i=K;i<=N;i++)
    {
        if(i!=K)
        {
            for(int j=0;j<v[i].size();j++)
                dp[v[i][j]]++;
            for (int j=0;j<v[i-K].size();j++)
                dp[v[i-K][j]]--;
        }
        int brojce=0;
        for(int j=1;j<=L;j++)
        {
            if(dp[j]>0)
                brojce++;
        }
        if(brojce==0)
            brojac++;
        for(int j=L+1;j<=M;j++)
        {
            if(dp[j-L]>0)
                brojce--;
            if (dp[j]>0)
                brojce++;
            if(brojce==0)
            {
                brojac++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin>>N>>M>>K>>L>>P;
    vector<int> vec;
    v.insert(v.begin(),10001+1,vec);
    for(int i=0;i<P;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    funkcija(K,L);
    if(K!=L)
    {
        funkcija(L,K);
    }
    cout<<brojac<<endl;
    return 0;
}