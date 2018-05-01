#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    ss='#'+ss;
    int brojac=0;
    vector<int> dp((int)ss.size()+1,0);
    for(int i=1;i<ss.size();i++)
    {
        if(ss[i]==ss[i-1])
            dp[i]=1;
        if(ss[i]==ss[i-2*dp[i-1]-1])
            dp[i]=max(dp[i],dp[i-1]+1);
        if(dp[i]==2*dp[i-dp[i]])
            brojac=max(brojac,2*dp[i]);
    }
    cout<<brojac<<endl;
    return 0;
}