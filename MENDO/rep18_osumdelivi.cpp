#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll dp[2][10][10];
ll dp2[2][10];
int mat[10][10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin>>n;
    vector<vector<pair<int,int> > > v;
    vector<pair<int,int> > vec;
    v.insert(v.begin(),10,vec);
    vector<int> br;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                int a=i*100+j*10+k;
                if(a%8==0)
                {
                    if(!mat[i][j][k])
                        v[k].push_back(make_pair(i,j));
                    mat[i][j][k]=true;
                }
 
            }
        }
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        int a;
        a=s[i]-'0';
        br.push_back(a);
    }
    ll brojac=0;
    if(br[0]%8==0||br[0]==8)
    {
        brojac++;
    }
    int a=0,b=1;
    brojac%=mod;
    dp2[0][br[0]]=1LL;
    vector<ll> vi(10,0);
    vi[br[0]]++;
    brojac%=mod;
    for(int i=1;i<n;i++)
    {
        vector<int> viss(100,0);
        swap(a,b);
        bool cc;
        for(int j=0;j<v[br[i]].size();j++)
        {
            brojac+=dp[b][v[br[i]][j].first][v[br[i]][j].second];
            brojac%=mod;
        }
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(!viss[j*10+k])
                {
                    dp[a][j][k]=0;
                    dp[a][j][k]+=dp[b][j][k];
                    dp[a][j][k]%=mod;
                    viss[j*10+k]=true;
                }
            }
        }
        for(int j=0;j<10;j++)
        {
            dp[a][j][br[i]]+=dp2[b][j];
            dp[a][j][br[i]]%=mod;
 
        }
        for(int j=0;j<10;j++)
        {
            dp2[a][j]=0;
            dp2[a][j]+=dp2[b][j];
            dp2[a][j]%=mod;
        }
        for(int j=0;j<10;j++)
        {
            dp2[a][br[i]]+=dp2[b][j],dp2[a][br[i]]%=mod;
        }
        dp2[a][br[i]]++;
        dp2[a][br[i]]%=mod;
        for(int j=0;j<10;j++)
        {
            if((j*10+br[i])%8==0)
            {
                brojac+=vi[j], brojac%=mod;
            }
        }
        if(br[i]==8||br[i]==0)
        {
            brojac++,brojac%=mod;
        }
        vi[br[i]]++;
    }
    cout<<brojac<<endl;
    return 0;
}