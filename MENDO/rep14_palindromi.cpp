#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=2;i<=k;i++)
    {
        int p=i;
        string s1="",s2="";
        while(p)
        {
            s1+=(p%10)-'0';
            p/=10;
        }
        s2=s1;
        reverse(s2.begin(),s2.end());
        if(s1==s2)
            v.push_back(i);
    }
    sort(v.begin(),v.end());
    vector<int> dp(99999+2,99999999);
    dp[n]=0;
 
    for(int i=n;i<=k;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i+v[j]>k||v[j]>=i)
                break;
            if(dp[i+v[j]]>(dp[i]+1))
                dp[i+v[j]]=(dp[i]+1);
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}