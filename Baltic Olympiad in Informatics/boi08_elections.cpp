#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int brojac=0;
    vector<pair<int,int > > v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        brojac+=a;
        v.push_back(make_pair(a,i+1));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<int> dp(brojac+3,-1);
    dp[0]=-2;
    brojac/=2;
    brojac++;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=brojac-1;j>=0;j--)
        {
            if(dp[j]!=-1&&dp[j+v[i].first]==-1)
            {
                dp[j+v[i].first]=i;
                maxi=max(maxi,j+v[i].first);
            }
        }
    }
    int y=maxi;
    vector<int> vkraj;
    while(y!=0)
    {
        vkraj.push_back(v[dp[y]].second);
        y=y-v[dp[y]].first;
    }
    cout<<vkraj.size()<<endl;
    sort(vkraj.begin(),vkraj.end());
    for(int i=0;i<vkraj.size();i++)
    {
        if(i)
            cout<<" ";
        cout<<vkraj[i];
    }
    cout<<endl;
    return 0;
}