#include<iostream>
#include<string>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    int dp[252];
    for(int i=0;i<251;i++)
        dp[i]=0;
    dp[0]=1;
    dp[1]=1;
    if((ss[0]=='1'&&ss[1]>='0'&&ss[1]<='9')||(ss[0]=='2'&&ss[1]>='0'&&ss[1]<='6'))
    {
        dp[1]++;
    }
    if(ss[1]=='0')
        dp[1]=1;
    for(int i=1;i<ss.size();i++)
    {
        if(ss[i+1]!='0')
        dp[i+1]+=dp[i];
        if((ss[i]=='1'&&ss[i+1]>='0'&&ss[i+1]<='9')||(ss[i]=='2'&&ss[i+1]>='0'&&ss[i+1]<='6'))
        {
            dp[i+1]+=dp[i-1];
        }
 
    }
    cout<<dp[ss.size()-1]<<endl;
    return 0;
}