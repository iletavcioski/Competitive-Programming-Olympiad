#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<ll> k,w;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        w.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        k.push_back(a);
    }
    static ll dp[1001][1001];
    static ll poc[1001][1001];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
        poc[i][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int e=(j+i+n)%n;
            int vtor=(j+1+n)%n;
            poc[j][e]=max(poc[vtor][e]+k[j]-w[j],(ll)0);
            dp[j][e]=dp[vtor][e]+poc[vtor][e]+k[j];
        }
    }
    for(int qq=0;qq<q;qq++)
    {
        int a,b;
        cin>>a>>b;
        if(poc[a][b])
            cout<<-1<<endl;
        else
            cout<<dp[a][b]<<endl;
    }
    return 0;
}