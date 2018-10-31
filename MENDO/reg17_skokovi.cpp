#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v1,v2;
    int n;
    cin>>n;
    vector<vector<int> > v;
    vector<int> vec;
    vector<int> dp(1000,0);
    v.insert(v.begin(),91,vec);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        dp[a]++;
        v1.push_back(a);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    sort(v2.begin(),v2.end());
    int r,k;
    cin>>r>>k;
    if(k==1)
    {
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            int brojac=0;
            for(int j=1;j<=r;j++)
            {
                brojac+=dp[v2[i]-j];
                brojac+=dp[v2[i]+j];
            }
            brojac+=dp[v2[i]];
            maxi=max(maxi,brojac);
        }
        cout<<maxi<<endl;
        return 0;
    }
    if(k==m)
    {
        int brojac=0;
        for(int i=0;i<v1.size();i++)
        {
            if(abs(v2[0]-v1[i])<=r&&abs(v2[m-1]-v1[i])<=r)
                brojac++;
        }
        cout<<brojac<<endl;
        return 0;
    }
    int i=0;
    int j=i+k-1;
    int brojac=0;
    int maxi=0;
    while(j<m)
    {
        brojac=0;
        vector<bool> visi(n+1,false);
        int raz=v2[j]-v2[i];
            int mm=r-raz;
            if(mm>=0)
            {
     
        for(int ii=1;ii<=mm;ii++)
        {
            brojac+=dp[v2[i]-ii];
            brojac+=dp[v2[j]+ii];
        }
     
        for(int ii=0;ii<=raz;ii++)
        brojac+=dp[v2[i]+ii];
            }
     
        maxi=max(maxi,brojac);
        i++;
        j++;
    }
    cout<<maxi<<endl;
    return 0;
}