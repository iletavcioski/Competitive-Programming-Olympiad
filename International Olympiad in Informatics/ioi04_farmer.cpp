#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    
    int q,n,m;
    cin>>q>>n>>m;
    vector<int> v1,v2;
    int brojac=0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v1.push_back(a);
        brojac += a;
    }
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    vector<int> dp(q+1,-1);
    dp[0]=0;
    int maxi=0;
    for(int j=0;j<v1.size();j++)
    {
        for(int i=q;i>=0;i--)
        {
            if(dp[i]!=-1&&i+v1[j]<=q)
            {
                dp[i+v1[j]]=max(dp[i+v1[j]],dp[i]+v1[j]);
            }
        }
    }
    for(int i=q;i>=0;i--) {
        if (dp[i] != -1) {
            maxi = i;
            break;
        }
    }
    if(brojac>=q)
    {
        cout<<max(maxi,q-1)<<endl;
        return 0;
    }
    int kraj=maxi;
    for(int i=0;i<v2.size();i++)
    {
        int a=q-maxi,b=v2[i];
        if(a<b)
        {
            maxi+=a;
            kraj+=a-1;
        }
        else {
            maxi += b;
            kraj += b - 1;
        }
        if(maxi==q)
        {
            cout<<kraj<<endl;
            return 0;
        }
    }
    cout<<maxi<<endl;
    return 0;
}