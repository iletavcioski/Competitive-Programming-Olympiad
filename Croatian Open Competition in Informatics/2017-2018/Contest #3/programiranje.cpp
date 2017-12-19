#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;
int dp[100005][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    string ss;
    cin>>ss;
    for(int i=0;i<ss.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(j!=(ss[i]-'a'))
                dp[i+1][j]=dp[i][j];
        }
        dp[i+1][ss[i]-'a']=dp[i][ss[i]-'a']+1;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        bool cc=true;
        for(int j=0;j<26;j++)
        {
            if((dp[d][j]-dp[c-1][j])!=(dp[b][j]-dp[a-1][j]))
            {
                cc=false;
                break;
            }
        }
        if(cc)
            cout<<"DA"<<endl;
        else
            cout<<"NE"<<endl;
    }
    return 0;
}