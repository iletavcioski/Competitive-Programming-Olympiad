#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<bool> broevi(10,0);
    string ss;
    cin>>ss;
    for(int i=0;i<ss.size();i++)
        broevi[(ss[i]-'0')]=true;
    vector<int> dp(5005,9999);
    vector<int> v;
    for(int i=0;i<=5000;i++)
    {
        if(i==0)
        {
            if(broevi[0])
            {
                v.push_back(0);
                dp[0]=min(dp[0],1);
            }
        }
        else
        {
            int brojki=0;
            int p=i;
            bool cc=true;
            while(p)
            {
                if(!broevi[p%10])
                {
                    cc=false;
                    break;
                }
                else
                {
                    brojki++;
                    p/=10;
                }
            }
            if(cc)
            {
                if(i>=5000)
                {
                    if(dp[5000]>4)
                    {
                        dp[5000]=4;
                        v.push_back(5000);
                    }
                }
                else
                {
                v.push_back(i);
                dp[i]=min(dp[i],brojki);
                }
            }
        }
    }
 
 
    for(int j=0;j<=5000;j++)
        {
            for(int i=0;i<=5000;i++)
           {
                if((dp[j]+1+dp[i])<dp[min((j*i),5000)])
                {
                    dp[min((j*i),5000)]=(dp[j]+1+dp[i]);
                }
          }
        }
     
        for(int j=0;j<=5000;j++)
        {
            for(int i=0;i<=5000;i++)
           {
                if((dp[j]+1+dp[i])<dp[min((j+i),5000)])
                {
                    dp[min((j+i),5000)]=(dp[j]+1+dp[i]);
                }
          }
        }
    int n;
    cin>>n;
    cout<<dp[n]<<endl; 
    return 0;
}